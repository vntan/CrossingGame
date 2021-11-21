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
	
	ListChickens listChicks(lane, 1);
	listChicks.setDirection(true);
	m.lock();
	listChicks.trafficColor();
	m.unlock();
	listChicks.addChicken(4,5);
	int count = 0;
	while (!*isExit) {
		if (*isStop) continue;
		m.lock();
		if (listChicks.getRedlight()) {
			listChicks.deleteListCar();
			listChicks.drawListCar();
		}
		if (count == 30) {
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

			*isStop = true;
		}

		listChicks.updateListCar();
		
		m.unlock();
		Sleep(100 * user.getLevel());
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