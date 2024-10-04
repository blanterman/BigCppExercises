#include "P922_Board.h"

P922_Board::P922_Board()
	:boardSize(0)
{
	char a = 'a';
	for(int i = 0; i < NUMROWS; i++)
	{
		for(int j = 0; j < NUMCOLS; j++)
		{
			board[i][j] = a;
			a++;
		}
	}
}

void P922_Board::insert_move(int row, int col, char xo)
{
	board[row][col] = xo;
	boardSize++;
}

int P922_Board::get_size() const
{
	return boardSize;
}

void P922_Board::get_RC(int& rows, int& cols)
{
	rows = NUMROWS;
	cols = NUMCOLS;
}

char P922_Board::get_move(int row, int col) const
{
	return board[row][col];
}

bool P922_Board::full() const
{
	return boardSize == (NUMROWS * NUMCOLS);
}

bool P922_Board::available(int row, int col) const
{
	return board[row][col] != 'X' && board[row][col] != 'O';
}