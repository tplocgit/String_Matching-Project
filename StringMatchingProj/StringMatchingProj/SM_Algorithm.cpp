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

		if (count == sizePatt)// All match
			ans.push_back(i);//
	}
	return ans;
}


vector<int> SM_Algorithm::Rabin_Karp(char* pattern, int m, char* text, int n) {
	if (pattern == nullptr || text == nullptr || m < 0 || n < 0 || n < m)// Invalid input
		return {};// Emty array(vector)

	// Prime number
	int h = SM_Algorithm::Pow_Mod_q(d, m - 1);// h = d^(m - 1) mod q
	vector<int> res;

	//d: number of char in alphabet
	//m: length of pattern
	//q: a prime number
	//h: d^(m - 1) % q
	//p: result

	// Pre-processing, O(2m)
	int p = SM_Algorithm::String_Hashing(pattern, m);
	int t = SM_Algorithm::String_Hashing(text, m);

	// O(m(n-m)) matching
	for (int s = 0; s <= n - m; ++s) {// O(n - m)
		if (p == t) {// Matching
			int count = 1;// Store number of character that match
			while (count < m && pattern[count - 1] == text[s + count - 1])
				count++; // Count same character, O(m)
			if (count == m)// All character is matching
				t = SM_Algorithm::String_ReHashing(t, text[s], text[s + m], h);
		}

		return res;
	}
}


vector<int> SM_Algorithm::Knuth_Morris_Pratt(char* pattern, int pSize, char* text, int tSize) {
	vector<int> result;
	vector<int> lps = findLPS(pattern, pSize);// Pre-processing, find longest prefix suffix for skipping, O(m)

	int j = 0;// Store index of lps for skipping number of characters

	for (int i = 0; i < tSize; i++) {
		while (j > 0 && (pattern[j] != text[i]))// Pattern and sub-text doesn't match, reset j
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

int SM_Algorithm::String_Hashing(char* patt, int length) {// O(m)
	if (patt == nullptr)
		throw "Error: Invalid input";

	// d: alphabet character
	// m: length of pattern
	// q: a prime number
	// h: d^(m - 1) % q
	// p: result

	int p = 0;// Store hash value of input

	for (int i = 0; i < length; ++i)
		p = (d * p + patt[i]) % q;

	return p;
}

//------------------------------------------------
int SM_Algorithm::String_ReHashing(int hash_value, char MSD, char LSD, int64_t h) {// O(1)
	int t = (d * (hash_value - h * MSD) + LSD) % q;
	// t may be a negative value, so we need to make it become positive
	return t >= 0 ? t : t + q;
}

vector<int> SM_Algorithm::findLPS(char* pattern, int m) {
	vector<int> lps;
	lps.resize(m);
	lps[0] = 0;
	int j = 0;// Index of lps for saving longest prefix suffix for each position in pattern
	for (int i = 1; i < m; i++) {
		while ((pattern[j] != pattern[i]) && j > 0)// Reset j
			j = lps[j - 1];
		if (pattern[j] == pattern[i])// Match then increase j
			j++;
		lps[i] = j;// Save longest prefix suffix at position i
	}
	return lps;
}

string SM_Algorithm::Algo_String_Name(searchAl enumName) {
	string name;
	if (enumName == BRUTE_FORCE)
		name = "Brute_Force";
	else if (enumName == RABIN_KARP)
		name = "RAbin_Karp";
	else
		name = "Knuth_Morris_Pratt";

	if (name.empty())
		name = "<Undefine>";
	return name;
}

int SM_Algorithm::Pow_Mod_q(int x, int n) {
	if (n == 1)
		return x % q;

	int val = SM_Algorithm::Pow_Mod_q(x, n / 2);

	if (n % 2 == 0)
		return (val * val) % q;
	else
		return (x * val * val) % q;

}
