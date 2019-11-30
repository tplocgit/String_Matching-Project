#include "SM_Algorithm.h"

vector<int> SM_Algorithm::Brute_Force(char* pattern, int m, char* text, int n) {

}

vector<int> SM_Algorithm::Kabin_Karp(char* pattern, char* text) {
	int m = strlen(pattern);
	int n = strlen(text);
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
	int p = SM_Algorithm::String_Hashing(pattern, q);
	int t = SM_Algorithm::String_Hashing(text, q);

	// O(m(n-m)) matching
	for (int s = 0; s < n - m; ++s) {// O(n - m)
		if (p == t) {
			int count = 0;
			while (count < m && pattern[count] == text[count])
				count++; // Count same character, O(m)
			if (count == m)// All character is same
				res.push_back(s);
		}
		if (s < n - m)
			t = SM_Algorithm::String_ReHashing(t, text[s], text[s + m], h, q);
	}

	return res;
}

vector<int> SM_Algorithm::Knuth_Morris_Pratt(char* pattern, char* text) {

}

int SM_Algorithm::String_Hashing(char* patt, int q) {// O(m)
	if (patt == nullptr)
		throw "Error: Invalid input";
	//d: alphabet
	//m: length of pattern
	//q: a prime number
	//h: d^(m - 1) % q
	//p: result

	int m = strlen(patt);
	int p;

	for (int i = 0; i < m; ++i)
		p = (d * p + patt[i]) % q;

	return p;
}

int SM_Algorithm::String_ReHashing(int hash_value, char first_char, char new_char, int h, int q) {// O(1)
	int t = (d * (hash_value - h * first_char) + new_char) % q;
	return t >= 0 ? t : t + q;
}