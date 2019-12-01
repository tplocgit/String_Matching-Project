#pragma once
#include "pch.h"
#include "Board.h"
struct Data{
	Board Matrix;
	vector <string> pattern;
	bool Load2DBoard();
	void cumOutput();
};