﻿#include "Traffic.h"

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
	//Khởi tạo ListCar ListRoyalCar t;
	while (true) {
		m.lock();

		//t.updateListCar(); -> xóa tất cả xe trên làn, vẽ ra xe trên làn theo vị trí mới


		m.unlock();
		Sleep(1000);
	}
	
	//Sleep(1000);
}

void Traffic::startTraffic() {
	*isStop = false;
	*isExit = false;

	(*character).deleteCharacter();
	(*character).resetCharater(true);

	thread control(&Traffic::processCharacter, this);
	thread l1(&Traffic::carInLane, this, 1);
	thread l2(&Traffic::carInLane, this, 2);


	l1.join();
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