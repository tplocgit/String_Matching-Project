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



public:
	Board();
	Board(int )
};

