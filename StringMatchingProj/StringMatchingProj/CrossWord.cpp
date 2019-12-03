#include "CrossWord.h"

vector<POS> startSearch(string patt, Board table, searchAl p) {
	//---Ngang---

	vector<POS> ans;
	char* key = nullptr;
	key = convert(patt);
	if (key == nullptr)
		return {};

	vector<int> x, y;

	for (auto i = 0; i < table.s_height; ++i) {
		char* list = nullptr;
		list = table.getRow(i);

		if (list == nullptr)
			break;
		//vector <int> pos_y;
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
		if (list != nullptr)
			delete list;
	}


	//---Dọc-----
	for (auto i = 0; i < table.s_width; ++i) {
		char* list = nullptr;
		list = table.getCol(i);
		if (list == nullptr)
			break;
		//vector <int> pos_x;
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

		if (list != nullptr)
			delete list;
	}
	/*if (x.empty() && y.empty()) {
		POS place;
		ans.push_back(place);
	}*/
	delete[]key;
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
