#include "Board.h"

Board::Board() {
	s_height = s_width = 0;
	s_board = nullptr;
}
Board::Board(int height, int width) {
	s_height = height;
	s_width = width;
	s_board = new char*[s_height];
	for (int i = 0; i < s_height; ++i)
		s_board[i] = new char[s_width];

}
Board::~Board() {
	for (int i = 0; i < s_height; ++i)
		delete[]s_board[i];

	delete[]s_board;
}
