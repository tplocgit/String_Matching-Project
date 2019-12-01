#pragma once
#include "FileEater.h"
#include "SM_Algorithm.h"
enum searchAl {
	BRUTE_FORCE,
	RABIN_KARP,
	KNUTH_MORRIS_PRATT,
	NONE
};
//
//class CrossWord
//{
//public:
	//Data data;
	vector<POS> startSearch(string patt, Board table, searchAl p);

	char* convert(string patt);
//};

