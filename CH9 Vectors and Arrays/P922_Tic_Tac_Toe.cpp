#include "P922_Tic_Tac_Toe.h"
#include <string>

using namespace std;

P922_Tic_Tac_Toe::P922_Tic_Tac_Toe()
{
	P922_Board gameBoard;
}

void P922_Tic_Tac_Toe::new_board()
{
	P922_Board newBoard;
	gameBoard = newBoard;
}

void draw_x(double x, double y)
{
	Point p1(x - .45, y + .45);
	Point p2 = p1;
	p2.move(0.9, -0.9);
	Line l1(p1, p2);
	
	Point p3(x - .45, y - .45);
	Point p4 = p3;
	p4.move(0.9, 0.9);
	Line l2(p3, p4);

	cwin << l1 << l2;

}

void draw_o(double x, double y)
{
	Circle c1(Point(x, y), 0.45);

	cwin << c1;

}

void place_marks(P922_Board GB)
{
	int rows = 0;
	int cols = 0;
	GB.get_RC(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (GB.get_move(i, j) == 'X')
			{
				draw_x(i + 0.5, -j - 0.5);
			}
			if (GB.get_move(i, j) == 'O')
			{
				draw_o(i + 0.5, -j - 0.5);
			}
		}
	}
}

void P922_Tic_Tac_Toe::draw_board()
{
	Point p1(1,0);
	Point p2 = p1;
	p2.move(0,-3);
	Line l1(p1, p2);
	Line l2 = l1;
	l2.move(1,0);
	Point p3 = p1;
	p3.move(-1,-1);
	Point p4 = p3;
	p4.move(3,0);
	Line l3(p3, p4);
	Line l4 = l3;
	l4.move(0, -1);
	cwin.clear();
	cwin.coord(-.2,.2,3.2,-3.2);
	cwin << l1 << l2 << l3 << l4;
	place_marks(gameBoard);
	
}

void P922_Tic_Tac_Toe::take_turn(int player)
{
	bool valid = false;
	int row = 0;
	int col = 0;
	if (player == 1)
	{
		while (!valid)
		{
			Point p1 = cwin.get_mouse("Player 1, please select where to place a O");
			row = (int)p1.get_x();
			col = (int)-p1.get_y();
			if (gameBoard.available(row, col))
			{
				gameBoard.insert_move(row, col, 'O');
				valid = true;
			}
		}
	}
	if (player == 2)
	{
		while (!valid)
		{
			Point p1 = cwin.get_mouse("Player 2, please select where to place a X");
			row = (int)p1.get_x();
			col = (int)-p1.get_y();
			if (gameBoard.available(row, col))
			{
				gameBoard.insert_move(row, col, 'X');
				valid = true;
			}
		}
	}
}

bool P922_Tic_Tac_Toe::check_for_win(int& player)
{
	int rows = 0;
	int cols = 0;
	char winningToken;
	bool winner = false;
	gameBoard.get_RC(rows, cols);
	//cases 1 - 3 vertical wins
	for (int i = 0; i < rows; i++)
	{
		if (gameBoard.get_move(i, 0) == gameBoard.get_move(i, 1) &&
			gameBoard.get_move(i, 1) == gameBoard.get_move(i, 2))
		{
			winningToken = gameBoard.get_move(i,0);
			winner = true;
		}
	}
	//cases 4 - 6 horizontal wins
	for (int i = 0; i < cols; i++)
	{
		if (gameBoard.get_move(0, i) == gameBoard.get_move(1, i) &&
			gameBoard.get_move(1, i) == gameBoard.get_move(2, i))
		{
			winningToken = gameBoard.get_move(0,i);
			winner = true;
		}
	}
	if (gameBoard.get_move(0, 0) == gameBoard.get_move(1, 1) &&
		gameBoard.get_move(1, 1) == gameBoard.get_move(2, 2))
	{
		winningToken = gameBoard.get_move(0,0);
		winner = true;
	}
	if (gameBoard.get_move(0, 2) == gameBoard.get_move(1, 1) &&
		gameBoard.get_move(1, 1) == gameBoard.get_move(2, 0))
	{
		winningToken = gameBoard.get_move(1,1);
		winner = true;
	}
	if (winner)
	{
		if(winningToken == 'O')
			player = 1;
		if(winningToken == 'X')
			player = 2;
	}
	return winner;
	
}

P922_Board P922_Tic_Tac_Toe::get_board() const
{
	return gameBoard;
}


