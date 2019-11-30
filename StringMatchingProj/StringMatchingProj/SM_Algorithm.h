#pragma once
#include "pch.h"
#define d 26 //Number of charcters

class SM_Algorithm
{
public:
	static vector<int> Brute_Force(char* pattern, int sizePatt, char* text, int sizeText);
	static vector<int> Kabin_Karp(char* pattern, int m, char* text, int n);
	static vector<int> Knuth_Morris_Pratt(char* pattern, int pSize, char* text, int tSizet);
public:
	static int String_Hashing(char* patt,int length ,int q);
	static int String_ReHashing(int hash_value, char first_char, char new_char, int h, int q);
	static vector<int> findLPS(char* pattern, int m);
};