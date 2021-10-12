#include "HighScore.h"

void HighScore::drawUI() {
	UIHelper::getUIHelper()->drawHeaderText();

	ConsoleHelper* console = ConsoleHelper::getConsoleUtilities();

	int x = 41, y = 8, width = 25, height = 19;
	UIHelper::getUIHelper()->drawRectangleWithAnimate(x, y, width, height, 3);

	console->gotoXY(x, y + 4);
	Sleep(25);
	for (int i = 0; i < width * 2; i++) {
		cout << (char)177;
		Sleep(10);
	}

	console->showConsoleCursor(false);
	console->gotoXY(x + 8, y + 2);
	cout << "============ High Score ============" << endl;
	
	string add = console->getFilePath() + "HighScore.txt";

	fstream f(add, ios::in);

	vector<pair<string, int>> dataHighScore;
	if (f.fail()) {
		for (int i = 0; i <= 5; i++) dataHighScore.push_back(make_pair("-", 0));
	}
	else {
		while (!f.eof() && dataHighScore.size() < 5) {
			string name, t; int mark;
			getline(f, name);
			f >> mark; 
			dataHighScore.push_back(make_pair(name, mark));
			getline(f, name);
		}

		while (dataHighScore.size() < 5) dataHighScore.push_back(make_pair("-", 0));
	}

	y = y + 4;
	console->gotoXY(x + 5, y + 2); y = y + 2;
	cout << left << setw(5) << " Top " << left << setw(20) << "\t Name" << left << setw(8) << " Scores " << endl;

	for (int i = 0; i < dataHighScore.size(); i++) {
		y += 2; console->gotoXY(x + 5, y); 
		cout << left << "  " << setw(5) << i + 1 << left << " " << setw(20) << dataHighScore[i].first << left << "    " << setw(8) << dataHighScore[i].second << endl;
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