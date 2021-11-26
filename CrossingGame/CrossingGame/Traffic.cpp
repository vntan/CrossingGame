#include "Traffic.h"

Traffic::Traffic(User user, int pos) {
	isStop = new bool;
	isExit = new bool;
	character = new Character();

	*isStop = false;
	*isExit = false;

	this->user = user;
	this->accountPos = pos;
}

void Traffic::carInLane(int lane) {

	redCar(lane);
  if (lane % 2 == 0) fastAFCarProcess(lane);
	else truckCarProcess(lane);
}

void Traffic::redCar(int lane) {
	ListRedCar l;
	l.setLane(lane);
	l.setLevel(1);
	l.setDirection(1);

	m.lock();
	l.trafficColor();
	m.unlock();

	//l.loadCar("rcar");

	int count = 0;
	while (true) {
	if (count == l.getTimeRedLight()) {
			if (l.getRedLight()) {
				l.setRedLight(0);
				l.trafficColor();
				count = 0;
			}
			else {
				l.setRedLight(1);
				l.trafficColor();
				count = 0;
			}
		}
		++count;

		if (l.getRedLight() == 0) {
			l.updateListCar();
		}

		if (l.isCollision(character) == true) {
			//l.saveCar("rcar");
			exit(0);
		}

		m.unlock();
		Sleep(l.getSleep());
  }
	//UIHelper* helper = UIHelper::getUIHelper();
}

	
void Traffic::truckCarProcess(int lane) {

	ListTrucks listTrucks(lane, 1, 5);

	//Draw Traffic Color
	m.lock();
	listTrucks.trafficColor();
	m.unlock();

	int count = 1;
	while (!*isExit) {
		if (*isStop) {
			continue;
		}
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

		if (listTrucks.isCollision(character)) {
			listTrucks.saveCar("ListTrucks.txt");
			*isStop = true;
		}

		listTrucks.updateListCar();

		
		m.unlock();

		Sleep(listTrucks.getSpeed());
	}
}

void Traffic::fastAFCarProcess(int lane) {
	ListFastAFCars fastAF;
	fastAF.setLane(lane);
	fastAF.setLevel(4);
	int count = 1;

	m.lock();
	fastAF.trafficColor();
	m.unlock();

	while (true) {
		if (*isStop) continue;

		m.lock();
		if (count % 20 == 0) {
			fastAF.setTraffic(!fastAF.getTraffic());
			fastAF.trafficColor();
		}

		fastAF.updateListCar();
		if (fastAF.isCollision(character)) {
			fastAF.saveCar();
			exit(0);
		}
		count++;

		m.unlock();
		Sleep(fastAF.getSleepTime());
	}
}

void Traffic::startTraffic() {
	*isStop = false;
	*isExit = false;

	srand(time(NULL));
	(*character).deleteCharacter();
	(*character).resetCharater(true);

	thread control(&Traffic::processCharacter, this);
	thread l1(&Traffic::carInLane, this, 1);
	thread l2(&Traffic::carInLane, this, 2);
	thread l3(&Traffic::carInLane, this, 3);
	thread l4(&Traffic::carInLane, this, 4);
	thread l5(&Traffic::carInLane, this, 5);


	//l1.join();
	l2.join();
	l3.join();
	l4.join();
	l5.join();
	control.join();
}

void Traffic::stopTraffic() {
	*isStop = true;
}

void Traffic::resetTraffic() {
	*isStop = true;
	*isExit = true;

	Sleep(500);
	startTraffic();

}

void Traffic::processCharacter() {
	UIHelper* helper = UIHelper::getUIHelper();

	while (true) {
		
		int k = helper->getKey();
		if (!*isStop) {
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

		if (tolower(k) == 'p') *isStop = !*isStop;
		if (tolower(k) == 'r') break;
		if (k == 27) {
			*isStop = true;
			*isExit = true;

			Sleep(500);
			vector<string> menu{"Save Game", "Exit"};
			int key = helper->createMenu(105, 23, menu);
			//Todo:  Save Game, exit;

			return;
		}

		//Todo: Win update, score
	}
	this->resetTraffic();
}