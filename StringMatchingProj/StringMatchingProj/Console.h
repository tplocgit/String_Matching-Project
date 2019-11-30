#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<stdio.h>
//#include<stdlib.h>
#include<Windows.h>
#include<windows.h>
#include"pch.h"
//#include<string.h>
//#include<conio.h>
//#include<fstream>
//#include<string>

//--------
#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

#ifndef _console_header
#define _console_header


#define Color_Back			0
#define Color_DarkBlue		1
#define Color_DarkGreen		2
#define Color_DarkCyan		3
#define Color_DarkRed		4
#define Color_DarkPink		5
#define Color_DarkYellow	6
#define Color_DarkWhite		7
#define Color_Gray			8
#define Color_Blue			9
#define Color_Green			10
#define Color_Cyan			11
#define Color_Red			12
#define Color_Pink			13
#define Color_Yellow		14
#define Color_White			15

#define default_ColorCode	7

/*
#define key_Up		1072
#define key_Down	1080
#define key_Left	1075
#define key_Right	1077*/
#define key_none	-1

#define KEY_UP 72

#define KEY_DOWN 80

#define KEY_LEFT 75

#define KEY_RIGHT 77

#define KEY_ENTER 13

#define KEY_SPACE 32

#define KEY_ESC 27
#define MAUNEN 160
#define MAUCHU Color_Yellow

/*Phím Enter : 13
Phím Space : 32
Phím Xóa ngược(BackSpace) < -- : 8
	Phím ESC : 27
*/
int inputKey();

//-------------------------Screen-------------------------
void clrscr();

//screen: goto [x,y]
void gotoXY(int column, int line);

//screen: get [x]
int whereX();

//screen: get [y]
int whereY();

void TextColor(int color);
//end----------------------Screen----------------------end
void keyUP();
void keyDOWN();
void keyLEFT();
void keyRIGHT();

void printxy(string str, int x, int y);
void resizeConsole(int width, int height);
void Exit();
#endif
