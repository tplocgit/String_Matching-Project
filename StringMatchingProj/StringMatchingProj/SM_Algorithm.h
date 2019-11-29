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

class SM_Algorithm
{
public:
	static vector<POS> Brute_Force(char* patterm, int m, char* text, int n);
	static vector<POS> Kabin_Karp(char* patterm, int m, char* text, int n);
	static vector<POS> Knuth_Morris_Pratt(char* patterm, int m, char* text, int n);

};

