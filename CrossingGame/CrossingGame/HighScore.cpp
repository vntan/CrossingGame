#include "HighScore.h"

void HighScore::drawUI() {

	UIHelper* console = UIHelper::getUIHelper();
	console->drawHeaderText();

	int x = 41, y = 8, width = 25, height = 19;
	console->drawRectangleWithAnimate(x, y, width, height, 3);

	console->gotoXY(x, y + 4);
	Sleep(25);
	for (int i = 0; i < width * 2; i++) {
		cout << (char)177;
		Sleep(10);
	}

	console->showConsoleCursor(false);
	console->gotoXY(x + 8, y + 2);
	cout << "============ High Score ============" << endl;
	
	vector<User> userScore = Account::getInstance()->getListAccount();

	sort(userScore.begin(), userScore.end(), [](User a, User b) {
			return a.getScore() > b.getScore();
			});
	

	y = y + 4;
	console->gotoXY(x + 5, y + 2); y = y + 2;
	cout << left << setw(5) << " Top " << left << setw(20) << "\t Name" << left << setw(8) << " Scores " << endl;


	for (int i = 0; i < 5; i++) {
		y += 2; console->gotoXY(x + 5, y);
		if (i<userScore.size())
			cout << left << "  " << setw(5) << i + 1 << left << " " << setw(20) << userScore[i].getName() << left << "    " << setw(8) << userScore[i].getScore() << endl;
		else 
			cout << left << "  " << setw(5) << i + 1 << left << " " << setw(20) << " - " << left << "    " << setw(8) << "0" << endl;
	}
	

	

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