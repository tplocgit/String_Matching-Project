#pragma once
#include "pch.h"

class Board
{
private:
	int s_height, s_width;
	char** s_board;


public:
	Board();
	Board(int height, int width);
	~Board();

};

