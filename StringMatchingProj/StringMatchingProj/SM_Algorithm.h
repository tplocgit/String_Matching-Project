#pragma once
#include "pch.h"
#define d 26 //Number of charcters

class SM_Algorithm
{
public:
	static vector<int> Brute_Force(char* pattern, int m, char* text, int n);
	static vector<int> Kabin_Karp(char* pattern, char* text);
	static vector<int> Knuth_Morris_Pratt(char* pattern, char* text);
public:
	static int String_Hashing(char* patt, int q);
	static int String_ReHashing(int hash_value, char first_char, char new_char, int h, int q);
};