#include <iostream>
#include <string>
#include <ctime>

#include "colors.h"
#include "functions.h"

class tic_tac_toe
{
private:
	char board[3][3];
	const char* players = "XO";
	const char* colors[2] = { dye::red, dye::blue };
	int turn;
	bool is_winner()
	{
		for (int i = 0; i < 3; i++)
		{
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			{
				return true;
			}
			if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
			{
				return true;
			}
		}
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		{
			return true;
		}
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
		{
			return true;
		}
		return false;
	}
	bool is_draw()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == ' ')
				{
					return false;
				}
			}
		}
		return true;
	}
	bool mark_board(int pos)
	{
		int row = (pos - 1) / 3;
		int col = (pos - 1) % 3;
		if (board[row][col] == ' ')
		{
			board[row][col] = players[turn % 2];
			return true;
		}
		std::cout << "\033[91mERR: \033[1mPosition already taken\033[0m\n";
		return false;
	}
	void display_board()
	{
		for (int i = 0; i < 3; i++)
		{
			std::cout << repeat("+---", 3) << "+" << std::endl;
			for (int j = 0; j < 3; j++)
			{
				std::cout << "| ";
				if (board[i][j] == ' ')
					std::cout << dye::black << i * 3 + j + 1;
				else
					std::cout << colors[(int)(board[i][j] == 'O')] << board[i][j];
				std::cout << dye::reset << " ";
			}
			std::cout << "|" << std::endl;
		}
		std::cout << repeat("+---", 3) << "+" << std::endl;
	}

	int bot_turn()
	{
		srand((int)time(NULL));
		int pos = 1;

		if (board[0][0] == ' ' && board[0][1] != ' ' && board[0][2] != ' ' && board[0][1] == board[0][2])
			return 1;
		if (board[1][0] == ' ' && board[1][1] != ' ' && board[1][2] != ' ' && board[1][1] == board[1][2])
			return 4;
		if (board[2][0] == ' ' && board[2][1] != ' ' && board[2][2] != ' ' && board[2][1] == board[2][2])
			return 7;

		if (board[0][0] != ' ' && board[0][1] == ' ' && board[0][2] != ' ' && board[0][0] == board[0][2])
			return 2;
		if (board[1][0] != ' ' && board[1][1] == ' ' && board[1][2] != ' ' && board[1][0] == board[1][2])
			return 5;
		if (board[2][0] != ' ' && board[2][1] == ' ' && board[2][2] != ' ' && board[2][0] == board[2][2])
			return 8;

		if (board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] == ' ' && board[0][0] == board[0][1])
			return 3;
		if (board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] == ' ' && board[1][0] == board[1][1])
			return 6;
		if (board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] == ' ' && board[2][0] == board[2][1])
			return 9;

		if (board[0][0] == ' ' && board[1][0] != ' ' && board[2][0] != ' ' && board[1][0] == board[2][0])
			return 1;
		if (board[0][1] == ' ' && board[1][1] != ' ' && board[2][1] != ' ' && board[1][1] == board[2][1])
			return 2;
		if (board[0][2] == ' ' && board[1][2] != ' ' && board[2][2] != ' ' && board[1][2] == board[2][2])
			return 3;

		if (board[0][0] != ' ' && board[1][0] == ' ' && board[2][0] != ' ' && board[0][0] == board[2][0])
			return 4;
		if (board[0][1] != ' ' && board[1][1] == ' ' && board[2][1] != ' ' && board[0][1] == board[2][1])
			return 5;
		if (board[0][2] != ' ' && board[1][2] == ' ' && board[2][2] != ' ' && board[0][2] == board[2][2])
			return 6;

		if (board[0][0] != ' ' && board[1][0] != ' ' && board[2][0] == ' ' && board[0][0] == board[1][0])
			return 7;
		if (board[0][1] != ' ' && board[1][1] != ' ' && board[2][1] == ' ' && board[0][1] == board[1][1])
			return 8;
		if (board[0][2] != ' ' && board[1][2] != ' ' && board[2][2] == ' ' && board[0][2] == board[1][2])
			return 9;

		if ((board[0][0] != ' ' && board[1][1] == ' ' && board[2][2] != ' ' && board[0][0] == board[2][2]) ||
			(board[0][2] != ' ' && board[1][1] == ' ' && board[2][0] != ' ' && board[0][2] == board[2][0]))
			return 5;
		if (board[0][0] != ' ' && board[1][1] != ' ' && board[2][2] == ' ' && board[0][0] == board[1][1])
			return 9;
		if (board[0][2] != ' ' && board[1][1] != ' ' && board[2][0] == ' ' && board[0][2] == board[1][1])
			return 7;
		if (board[0][0] == ' ' && board[1][1] != ' ' && board[2][2] != ' ' && board[1][1] == board[2][2])
			return 1;
		if (board[0][2] == ' ' && board[1][1] != ' ' && board[2][0] != ' ' && board[1][1] == board[2][0])
			return 3;

		if ((board[0][0] == 'X' || board[0][2] == 'X' || board[2][2] == 'X' || board[2][0] == 'X') && turn == 1)
		{
			return 5;
		}

		if (board[0][0] != ' ' && board[1][1] != ' ' && board[2][2] != ' ' && board[0][0] == board[2][2])
			if (board[0][2] == ' ' && board[2][0] == ' ')
				return rand() % 2 * 4 + 3;
			else if (board[0][2] == ' ')
				return 3;
			else if (board[2][0] == ' ')
				return 7;
		if (board[0][2] != ' ' && board[1][1] != ' ' && board[2][0] != ' ' && board[0][2] == board[2][0])
			if (board[0][0] == ' ' && board[2][2] == ' ')
				return rand() % 2 * 8 + 1;
			else if (board[0][0] == ' ')
				return 1;
			else if (board[2][2] == ' ')
				return 9;

		while (board[(pos - 1) / 3][(pos - 1) % 3] != ' ')
		{
			pos = rand() % 9 + 1;
		}

		return pos;
	}

public:
	tic_tac_toe()
	{
		turn = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				board[i][j] = ' ';
			}
		}
	}
	~tic_tac_toe() {}

	void play(bool bot)
	{
		int pos;
		while (!is_winner() && !is_draw())
		{
			display_board();
			std::cout << colors[turn % 2] << "Player " << players[turn % 2] << "\'s " << dye::reset << "turn: " << dye::bright_green;
			if (bot && turn % 2 == 1)
			{
				pos = bot_turn();
				std::cout << pos << dye::reset << std::endl;
			}
			else
			{
				do
				{
					std::string input;
					std::cin >> input;
					std::cout << dye::reset << std::endl;
					try
					{
						pos = std::stoi(input);
					}
					catch (std::exception e)
					{
						std::cout << "\033[91mERR: \033[1mInvalid input\033[0m\n";
						continue;
					}

					pos = std::stoi(input.substr(0, 1));
				} while (pos < 1 || pos > 9);
			}
			if (mark_board(pos))
				turn++;
		}
		display_board();
		if (is_winner())
		{
			turn++;
			std::cout << std::endl
				<< colors[turn % 2] << "Player " << players[turn % 2] << dye::reset << dye::bold << " wins!" << dye::reset << std::endl;
		}
		else
		{
			std::cout << std::endl
				<< dye::yellow << dye::bold << "Draw!" << dye::reset << std::endl;
		}
	}

};
