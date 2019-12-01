#include "CrossWord.h"

vector<POS> startSearch(string patt, Board table, searchAl p) {
	//---Ngang---

	vector<POS> ans;
	char* key = nullptr;
	key = convert(patt);
	if (key == nullptr)
		return {};

	for (auto i = 0; i < table.s_height; ++i) {
		char* list = table.getRow(i);
		//vector <int> pos_y;
		vector<int> x;
		// search theo từng Algor 
		if (p == BRUTE_FORCE)
			x = SM_Algorithm::Brute_Force(key, patt.length(), list, table.s_width);

		else if (p == RABIN_KARP)
			x = SM_Algorithm::Rabin_Karp(key, patt.length(), list, table.s_width);

		else if (p == KNUTH_MORRIS_PRATT)
			x = SM_Algorithm::Knuth_Morris_Pratt(key, patt.length(), list, table.s_width);

		if (!x.empty()) {
			for (int j = 0; j < x.size(); ++j) {
				POS place(x[j] + 1, i + 1, LEFT_RIGHT);
				ans.push_back(place);
			}
		}

	}


	//---Dọc-----
	for (auto i = 0; i < table.s_width; ++i) {
		char* list = table.getCol(i);
		//vector <int> pos_x;
		vector<int> y;
		if (p == BRUTE_FORCE)
			y = SM_Algorithm::Brute_Force(key, patt.length(), list, table.s_height);

		else if (p == RABIN_KARP)
			y = SM_Algorithm::Rabin_Karp(key, patt.length(), list, table.s_height);

		else if (p == KNUTH_MORRIS_PRATT)
			y = SM_Algorithm::Knuth_Morris_Pratt(key, patt.length(), list, table.s_height);

		if (!y.empty()) {
			for (int j = 0; j < y.size(); ++j) {
				POS place(i + 1, y[j] + 1, TOP_DOWN);
				ans.push_back(place);
			}
		}

	}
	return ans;
}


char* convert(string patt) {
	if (patt.empty())
		return nullptr;
	int length = patt.length();
	char* ans = new char[length];
	for (auto i = 0; i < length; ++i) {
		ans[i] = patt.at(i);
	}
	return ans;
}
