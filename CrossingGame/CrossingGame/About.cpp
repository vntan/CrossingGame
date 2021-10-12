#include "About.h"

void About::drawUI() {
	UIHelper::getUIHelper()->drawHeaderText();
	
	ConsoleHelper* console = ConsoleHelper::getConsoleUtilities();

	int x = 41, y = 8, width = 25, height = 19;
	UIHelper::getUIHelper()->drawRectangleWithAnimate(x, y, width, height, 3);

	console->gotoXY(x, y + 4);
	Sleep(25);
	for (int i = 0; i < width*2; i++) {
		cout << (char)177;
		Sleep(10);
	}

	console->showConsoleCursor(false);
	console->gotoXY(x + 10, y + 2);
	cout << "============ ABOUT ============" << endl;
	y = y + 4;
	console->gotoXY(x + 3, y + 2);
	cout << "\tGV huong dan: Truong Toan Thinh" << endl;
	console->gotoXY(x + 3, y + 4);
	cout << "\t1. Vo Nhat Tan " << setw(20) << "- 20127323" << endl;
	console->gotoXY(x + 3, y + 6);
	cout << "\t2. Nguyen Phat Thinh " << setw(14) << "- 20127334" << endl;
	console->gotoXY(x + 3, y + 8);
	cout << "\t3. Le Nhat Duy " << setw(20) << "- 20127469" << endl;
	console->gotoXY(x + 3, y + 10);
	cout << "\t4. Ngo Duc Bao " << setw(20) << "- 20127447" << endl;
	console->gotoXY(x + 3, y + 12);
	cout << "\t5. Dinh Anh Quoc " << setw(18) << "- 20127302" << endl;
	console->gotoXY(x + 3, y + 14);


	while (true) {
		if (_kbhit()) {
			int key = _getch();

			if (key == 27) {
				console->clrscr();
				system("color F0");
				return;
			}
		}
	}
		
	
}