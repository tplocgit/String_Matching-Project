#include "FileEater.h"
#include "Board.h"
#include "CrossWord.h"


bool Data::Load2DBoard(string fileName)
{
	ifstream f;
	f.open(fileName);
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

void Data::cumOutput(vector<vector<POS>> list, vector<string> nameList)
{
	ofstream f;
	if (list.empty())
		throw "Error: Empty input";
	f.open("output.txt", ios::out);
	if (!f.is_open())
		throw "Error: ???????????";
	int count = 0;
	for (auto i = 0; i < list.size(); ++i) 
		if (!list[i].empty())
			++count;
	
	f << count << '\n';
	for (auto i = 0; i < list.size(); ++i) {
		if (list[i].empty())
			f << nameList[i] << " (0,0) NF" << endl;
		else {
			for (auto j = 0; j < list[i].size(); ++j) {
				f << nameList[i] << " (" << list[i][j].s_x << "," << list[i][j].s_y << ") " << list[i][j].getStat() << endl;
			}
		}
	}
	
	f.close();
}