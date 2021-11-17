#include "FastAFCar.h"

FastAFCar::FastAFCar() {
	width = 9;
}

void FastAFCar::setCarWidth(int width) {
	this->width = width;
}

void FastAFCar::drawCar(int x, int y, int count) {
	UIHelper* p;
	p->getUIHelper()->setTextColor(244);
	if (count >= width) {
		p->getUIHelper()->gotoXY(x, y);
		cout << (char)219 << "    " << (char)219 << (char)223 << (char)223 << (char)221;
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << (char)219 << (char)220 << (char)220 << (char)220 << (char)220 << (char)219 << (char)220 << (char)220 << (char)219;
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << (char)219 << (char)220 << (char)219 << (char)223 << (char)223 << (char)223 << (char)219 << (char)220 << (char)219;
	}
	else if (count == width - 1) {
		p->getUIHelper()->gotoXY(x, y);
		cout << (char)219 << "    " << (char)219 << (char)223 << (char)223;
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << (char)219 << (char)220 << (char)220 << (char)220 << (char)220 << (char)219 << (char)220 << (char)220;
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << (char)219 << (char)220 << (char)219 << (char)223 << (char)223 << (char)223 << (char)219 << (char)220;
	}
	else if (count == width - 2) {
		p->getUIHelper()->gotoXY(x, y);
		cout << (char)219 << "    " << (char)219 << (char)223;
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << (char)219 << (char)220 << (char)220 << (char)220 << (char)220 << (char)219 << (char)220;
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << (char)219 << (char)220 << (char)219 << (char)223 << (char)223 << (char)223 << (char)219;
	}
	else if (count == width - 3) {
		p->getUIHelper()->gotoXY(x, y);
		cout << (char)219 << "    " << (char)219;
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << (char)219 << (char)220 << (char)220 << (char)220 << (char)220 << (char)219;
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << (char)219 << (char)220 << (char)219 << (char)223 << (char)223 << (char)223;
	}
	else if (count == width - 4) {
		p->getUIHelper()->gotoXY(x, y);
		cout << (char)219 << "    ";
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << (char)219 << (char)220 << (char)220 << (char)220 << (char)220;
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << (char)219 << (char)220 << (char)219 << (char)223 << (char)223;
	}
	else if (count == width - 5) {
		p->getUIHelper()->gotoXY(x, y);
		cout << (char)219 << "   ";
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << (char)219 << (char)220 << (char)220 << (char)220;
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << (char)219 << (char)220 << (char)219 << (char)223;
	}
	else if (count == width - 6) {
		p->getUIHelper()->gotoXY(x, y);
		cout << (char)219 << "  ";
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << (char)219 << (char)220 << (char)220;
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << (char)219 << (char)220 << (char)219;
	}
	else if (count == width - 7) {
		p->getUIHelper()->gotoXY(x, y);
		cout << (char)219 << " ";
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << (char)219 << (char)220;
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << (char)219 << (char)220;
	}
	else if (count == width - 8) {
		p->getUIHelper()->gotoXY(x, y);
		cout << (char)219;
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << (char)219;
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << (char)219;
	}
}

void FastAFCar::deleteCar(int x, int y, int count) {
	UIHelper* p;
	p->getUIHelper()->setTextColor(244);
	if (count >= width) {
		p->getUIHelper()->gotoXY(x, y);
		cout << "         ";
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << "         ";
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << "         ";
	}
	else if (count == width - 1) {
		p->getUIHelper()->gotoXY(x, y);
		cout << "        ";
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << "        ";
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << "        ";
	}
	else if (count == width - 2) {
		p->getUIHelper()->gotoXY(x, y);
		cout << "       ";
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << "       ";
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << "       ";
	}
	else if (count == width - 3) {
		p->getUIHelper()->gotoXY(x, y);
		cout << "      ";
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << "      ";
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << "      ";
	}
	else if (count == width - 4) {
		p->getUIHelper()->gotoXY(x, y);
		cout << "     ";
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << "     ";
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << "     ";
	}
	else if (count == width - 5) {
		p->getUIHelper()->gotoXY(x, y);
		cout << "    ";
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << "    ";
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << "    ";
	}
	else if (count == width - 6) {
		p->getUIHelper()->gotoXY(x, y);
		cout << "   ";
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << "   ";
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << "   ";
	}
	else if (count == width - 7) {
		p->getUIHelper()->gotoXY(x, y);
		cout << "  ";
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << "  ";
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << "  ";
	}
	else if (count == width - 8) {
		p->getUIHelper()->gotoXY(x, y);
		cout << " ";
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << " ";
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << " ";
	}
}

void FastAFCar::drawCarReverse(int x, int y, int count) {
	UIHelper* p;
	p->getUIHelper()->setTextColor(244);
	if (count >= width) {
		p->getUIHelper()->gotoXY(x, y);
		cout << (char)222 << (char)223 << (char)223 << (char)219 << "    " << (char)219;
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << (char)219 << (char)220 << (char)220 << (char)219 << (char)220 << (char)220 << (char)220 << (char)220 << (char)219;
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << (char)219 << (char)220 << (char)219 << (char)223 << (char)223 << (char)223 << (char)219 << (char)220 << (char)219;
	}
	else if (count == width - 1) {
		p->getUIHelper()->gotoXY(x, y);
		cout << (char)223 << (char)223 << (char)219 << "    " << (char)219;
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << (char)220 << (char)220 << (char)219 << (char)220 << (char)220 << (char)220 << (char)220 << (char)219;
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << (char)220 << (char)219 << (char)223 << (char)223 << (char)223 << (char)219 << (char)220 << (char)219;
	}
	else if (count == width - 2) {
		p->getUIHelper()->gotoXY(x, y);
		cout << (char)223 << (char)219 << "    " << (char)219;
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << (char)220 << (char)219 << (char)220 << (char)220 << (char)220 << (char)220 << (char)219;
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << (char)219 << (char)223 << (char)223 << (char)223 << (char)219 << (char)220 << (char)219;
	}
	else if (count == width - 3) {
		p->getUIHelper()->gotoXY(x, y);
		cout << (char)219 << "    " << (char)219;
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << (char)219 << (char)220 << (char)220 << (char)220 << (char)220 << (char)219;
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << (char)223 << (char)223 << (char)223 << (char)219 << (char)220 << (char)219;
	}
	else if (count == width - 4) {
		p->getUIHelper()->gotoXY(x, y);
		cout << "    " << (char)219;
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << (char)220 << (char)220 << (char)220 << (char)220 << (char)219;
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << (char)223 << (char)223 << (char)219 << (char)220 << (char)219;
	}
	else if (count == width - 5) {
		p->getUIHelper()->gotoXY(x, y);
		cout << "   " << (char)219;
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << (char)220 << (char)220 << (char)220 << (char)219;
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << (char)223 << (char)219 << (char)220 << (char)219;
	}
	else if (count == width - 6) {
		p->getUIHelper()->gotoXY(x, y);
		cout << "  " << (char)219;
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << (char)220 << (char)220 << (char)219;
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << (char)219 << (char)220 << (char)219;
	}
	else if (count == width - 7) {
		p->getUIHelper()->gotoXY(x, y);
		cout << " " << (char)219;
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << (char)220 << (char)219;
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << (char)220 << (char)219;
	}
	else if (count == width - 8) {
		p->getUIHelper()->gotoXY(x, y);
		cout << (char)219;
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << (char)219;
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << (char)219;
	}
}

void FastAFCar::deleteCarReverse(int x, int y, int count) {
	UIHelper* p;
	p->getUIHelper()->setTextColor(244);
	if (count >= width) {
		p->getUIHelper()->gotoXY(x, y);
		cout << "         ";
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << "         ";
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << "         ";
	}
	else if (count == width - 1) {
		p->getUIHelper()->gotoXY(x, y);
		cout << "        ";
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << "        ";
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << "        ";
	}
	else if (count == width - 2) {
		p->getUIHelper()->gotoXY(x, y);
		cout << "       ";
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << "       ";
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << "       ";
	}
	else if (count == width - 3) {
		p->getUIHelper()->gotoXY(x, y);
		cout << "      ";
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << "      ";
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << "      ";
	}
	else if (count == width - 4) {
		p->getUIHelper()->gotoXY(x, y);
		cout << "     ";
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << "     ";
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << "     ";
	}
	else if (count == width - 5) {
		p->getUIHelper()->gotoXY(x, y);
		cout << "    ";
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << "    ";
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << "    ";
	}
	else if (count == width - 6) {
		p->getUIHelper()->gotoXY(x, y);
		cout << "   ";
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << "   ";
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << "   ";
	}
	else if (count == width - 7) {
		p->getUIHelper()->gotoXY(x, y);
		cout << "  ";
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << "  ";
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << "  ";
	}
	else if (count == width - 8) {
		p->getUIHelper()->gotoXY(x, y);
		cout << " ";
		p->getUIHelper()->gotoXY(x, y + 1);
		cout << " ";
		p->getUIHelper()->gotoXY(x, y + 2);
		cout << " ";
	}
}

void FastAFCar::drawCar(int x, int y) {

}

void FastAFCar::deleteCar(int x, int y) {

}
