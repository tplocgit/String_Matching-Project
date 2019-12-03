#include "Board.h"
#include"CrossWord.h"
#include"FileEater.h"
#include <chrono> 
using namespace std::chrono;
int main() {
	// For testing
	/*char* t, * p;
	int m, n;
	cout << "TEXT:\n";
	cout << "Length: ";
	cin >> n;
	cout << "Input: ";
	t = new char[n];
	for (int i = 0; i < n; i++)
		cin >> t[i];

	cout << "PATTERN:\n";
	cout << "Length: ";
	cin >> m;
	cout << "Input: ";
	p = new char[m];
	for (int i = 0; i < m; ++i)
		cin >> p[i];

	vector<int> res = SM_Algorithm::Rabin_Karp(p, m, t, n);

	for (auto it = res.begin(); it != res.end(); ++it) {
		cout << "Found pattern at: " << *it << endl;
		for (int i = 0; i < m; ++i)
			cout << t[*it + i];
		cout << endl;
	}

	cout << endl;

	delete t, p;*/
	////-------------------------------------------------------------
	string name;
	cout << "Enter input file name:\t";
	cin >> name;
	Data p;
	if (p.Load2DBoard(name))
		cout << "Input file was successfully loaded\n";
	else {
		cout << "Error: Input file is inaccessible!!!!\n";
		system("pause");
		return 0;
	}
	name.erase(name.begin(), name.begin() + 5);
	string outputName = name;
	for (int run = 0; run < 3; ++run) {
		vector<vector<POS>> ans;
		searchAl tp;
		if (run == 0)
			tp = BRUTE_FORCE;
		else if (run == 1)
			tp = RABIN_KARP;
		else
			tp = KNUTH_MORRIS_PRATT;
		auto start = high_resolution_clock::now();///////////////////////////////

		for (int i = 0; i < p.pattern.size(); ++i) {
			vector<POS> searchPatt = startSearch(p.pattern[i], p.Matrix, tp);
			ans.push_back(searchPatt);
		}
		auto stop = high_resolution_clock::now();//////////////////////
		auto duration = duration_cast<microseconds>(stop - start);
		string AlName = SM_Algorithm::Algo_String_Name(tp);
		cout << "\n" << AlName << " completed in " << duration.count() << " microseconds!!!\n";
		//----------Output-----------------
		try {
			p.cumOutput(ans, p.pattern, AlName + "_output_" + outputName);
		}
		catch (string k) {
			cout << "\nError: " << k << "- Can't output result file\n";
		}
	}
	cout << "==> All task completed\n";
	system("pause");
	return 1;
}