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

}
Board::~Board() {
	for (int i = 0; i < s_height; ++i)
		delete[]s_board[i];

	delete[]s_board;
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