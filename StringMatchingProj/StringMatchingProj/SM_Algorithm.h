#pragma once
#include "pch.h"

#define d 26 //Number of charcters
#define q 29 // Prime number

enum searchAl {
	BRUTE_FORCE,
	RABIN_KARP,
	KNUTH_MORRIS_PRATT,
	NONE
};
string Algo_String_Name(searchAl enumName);

class SM_Algorithm
{
public:
	static vector<int> Brute_Force(char* pattern, int sizePatt, char* text, int sizeText);
	static vector<int> Rabin_Karp(char* pattern, int m, char* text, int n);
	static vector<int> Knuth_Morris_Pratt(char* pattern, int pSize, char* text, int tSize);

public:
	static int Pow_Mod_q(int x,int n);
	static int String_Hashing(char* patt,int length);
	static int String_ReHashing(int hash_value, char first_char, char new_char, int64_t h);
	static vector<int> findLPS(char* pattern, int m);
};