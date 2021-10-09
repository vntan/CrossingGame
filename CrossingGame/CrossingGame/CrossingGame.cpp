#include <iostream>
#include "ConsoleHelper.h"
#include "UIHelper.h"

using namespace std;

int main() {
	cout << "Hello World";

	ConsoleHelper::getConsoleUtilities()->clrscr();
	//ConsoleHelper::getConsoleUtilities()->getAllTextColor();
	
	vector<string> listMenu = { "Cong viec 1", "Cong viec 2", "Cong viec 3", "Cong viec 4" };

	
	//cout<<helper.createMenu(25, 16, listMenu, 2);

	
	UIHelper::getUIHelper()->drawRectangle(0, 0, 25, 25, 3);

	/*while (true) {
		while (!_kbhit()) {}
		cout << "Oke" << ConsoleHelper::getConsoleUtilities()->getKey() << endl;
	}*/
}