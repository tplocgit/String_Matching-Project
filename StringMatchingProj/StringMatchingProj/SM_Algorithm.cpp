#include "SM_Algorithm.h"

vector<int> SM_Algorithm::Brute_Force(char* pattern, char* text) {
	if (pattern == nullptr || text == nullptr)
		throw "Error: Invalid input";

	int sizePatt = strlen(pattern),
		sizeText = strlen(text);

	if (sizePatt > sizeText)
		throw "Error: Invalid input";

	vector<int> ans;
	for (int i = 0; i < (sizeText - sizePatt); ++i) {
		int count = 0;
		for (int j = 0; j < sizePatt; ++j) {
			if (pattern[j] == text[i + j])
				++count;
			else 
				break;
		}
		if (count == sizePatt)
			ans.push_back(i);
	}
	return ans;
}

vector<int> SM_Algorithm::Kabin_Karp(char* pattern, int m, char* text, int n) {
	return {};
}

vector<int> SM_Algorithm::Knuth_Morris_Pratt(char* pattern, int m, char* text, int n) {
	return {};
}