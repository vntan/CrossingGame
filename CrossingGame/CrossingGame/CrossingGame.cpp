#include <iostream>
#include "ConsoleHelper.h"

using namespace std;

int main() {
	cout << "Hello World";

	ConsoleHelper::getConsoleUtilities()->clrscr();
	
	
	while (true) {
		while (!_kbhit()) {}
		cout << ConsoleHelper::getConsoleUtilities()->getKey() << endl;
	}
}