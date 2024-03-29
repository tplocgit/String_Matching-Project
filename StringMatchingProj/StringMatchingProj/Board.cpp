#include "Board.h"

void Board::printBoard() {
	for (int i = 0; i < s_height; i++) {
		for (int j = 0; j < s_width; j++)
			cout << (*this)[i][j] << " ";
		cout << endl;
	}
}

Board::Board() {
	s_height = s_width = 0;
	s_board = nullptr;
}
Board::Board(int height, int width) {
	s_height = height;
	s_width = width;
	s_board = new char* [s_height];
	for (int i = 0; i < s_height; ++i)
		s_board[i] = new char[s_width];
	//nh�p 
	for (int i = 0; i < s_height; ++i)
		for (int j = 0; j < s_width; ++j) {
			s_board[i][j] = i;
		}
}

Board::Board(const Board& obj) {
	this->s_height = obj.s_height;
	this->s_width = obj.s_width;
	s_board = new char* [this->s_height];
	for (int i = 0; i < this->s_height; ++i)
		s_board[i] = new char[this->s_width];

	for (int i = 0; i < obj.s_height; i++)
		for (int j = 0; j < obj.s_width; j++)
			this->s_board[i][j] = obj.s_board[i][j];
}

Board::~Board() {
	for (int i = 0; i < s_height; ++i)
		delete[] s_board[i];

	delete[] s_board;
}
//-----------------------------------------------------

char* Board::getRow(int row) {
	if (row < 0 || row >= this->s_height)
		return nullptr;
	char* ans = new char[this->s_width];
	for (int i = 0; i < this->s_width; ++i)
		ans[i] = this->s_board[row][i];
	return ans;
}
char* Board::getCol(int col) {
	if (col < 0 || col >= this->s_width)
		return nullptr;
	char* ans = new char[s_height];

	for (int count = 0; count < s_height; ++count) {
		ans[count] = s_board[count][col];
	}
	return ans;
}
void Board::printCol(int col) {
	for (int count = 0; count < s_height; ++count) {
		cout << char(s_board[count][col]) << " ";
	}
}

void Board::printRow(int row) {
	for (int count = 0; count < s_width; ++count)
		cout << char(s_board[row][count]) << " ";
}

char Board::random(char start, char end) {
	char result;
	result = start + rand() % (end - start + 1);
	return result;
}

void Board::GenerateRandomData() {
	for (int i = 0; i < s_height; i++)
		for (int j = 0; j < s_width; j++)
			(*this)[i][j] = random('A', 'Z');
}

char* Board::operator[](int index) {
	return s_board[index];
}
