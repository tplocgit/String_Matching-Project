#pragma once
#include "pch.h"

enum RESULT_STATUS {
	LEFT_RIGHT,
	TOP_DOWN,
	NOT_FOUND
};

struct POS {
	int s_x, s_y;
	RESULT_STATUS status;
	//---------------
	POS() {
		s_x = s_y = 0;
		status = NOT_FOUND;
	}
	POS(int y, int x, RESULT_STATUS stat) {
		s_x = x;
		s_y = y;
		status = stat;
	}
	//------------
	string getStat() {
		if (status == LEFT_RIGHT)
			return "LR";
		else if (status == TOP_DOWN)
			return "TD";
		else return "NF";
	}
};

class Board
{
public:
	int s_height, s_width;
	char** s_board;

public:
	Board();
	Board(int height, int width);
	Board(const Board& obj);
	~Board();

public:
	char* getRow(int row);
	char* getCol(int col);
	void printCol(int col);
	void printRow(int row);
	void printBoard();

//--------------------------------
	char random(char start, char end);
	void GenerateRandomData();
	char* operator[](int index);
};
