#pragma once
#include "pch.h"
#include "Console.h"

#define ON_COLOR		Color_Green
#define OFF_COLOR		Color_Red
#define SELECTED_COLOR	Color_Cyan

#define Height_Offset	7
#define Width_Offset	20
class GUI
{
public:
	void SplashScreen(int time);
	void FirstLayer();
	void SecondLayer();
private:
	void doTask1(int choiceNum);
	void doTask2(int choiceNum);
	int menu(vector <string> optionList, int menuNumber);

};

