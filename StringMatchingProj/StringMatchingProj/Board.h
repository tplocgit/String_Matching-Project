#pragma once
#include "pch.h"

enum RESULT_STATUS {
	LEFT_RIGHT,
	TOP_DOWN,
	NOT_FOUND
};

struct POS {
	int x, y;
	RESULT_STATUS status;
};

class Board
{
private:
	int s_height, s_width;
	char** s_board;

public:
	Board();
	Board(int height, int width);
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
