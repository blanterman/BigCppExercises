#include "ccc_win.h"

const int NUMROWS = 3;
const int NUMCOLS = 3;

class P922_Board
{
public:
	P922_Board();
	void insert_move(int row, int col, char xo);
	int get_size() const;
	void get_RC(int& rows, int& cols);
	char get_move(int row, int col) const;
	bool full() const;
	bool available(int row, int col) const;
private:
	char board[NUMROWS][NUMCOLS];
	int boardSize;
};