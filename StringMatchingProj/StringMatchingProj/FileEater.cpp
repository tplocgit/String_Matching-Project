#include "FileEater.h"
#include "Board.h"
#include "CrossWord.h"


bool Data::Load2DBoard()
{
	ifstream f;
	f.open("input50x50.txt");
	//Board BOARD;
	if (!f.is_open())
		return 0;
	f >> Matrix.s_width >> Matrix.s_height;
	Matrix.s_board = new char* [Matrix.s_height];
	for (int i = 0; i < Matrix.s_height; ++i)
		Matrix.s_board[i] = new char[Matrix.s_width];
	for (int i = 0; i < Matrix.s_height; i++)
	{
		for (int j = 0; j < Matrix.s_width; j++)
		{
			f >> (Matrix[i][j]);
		}
	}

	f.ignore();
	while (!f.eof())
	{
		string temp;
		getline(f, temp, '\n');
		if (temp == "#")
			break;
		else pattern.push_back(temp);
	}
	/*
	for (int i = 0; i < Matrix.s_height; i++)
	{
		for (int j = 0; j < Matrix.s_width; j++)
		{
			cout << Matrix[i][j] << "\t";
		}
		cout << endl;
	}
	*/
	f.close();
	return 1;
}

void Data::cumOutput()
{
	ofstream f;
	f.open("output.txt", ios::out);
	if (!f.is_open())
		throw "????????????";
	Data p;
	if (p.Load2DBoard())
		cout << "Input file was successfully loaded\n";
	else
		cout << "Error: Input file is inaccessible!!!!\n";

	for (int i = 0; i < p.pattern.size(); ++i) {
		vector<POS> ans = startSearch(p.pattern[i], p.Matrix, RABIN_KARP);
		if (ans.empty()) {
			cout << "Pattern " << i + 1 << ": 0, 0\n";
		}
		else {
			for (int j = 0; j < ans.size(); ++j) {
				f << p.pattern.at(j) << "(" << ans.at(j).s_y << "," << ans.at(j).s_x << ") " << ans.at(j).getStat() << endl;
			}
		}
		
	}
	f.close();
}