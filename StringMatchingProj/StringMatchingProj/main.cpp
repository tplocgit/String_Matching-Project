#include"CrossWord.h"
#include"GUI.h"
#include"FileEater.h"



int main() {
	// For testing
	char* t, * p;
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

	vector<int> res = SM_Algorithm::Kabin_Karp(p, m, t, n);

	for (auto it = res.begin(); it != res.end(); ++it) {
		cout << "Found pattern at: " << *it << endl;
		for (int i = 0; i < m; ++i)
			cout << t[*it + i];
		cout << endl;
	}

	cout << endl;

	delete t, p;
	//-------------------------------------------------------------
	
	
	
	
	
	system("pause");
	return 0;
}