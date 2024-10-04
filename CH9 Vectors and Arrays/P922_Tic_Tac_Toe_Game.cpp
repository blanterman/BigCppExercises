#include "ccc_win.h"
#include "P922_Tic_Tac_Toe.h"

int ccc_win_main()
{
	int player = 1;
	int winPlayer = 0;
	bool cont = true;
	bool fullBoard = false;
	bool winner = false;
	P922_Tic_Tac_Toe game;
	game.draw_board();

	while (cont)
	{
		game.take_turn(player);
		game.draw_board();

		fullBoard = game.get_board().full();
		winner = game.check_for_win(winPlayer);

		if (winner)
		{
			cont = false;
			string winnerString = to_string(static_cast<long long>(winPlayer));
			Message winMessage(Point (.1, .1), "Player " + winnerString + " wins!");
			cwin << winMessage;
		}

		if (fullBoard && !winner)
		{
			cont = false;
			Message catsGame(Point(0.1, 0.1), "Cat's Game!");
			cwin << catsGame;
		}

		player = player == 1 ? 2 : 1;
	}
	return 0;
}