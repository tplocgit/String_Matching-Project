#include "GUI.h"


void GUI::SplashScreen(int time) {
	//cout << "A long time ago, in a galaxy far far away....";
}

void GUI::FirstLayer() {
	//Start
	//Exit
	vector<string> Options{ "Start", "Exit" };
	menu(Options, 1);

}
void GUI::SecondLayer() {
	//Input from file
	//Randomly generated data
	//Manually input (Height -> Width -> Table)
	vector<string> Options{ "Input from file", "Generate randon data", "Manual input" , "Return" };
	menu(Options, 2);
}
void GUI::doTask1(int choiceNum) {
	switch (choiceNum) {
	case 1:
		break;
	case 2:
		Exit();
		break;

	default:
		break;
	}

}

void GUI::doTask2(int choiceNum) {
	switch (choiceNum) {
	case 1:
		//Input from file
		break;
	case 2:
		//Generate randon data
		break;
	case 3:
		//Manual input
		break;
	case 4:
		//Return
		return;
		break;
	default:
		break;
	}
}
int GUI::menu(vector <string> optionList, int menuNumber) {
	short int choiceSize = optionList.size();
	short int choice = 0;
	
	clrscr();
	
	for (auto i = 0; i < choiceSize; ++i) {
		if (i == choice) {
			TextColor(SELECTED_COLOR);
			gotoXY(Width_Offset - 3, Height_Offset + i);
			cout << ">> " << optionList[i] << " <<                ";
		}
		else {
			TextColor(default_ColorCode);
			gotoXY(Width_Offset, Height_Offset + i);
			cout << optionList[i] << "                ";
		}
	}

	while (1) {
		char key = _getch();
		if (key == 'W' || key == 'w' || key == KEY_UP) {
			if (choice == 0)
				choice = choiceSize - 1;
			else ++choice;
		}
		else if (key == 'S' || key == 's' || key == KEY_DOWN) {
			if (choice == choiceSize - 1)
				choice = 0;
			else --choice;
		}
		else if (key == 'a' || key == 'A' || key == KEY_LEFT) {
			if (choice == choiceSize - 1)
				choice = 0;
			else --choice;
		}
		else if (key == 'd' || key == 'D' || key == KEY_RIGHT) {
			if (choice == 0)
				choice = choiceSize - 1;
			else ++choice;
		}
		//--------------------Main part----------------
		else if (key == KEY_ENTER || key == KEY_SPACE) {
			if (menuNumber == 1)
				doTask2(choice);
			else if (menuNumber == 1)
				doTask2(choice);
		}

	}
}
