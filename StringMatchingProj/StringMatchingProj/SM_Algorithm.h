#pragma once
#include "pch.h"

class SM_Algorithm
{
public:
	static vector<int> Brute_Force(char* pattern, char* text);
	static vector<int> Kabin_Karp(char* pattern, int m, char* text, int n);
	static vector<int> Knuth_Morris_Pratt(char* pattern, int m, char* text, int n);
public:
	static int String_Hashing(char* patt, int m);
};

