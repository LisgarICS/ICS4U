// Sample program to show how to set position and colour.
#include <iostream>
#include <windows.h>
#include <ctime>
 

//Defines gotoxy() for ANSI C compilers.
void gotoxy(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main() {
	short r, c;
	char ch;
	
	srand(time(0));
	system("Color 0A");
	for (int i=0; i< 15000; i++) {
		r = rand() % 24;
		c = rand() % 80;
		gotoxy(c, r);
		if (rand() % 2)
			ch = rand() % 26 + 'a';
		else
			ch = ' ';
		std::cout << ch << std::endl;
		Sleep(10);
	}
	return 0;
}
