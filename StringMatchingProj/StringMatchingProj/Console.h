//#include<iostream>
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<conio.h>
//#include<fstream>
//#include<string>
#include"pch.h"

#pragma once
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

#define key_none		-1
#define KEY_UP			72
#define KEY_DOWN		80
#define KEY_LEFT		75
#define KEY_RIGHT		77
#define KEY_ENTER		13
#define KEY_SPACE		32
#define KEY_ESC			27
#define MAUNEN			160
#define MAUCHU Color_Yellow


//-------------------------Screen-------------------------
void clrscr();

//screen: goto [x,y]
void gotoXY(int column, int line);
void TextColor(int color);
void resizeConsole(int width, int height);
void Exit();
