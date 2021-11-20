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
	UIHelper* helper = UIHelper::getUIHelper();

	ListTrucks listCars(lane, 1);
	listCars.setDirection(0);

	m.lock();
	listCars.loadTrucks("Test.txt", lane);
	listCars.trafficColor();
	m.unlock();
	//listCars.addTrucks(3,6); // Random: 4 -> 6


	bool isSave = true;
	while (!*isExit) {
		if (*isStop) {
			if (isSave) {
				listCars.setStorage();
				listCars.saveTrucks("Test.txt");
			}
			isSave = false;
			continue;
		}
		
		m.lock();

		if (listCars.getCount() % 20 == 0) {
			if (listCars.getRedLight()) {
				listCars.setRedLight(0);
				listCars.trafficColor();
				listCars.setCount(1);
			}
			else {
				listCars.setRedLight(1);
				listCars.trafficColor();
				listCars.setCount(1);

			}
		}
		listCars.setCount(listCars.getCount() + 1);

		
		if (listCars.getRedLight() == 0) {
			listCars.deleteListCar();
			listCars.drawListCar();

		}


		if (listCars.isCollision(character)) {

			*isStop = true;
		}

		listCars.updateListCar();
	
		
		
		m.unlock();
		Sleep(100 * lane);
	}
		
	

}

void Traffic::startTraffic() {
	*isStop = false;
	*isExit = false;

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