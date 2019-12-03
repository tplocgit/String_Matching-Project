#pragma once
#include "pch.h"
#include "Board.h"
struct Data {
	Board Matrix;
	vector <string> pattern;
	bool Load2DBoard(string fileName);
	void cumOutput(vector<vector<POS>> list, vector<string> nameList, string name);
};