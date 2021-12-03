#include "Traffic.h"

Traffic::Traffic(User user, bool isContinue) {
	character = new Character();

	isSave = false;	
	isLoad = isContinue;
	result = "LOSE";

	this->user = user;
}

Traffic::~Traffic() {
	delete character;
}

void Traffic::saveUser() {
	string pathFile = UIHelper::getUIHelper()->getFilePath() + "InfoContinue" + user.getName();
	ofstream g(pathFile);
	g << user.getName() << endl << user.getLevel() << endl << user.getScore();
	g.close();
}

void Traffic::carInLane(int lane) {
	switch (lane)
	{
	case 1:
		truckCarProcess(lane);
		break;
	case 2:
		chickenProcess(lane);
		break;
	case 3:
		fastAFCarProcess(lane);
		break;
	case 4:
		redCarProcess(lane);
		break;
	case 5:
		int choice = (rand() % 100) % 4;
		switch (choice)
		{
		case 0:
			truckCarProcess(lane);
			break;
		case 1:
			chickenProcess(lane);
			break;
		case 2:
			fastAFCarProcess(lane);
			break;
		case 3:
			redCarProcess(lane);
			break;
		}
		break;
	}
}

void Traffic::truckCarProcess(int lane) {
	UIHelper* helper = UIHelper::getUIHelper();
	ListTrucks listTrucks(lane, lane%2, user.getLevel());
	listTrucks.setDirection(lane % 2);
	
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

	int count = 1;
	while (!isExit) {
		if (isStop) continue;
		
		m.lock();

		if (!listTrucks.getRedLight()) {
			helper->setTextColor(helper->default_ColorCode);
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
			isSave = false; isExit = true;
			result = "LOSE";
			m.unlock();
			break;
		}
		m.unlock();
		Sleep(listTrucks.getSpeed());
	}


	if (!listTrucks.isCollision(character)) {
		m.lock();

		listTrucks.deleteListCar();
		m.unlock();
	}
	
	if (isSave) listTrucks.saveCar(pathFile);
}

void Traffic::fastAFCarProcess(int lane) {
	UIHelper* helper = UIHelper::getUIHelper();
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
			remove(pathFile.c_str());
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

		helper->setTextColor(helper->default_ColorCode);
		fastAF.updateListCar();

		if (fastAF.isCollision(character)) {
			isSave = false; isExit = true;
			result = "LOSE";
			m.unlock();
			break;
		}
		count++;

		m.unlock();
		Sleep(fastAF.getSleepTime());
	}
	
	if (!fastAF.isCollision(character)) {
		m.lock();
		character->drawCharacter();
		fastAF.deleteEverything();
		m.unlock();
	} 
	if (isSave) fastAF.saveCar(pathFile);
}

void Traffic::redCarProcess(int lane) {
	UIHelper* helper = UIHelper::getUIHelper();
	ListRedCar redCars;
	string pathFile = UIHelper::getUIHelper()->getFilePath() + "RedCar" + user.getName() + to_string(lane);

	redCars.setLane(lane);
	redCars.setLevel(user.getLevel());
	redCars.setDirection(lane % 2);

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

		if (redCars.getRedLight() == 0) {
			helper->setTextColor(helper->default_ColorCode);
			redCars.updateListCar();
		} 

		
		if (redCars.isCollision(character)) {
			isSave = false; isExit =  true;
			result = "LOSE";
			m.unlock();
			break;
		}
		m.unlock();
		
		Sleep(redCars.getSleep());
	}
	
	if (!redCars.isCollision(character)) {
		m.lock();
		character->drawCharacter();
		redCars.deleteListCar();
		m.unlock();
	}	

	if (isSave) redCars.saveCar(pathFile);
}

void Traffic::chickenProcess(int lane) {
	UIHelper* helper = UIHelper::getUIHelper();
	ListChickens listChicks(lane, user.getLevel());
	listChicks.setLevel(user.getLevel());
	string pathFile = UIHelper::getUIHelper()->getFilePath() + "Chickens" + user.getName() + to_string(lane);

	listChicks.setDirection(!(lane % 2));
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
			helper->setTextColor(helper->default_ColorCode);
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
			isSave = false; isExit = true;
			result = "LOSE";
			m.unlock();
			break;
		}

		listChicks.updateListCar();

		m.unlock();
		listChicks.addTimeDelay();
	}

	
	if (!listChicks.isCollision(character)) {
		m.lock();
		character->drawCharacter();
		listChicks.deleteListCar();
		m.unlock();
	}

	if (isSave) listChicks.saveToFile(pathFile);	
}

string Traffic::startTraffic() {
	
	isExit = isStop = false;

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

	return result;
}

void Traffic::stopTraffic() {
	isStop = true;
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
			isStop = isExit = true;
			if (!result.empty() && result != "LOSE") result = "RESTART";
			return;
		}

		//Save Game or Exit
		if (k == 27) {
			isStop = true;
			Sleep(1000);

			
			vector<string> menu{"Save Game and Exit", "Exit"};
			int key = helper->createMenu(105, 23, menu);

			//Todo:  Save Game, exit;
			if (key == 0) {
				isSave = true;
				saveUser();
			} 

			result = "EXIT";
			isExit = true;
			return;
		}

		//Todo: Win update, score
		if (character->getY() <= 4) {
			isStop = isExit = true;
			result = "WIN";
			return;
		}
	}
}