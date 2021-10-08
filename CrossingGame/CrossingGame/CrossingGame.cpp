#include <iostream>
#include "ConsoleHelper.h"

using namespace std;



int main() {
	cout << "Hello World";

	ConsoleHelper::getConsole()->clrscr();
	
	
	while (true) {
		while (!_kbhit()) {}
		cout << ConsoleHelper::getConsole()->getKey() << endl;
	}
	
	

}