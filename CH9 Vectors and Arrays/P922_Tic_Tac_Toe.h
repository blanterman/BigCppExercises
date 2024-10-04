#include "ccc_win.h"
#include "P922_Board.h"


class P922_Tic_Tac_Toe
{
public:
	P922_Tic_Tac_Toe();
	void new_board();
	void draw_board();
	void take_turn(int player);
	bool check_for_win(int& winner);
	P922_Board get_board() const;
private:
	P922_Board gameBoard;
};