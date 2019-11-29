#pragma once
#include "pch.h"

class SM_Algorithm
{
public:
	static vector<int> Brute_Force(char* patterm, int m, char* text, int n);
	static vector<int> Kabin_Karp(char* patterm, int m, char* text, int n);
	static vector<int> Knuth_Morris_Pratt(char* patterm, int m, char* text, int n);
public:
	static int String_Hashing(char* patt, int m);
};

