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
	ListFastAFCars fastAF;
	fastAF.setLane(lane);
	fastAF.setLevel(5);
	int count = 1;
	fastAF.trafficColor();
	while (true) {
		if (*isStop)
			continue;
		m.lock();

		if (count % 100 == 0) {
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
	
	//Sleep(1000);
}

void Traffic::startTraffic() {
	*isStop = false;
	*isExit = false;

	(*character).deleteCharacter();
	(*character).resetCharater(true);

	thread control(&Traffic::processCharacter, this);
	//thread l1(&Traffic::carInLane, this, 1);
	thread l2(&Traffic::carInLane, this, 2);


	//l1.join();
	l2.join();
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