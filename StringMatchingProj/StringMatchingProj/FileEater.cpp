#include "FileEater.h"
#include "Board.h"


void Data::Load2DBoard()
{
	ifstream f;
	f.open("input.txt");
	//Board BOARD;
	if (!f.is_open())
		throw "error";
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
}