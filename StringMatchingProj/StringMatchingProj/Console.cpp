#include <stdio.h>
#include <conio.h>
#include "console.h"

using namespace std;

int x, y, m, n;
int inputKey()
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)	// special key
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return key_none;
	}

	return key_none;
}


//-------------------------Screen-------------------------
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0,0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}


//screen: goto [x,y]
void gotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


//screen: get [x]
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}


//screen: get [y]
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}


void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void keyLEFT()
{
	x -= 1;
	if (x < 13) x = 13;
}

void keyRIGHT()
{
	x += 1;
	if (x >= 77) x = 77;
}

void keyUP()
{
	y -= 1;
	if (y < 3) y = 3;
}

void keyDOWN()
{
	y += 1;
	if (y >= 24) y = 24;
}

void pointer(short x, short y)
{  //Phuc vu cho di chuyen
	gotoXY(x, y);
	n = x; m = y;
}
void printxy(string str, int x, int y)
{
	static HANDLE  handle = NULL;
	if (!handle)
		handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { (short)x, (short)y };
	SetConsoleCursorPosition(handle, c);
	cout << str;
}


void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void ColorTable()
{
	TextColor(11); gotoXY(45, 1); cout << "--------COLOR-------";
	TextColor(7); gotoXY(45, 2); cout << "1: Blue"; TextColor(1); cout << "\t\t" << (char)219 << (char)219 << (char)219 << endl;
	TextColor(7); gotoXY(45, 3); cout << "2: Green"; TextColor(2); cout << "\t\t" << (char)219 << (char)219 << (char)219 << endl;
	TextColor(7); gotoXY(45, 4); cout << "3: Light Blue"; TextColor(3); cout << "\t" << (char)219 << (char)219 << (char)219 << endl;
	TextColor(7); gotoXY(45, 5); cout << "4: Red"; TextColor(4); cout << "\t\t" << (char)219 << (char)219 << (char)219 << endl;
	TextColor(7); gotoXY(45, 6); cout << "5: Puprle"; TextColor(5);  cout << "\t\t" << (char)219 << (char)219 << (char)219 << endl;
	TextColor(7); gotoXY(45, 7); cout << "6: Gold"; TextColor(6); cout << "\t\t" << (char)219 << (char)219 << (char)219 << endl;
	TextColor(7); gotoXY(45, 8); cout << "7: Dark White"; TextColor(7); cout << "\t" << (char)219 << (char)219 << (char)219 << endl;
	TextColor(7); gotoXY(45, 9); cout << "8: Gray"; TextColor(8); cout << "\t\t" << (char)219 << (char)219 << (char)219 << endl;
	TextColor(7); gotoXY(45, 10); cout << "9: Bright Blue"; TextColor(9); cout << "\t" << (char)219 << (char)219 << (char)219 << endl;
	TextColor(7); gotoXY(45, 11); cout << "10: Bright Green"; TextColor(10); cout << "\t" << (char)219 << (char)219 << (char)219 << endl;
	TextColor(7); gotoXY(45, 12); cout << "11: Aqua"; TextColor(11); cout << "\t\t" << (char)219 << (char)219 << (char)219 << endl;
	TextColor(7); gotoXY(45, 13); cout << "12: Bright Red"; TextColor(12); cout << "\t" << (char)219 << (char)219 << (char)219 << endl;
	TextColor(7); gotoXY(45, 14); cout << "13: Pink"; TextColor(13); cout << "\t\t" << (char)219 << (char)219 << (char)219 << endl;
	TextColor(7); gotoXY(45, 15); cout << "14: Yellow"; TextColor(14); cout << "\t\t" << (char)219 << (char)219 << (char)219 << endl;
	TextColor(7); gotoXY(45, 16); cout << "15: White"; TextColor(15); cout << "\t\t" << (char)219 << (char)219 << (char)219 << endl;
}


///////////////


//------------------------------------------------------

void Exit()
{
	system("cls");
	system("color 80");

	gotoXY(55, 19); cout << "Good_Bye";
	gotoXY(58, 20); cout << "=)";
	Sleep(500);

	ExitProcess(0);
}



