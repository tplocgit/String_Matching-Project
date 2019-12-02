#include "SM_Algorithm.h"

vector<int> SM_Algorithm::Brute_Force(char* pattern, int sizePatt, char* text, int sizeText) {
	if (pattern == nullptr || text == nullptr || sizeText < sizePatt || sizePatt < 0 || sizeText < 0)
		throw "Error: Invalid input";

	vector<int> ans;
	for (int i = 0; i <= (sizeText - sizePatt); ++i) {
		int count = 0;
		while (count < sizePatt) {
			if (pattern[count] != text[i + count])
				break;
			else
				++count;
		}

		if (count == sizePatt)//giống hết
			ans.push_back(i);//
	}
	return ans;
}


vector<int> SM_Algorithm::Rabin_Karp(char* pattern, int m, char* text, int n) {
	if (pattern == nullptr || text == nullptr || m < 0 || n < 0 || n < m)
		return {};

	int q = 29;// Prime number
	int h = int(pow(d, m - 1)) % q;
	vector<int> res;

	//d: number of char in alphabet
	//m: length of pattern
	//q: a prime number
	//h: d^(m - 1) % q
	//p: result

	// Pre-processing, O(2m)
	int p = SM_Algorithm::String_Hashing(pattern, m, q);
	int t = SM_Algorithm::String_Hashing(text, m, q);

	// O(m(n-m)) matching
	for (int s = 0; s <= n - m; ++s) {// O(n - m)
		if (p == t) {
			int count = 1;
			while (count < m && pattern[count - 1] == text[s + count - 1])
				count++; // Count same character, O(m)
			if (count == m)// All character is same
				res.push_back(s);
		}
		if (s <= n - m)
			t = SM_Algorithm::String_ReHashing(t, text[s], text[s + m], h, q);
	}

	return res;
}


vector<int> SM_Algorithm::Knuth_Morris_Pratt(char* pattern, int pSize, char* text, int tSize) {
	vector<int> result;
	vector<int> lps = findLPS(pattern, pSize);
	int j = 0;// Index of lps for skipping number of characters
	for (int i = 0; i < tSize; i++) {
		while (j > 0 && (pattern[j] != text[i]))// Pattern and text doesn't match, reset j
			j = lps[j - 1];
		if (pattern[j] == text[i])// If pattern and text match increase j
			j++;
		if (j == pSize) {// If j equal pSize that mean the pattern are match
			result.push_back(i - j + 1);// Save index to result
			j = lps[j - 1];// Reset j 
		}
	}
	return result;
}

int SM_Algorithm::String_Hashing(char* patt, int length, int q) {// O(m)
	if (patt == nullptr)
		throw "Error: Invalid input";
	// d: alphabet character
	// m: length of pattern
	// q: a prime number
	// h: d^(m - 1) % q
	// p: result

	int p = 0;

	for (int i = 0; i < length; ++i)
		p = (d * p + patt[i]) % q;

	return p;
}

//------------------------------------------------
int SM_Algorithm::String_ReHashing(int hash_value, char first_char, char new_char, int h, int q) {// O(1)
	int t = (d * (hash_value - h * first_char) + new_char) % q;
	// t may be a negative value, so we need to make it become positive
	return t >= 0 ? t : t + q;
}

vector<int> SM_Algorithm::findLPS(char* pattern, int m) {
	vector<int> lps;
	lps.resize(m);
	lps[0] = 0;
	int j = 0;// Index of lps for saving longest prefix suffix for each position in pattern
	for(int i = 1; i < m; i++) {
		while ((pattern[j] != pattern[i]) && j > 0)// Reset j
			j = lps[j - 1];
		if (pattern[j] == pattern[i])// Match then increase j
			j++;
		lps[i] = j;// Save longest prefix suffix at position i
	}
	return lps;
}