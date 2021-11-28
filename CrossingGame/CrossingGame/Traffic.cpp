#include "Traffic.h"


Traffic::Traffic(User user, int pos, int gameMode) {
	character = new Character();

	isStop = false;
	isExit = false;
	isWin = false;
	isSave = false;
	isLoad = gameMode;

	this->user = user;
	this->accountPos = pos;

	loadUser(true);
}

Traffic::~Traffic() {
	delete character;
}

void Traffic::loadUser(bool isShow) {
	string pathFile = UIHelper::getUIHelper()->getFilePath() + "InfoContinue" + user.getName();
	if (isLoad) {
		ifstream f(pathFile);

		if (f.good()) {
			string name; int a, b;
			getline(f, name);
			f >> a >> b;
			user.setName(name);
			user.setLevel(a);
			user.setScore(b);

			if (isShow) showUserInfo();
			f.close();
			remove(pathFile.c_str());
			return;
		}
	}
	user.setLevel(1);
	user.setScore(0);
	if (isShow) showUserInfo();
}

void Traffic::saveUser() {
	string pathFile = UIHelper::getUIHelper()->getFilePath() + "InfoContinue" + user.getName();
	ofstream g(pathFile);
	g << user.getName() << endl << user.getLevel() << endl << user.getScore();
	g.close();
}

void Traffic::showUserInfo() {
	UIHelper* console = UIHelper::getUIHelper();
	console->setTextColor(240);
	console->gotoXY(109, 3);
	for (int i = 0; i < 24; i++) {
		console->gotoXY(109 + i, 3); cout << " ";
	}

	for (int i = 0; i < 8; i++) {
		console->gotoXY(117 + i, 5); cout << " ";
		console->gotoXY(117 + i, 7); cout << " ";
	}

	//output word
	console->gotoXY(109, 3); // name spot
	cout << user.getName();
	console->gotoXY(109, 5); // score spot
	cout << "Score:";
	console->gotoXY(109, 7); // level spot
	cout << "Level:";
	console->gotoXY(117, 5); // score spot
	if (user.getScore() >= 0) cout << user.getScore(); else cout << "?";
	console->gotoXY(117, 7); // level spot
	if (user.getLevel() > 0) cout << user.getLevel(); else cout << "?";
}


void Traffic::carInLane(int lane) {
	//redCarProcess(lane);

	//truckCarProcess(lane);

	//fastAFCarProcess(lane);

	chickenProcess(lane);
	/*if (lane % 2 == 0) fastAFCarProcess(lane);
	else */
}

void Traffic::truckCarProcess(int lane) {
	ListTrucks listTrucks(lane, 0, user.getLevel());

	string pathFile = UIHelper::getUIHelper()->getFilePath() + "Truck" + user.getName() + to_string(lane);
	//Draw Traffic Color
	m.lock();
	listTrucks.trafficColor();
	if (isLoad) {
		ifstream f(pathFile);
		if (f.good()) {
			listTrucks.loadCar(pathFile);
			f.close();
			remove(pathFile.c_str());
		}
	}
	m.unlock();

	int count = 1; isWin = true;
	while (!isExit) {
		if (isStop) continue;
		
		m.lock();

		if (!listTrucks.getRedLight()) {
			listTrucks.deleteListCar();
			listTrucks.drawListCar();
		}
		
		if (count == listTrucks.getTimeToRed()) {
			if (listTrucks.getRedLight()) listTrucks.setRedLight(0);
			else listTrucks.setRedLight(1);

			listTrucks.trafficColor();
			count = 1;
		}
		++count;
		listTrucks.updateListCar();
		
		
		if (listTrucks.isCollision(character)) {
			isWin = isSave = false;
			isExit = true;

			m.unlock();
			break;
		}
		m.unlock();
		Sleep(listTrucks.getSpeed());
	}

	m.lock();
	listTrucks.deleteListCar();
	if (isSave) listTrucks.saveCar(pathFile);
	
	m.unlock();
}

void Traffic::fastAFCarProcess(int lane) {
	ListFastAFCars fastAF;
	string pathFile = UIHelper::getUIHelper()->getFilePath() + "FastAFCar" + user.getName() + to_string(lane);
	fastAF.setLane(lane);
	fastAF.setLevel(user.getLevel());
	int count = 1;

	m.lock();
	fastAF.trafficColor();
	if (isLoad) {
		ifstream f(pathFile);
		if (f.good()) {
			fastAF.loadCar(pathFile);
			f.close();
			//remove(pathFile.c_str());
		}
	}
	m.unlock();

	while (!isExit) {
		if (isStop) continue;

		m.lock();
		if (count == fastAF.getTimeToRed()) {
			fastAF.setTraffic(!fastAF.getTraffic());
			fastAF.trafficColor();
			count = 0;
		}

		fastAF.updateListCar();
		if (fastAF.isCollision(character)) {
			isWin = isSave = false;
			isExit = true;

			m.unlock();
			break;
		}
		count++;

		m.unlock();
		Sleep(fastAF.getSleepTime());
	}
	m.lock();
	fastAF.deleteEverything();
	if (isSave) fastAF.saveCar(pathFile);

	m.unlock();
}

void Traffic::redCarProcess(int lane) {
	ListRedCar redCars;
	string pathFile = UIHelper::getUIHelper()->getFilePath() + "RedCar" + user.getName() + to_string(lane);

	redCars.setLane(lane);
	redCars.setLevel(user.getLevel());
	redCars.setDirection(1);

	m.lock();
	redCars.trafficColor();
	if (isLoad) {
		ifstream f(pathFile);
		if (f.good()) {
			redCars.loadCar(pathFile);
			f.close();
			remove(pathFile.c_str());
		}
	}
	m.unlock();

	int count = 0;
	while (!isExit) {
		if (isStop) continue;
		m.lock();
		if (count == redCars.getTimeRedLight()) {
			if (redCars.getRedLight()) {
				redCars.setRedLight(0);
				redCars.trafficColor();
				count = 0;
			}
			else {
				redCars.setRedLight(1);
				redCars.trafficColor();
				count = 0;
			}
		}
		++count;

		if (redCars.getRedLight() == 0) redCars.updateListCar();

		
		if (redCars.isCollision(character) == true) {
			isWin = isSave = false;
			isExit = true;

			m.unlock();
			break;
		}
		m.unlock();
		
		Sleep(redCars.getSleep());
	}

	m.lock();
	redCars.deleteListCar();
	if (isSave) redCars.saveCar(pathFile);
	m.unlock();
}

void Traffic::chickenProcess(int lane) {
	ListChickens listChicks(lane, user.getLevel());
	listChicks.setLevel(user.getLevel());
	string pathFile = UIHelper::getUIHelper()->getFilePath() + "Chickens" + user.getName() + to_string(lane);

	listChicks.setDirection(true);
	m.lock();
	listChicks.trafficColor();
	listChicks.setAddChicken();
	if (isLoad) {
		ifstream f(pathFile);
		if (f.good()) {
			listChicks.loadFromFile(pathFile);
			f.close();
			remove(pathFile.c_str());
		}
	}

	m.unlock();
	
	int count = 0;
	while (!isExit) {
		if (isStop) continue;
		m.lock();
		if (listChicks.getRedlight()) {
			listChicks.deleteListCar();
			listChicks.drawListCar();
		}
		
		if (count == listChicks.RedLight()) {
			if (listChicks.getRedlight()) {
				listChicks.setRedlight(false);
				listChicks.trafficColor();
				count = 0;
			}
			else {
				listChicks.setRedlight(true);
				listChicks.trafficColor();
				count = 0;
			}
		}

		++count;

		if (listChicks.isCollision(character)) {

			isWin = isSave = false;
			isExit = true;

			m.unlock();
			break;
		}

		listChicks.updateListCar();

		m.unlock();
		//Sleep(ListChikens.getTimeDelay());
		listChicks.addTimeDelay();
	}

	m.lock();
	listChicks.deleteListCar();
	if (isSave) listChicks.saveToFile(pathFile);

	m.unlock();

}

void Traffic::startTraffic() {
	isStop = false;
	isExit = false;

	srand(time(NULL));
	(*character).deleteCharacter();
	(*character).resetCharater(true);

	thread control(&Traffic::processCharacter, this);
	thread l1(&Traffic::carInLane, this, 1);
	thread l2(&Traffic::carInLane, this, 2);
	thread l3(&Traffic::carInLane, this, 3);
	thread l4(&Traffic::carInLane, this, 4);
	thread l5(&Traffic::carInLane, this, 5);


	l1.join();
	l2.join();
	l3.join();
	l4.join();
	l5.join();
	control.join();
}

void Traffic::stopTraffic() {
	isStop = true;
}

void Traffic::resetTraffic() {
	UIHelper* console = UIHelper::getUIHelper();
	m.lock();
	showUserInfo();
	m.unlock();

	//Stop all traffic
	isStop = true;
	isExit = true;

	Sleep(500);
	startTraffic();
}

void Traffic::processCharacter() {
	UIHelper* helper = UIHelper::getUIHelper();
	helper->getKey();
	while (!isExit) {
		
		int k = helper->getKey();
		if (!isStop) {
			if (k == helper->ArrowKey_UP || toupper(k) == 'W') {
				m.lock();
				(*character).increaseY(-1);
				m.unlock();
			}

			if (k == helper->ArrowKey_DOWN || toupper(k) == 'S') {
				m.lock();
				(*character).increaseY(1);
				m.unlock();
			}

			if (k == helper->ArrowKey_LEFT || toupper(k) == 'A') {
				m.lock();
				(*character).increaseX(-1);
				m.unlock();
			}

			if (k == helper->ArrowKey_RIGHT || toupper(k) == 'D') {
				m.lock();
				(*character).increaseX(1);
				m.unlock();
			}
		}

		if (tolower(k) == 'p') isStop = !isStop;
		
		if (tolower(k) == 'r') {
			//play again
			user.setLevel(1);
			user.setScore(0);
			this->resetTraffic();
		}

		if (k == 27) {
			isStop = true;
			Sleep(500);

			
			vector<string> menu{"Save Game and Exit", "Exit"};
			int key = helper->createMenu(105, 23, menu);
			
			Sleep(500);
			//Todo:  Save Game, exit;
			if (key == 0) {
				isSave = true;
				saveUser();
			} 

			isExit = true;
			Sleep(500);

			return;
		}

		//Todo: Win update, score
		if (character->getY() <= 4) {
			Sleep(200);
			user.increaseScore(10);
			user.increaseLevel(1);
			isWin = true;
			break;
		}
	}

	if (isWin) this->resetTraffic();
	else {
		isStop = isExit = true;
		Sleep(500);

		Account* account = Account::getInstance();
		User userOld = account->getAccount(accountPos);

		int y = 23;
		helper->gotoXY(105, y++);
		cout << "You are a loser";

		if (userOld.getScore() < user.getScore()) {
			account->updateUser(accountPos, user);
			account->saveAccountToFile();

			UIHelper* helper = UIHelper::getUIHelper();
			helper->gotoXY(105, y++);
			cout << "High Score: "<<user.getScore();
		}
		y++;
		vector<string> menu{"Exit"};
		int key = helper->createMenu(105, y++, menu);
	}
}