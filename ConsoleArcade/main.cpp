#include <iostream>
#include <string>
#include <ctime>
#include <stdio.h>

#include "colors.h"
#include "functions.h"

class nim {
public:
	const char* colors[2] = { dye::red, dye::blue };
	int turn;
	int value;

	virtual int bot_turn() = 0;
	virtual void play() {}

	nim() {
		turn = 0;
		value = 0;
	}
	~nim() {
		delete this;
	}

};

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
					std::cout << dye::bright_black << i * 3 + j + 1;
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
		std::cout
			<< "Quick who to:" << std::endl
			<< "- Choose number beetwen 1 - 9 to select field" << std::endl
			<< "- You can't select a taken field" << std::endl
			<< "- If you place 3 of your symbols (X, O) in a column, row or diagonal, you win!" << std::endl;
		if (bot) {
			std::cout << "- Bot you play with is a tough opponent ;)" << std::endl;
		}

		int pos;
		while (!is_winner() && !is_draw())
		{
			display_board();
			std::cout << colors[turn % 2] << "Player " << players[turn % 2] << "\'s " << dye::reset << "turn: " << dye::bright_green;
			if (bot && turn % 2 == 1)
			{
				pos = bot_turn();
				std::cout << pos << dye::reset << std::endl << std::endl;
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
						if (pos < 1 || pos > 9) {
							std::cout << dye::red << "ERR: " << dye::bold << "Invalid input" << std::endl << dye::reset;
							continue;
						}
					}
					catch (std::exception e)
					{
						std::cout << dye::red << "ERR: " << dye::bold << "Invalid input" << std::endl << dye::reset;
						continue;
					}
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
				<< dye::yellow << dye::bold << "Game Over!" << std::endl
				<< colors[turn % 2] << "Player " << players[turn % 2] << dye::reset << dye::bold << " wins!" << dye::reset << std::endl;
		}
		else
		{
			std::cout << std::endl
				<< dye::yellow << dye::bold << "Draw!" << dye::reset << std::endl;
		}
	}

};

class game_2048 {

private:
	int board[4][4];
	int score;
	int colors[11] = { 208, 172, 136, 100, 64, 28, 29, 30, 31, 32, 33 };
	int check()
	{
		int empty = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (board[i][j] == 11)
					return 1;
				if (board[i][j] == 0)
					empty++;
			}
		}
		if (empty == 0)
			return -1;
		return 0;
	}
	void slide_board(int direction)
	{
		int temp[4][4];
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				temp[i][j] = board[i][j];

		std::cout << "Score: " << dye::bright_magenta << score << dye::reset << " | ";
		if (direction == 0)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (board[i][j] != 0)
					{
						for (int k = i - 1; k >= 0; k--)
						{
							if (temp[k][j] == 0)
							{
								temp[k][j] = temp[k + 1][j];
								temp[k + 1][j] = 0;
							}
							else if (temp[k][j] == temp[k + 1][j])
							{
								std::cout << dye::bright_green << "+" << pow(2, temp[k][j]) << " " << dye::reset;
								score += pow(2, temp[k][j]);
								temp[k][j] += 1;
								temp[k + 1][j] = 0;
							}
						}
					}
				}
			}
		}
		else if (direction == 1)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (board[i][j] != 0)
					{
						for (int k = j - 1; k >= 0; k--)
						{
							if (temp[i][k] == 0)
							{
								temp[i][k] = temp[i][k + 1];
								temp[i][k + 1] = 0;
							}
							else if (temp[i][k] == temp[i][k + 1])
							{
								std::cout << dye::bright_green << "+" << pow(2, temp[i][k]) << " " << dye::reset;
								score += pow(2, temp[i][k]);
								temp[i][k + 1] = 0;
								temp[i][k] += 1;
							}
						}
					}
				}
			}
		}
		else if (direction == 2)
		{
			for (int i = 3; i >= 0; i--)
			{
				for (int j = 0; j < 4; j++)
				{
					if (board[i][j] != 0)
					{
						for (int k = i + 1; k < 4; k++)
						{
							if (temp[k][j] == 0)
							{
								temp[k][j] = temp[k - 1][j];
								temp[k - 1][j] = 0;
							}
							else if (temp[k][j] == temp[k - 1][j])
							{
								std::cout << dye::bright_green << "+" << pow(2, temp[k][j]) << " " << dye::reset;
								score += pow(2, temp[k][j]);
								temp[k][j] += 1;
								temp[k - 1][j] = 0;
							}
						}
					}
				}
			}
		}
		else if (direction == 3)
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 3; j >= 0; j--)
				{
					if (board[i][j] != 0)
					{
						for (int k = j + 1; k < 4; k++)
						{
							if (temp[i][k] == 0)
							{
								temp[i][k] = temp[i][k - 1];
								temp[i][k - 1] = 0;
							}
							else if (temp[i][k] == temp[i][k - 1])
							{
								std::cout << dye::bright_green << "+" << pow(2, temp[i][k]) << " " << dye::reset;
								score += pow(2, temp[i][k]);
								temp[i][k] += 1;
								temp[i][k - 1] = 0;
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				board[i][j] = temp[i][j];
		std::cout << std::endl;
	}
	void display_board()
	{
		for (int i = 0; i < 4; i++)
		{
			std::cout << repeat("+----", 4) << "+";
			for (int j = 0; j < 2; j++)
			{
				std::cout << std::endl
					<< "|";
				for (int l = 0; l < 4; l++)
				{
					std::string value = std::to_string(pow(2, board[i][l]));
					for (int x = (int)value.size() - 1; x < 4; x++)
						value += ' ';
					dye::fg_custom(colors[board[i][l]]);

					if (board[i][l] == 0 || value == "0")
						std::cout << "   ";
					else
						std::cout << " " << value[2 * j] << value[2 * j + 1];
					std::cout << dye::reset << " |";
				}
			}
			std::cout << std::endl;
		}
		std::cout << repeat("+----", 4) << "+" << std::endl;
	}
	void add_number()
	{
		int empty = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (board[i][j] == 0)
					empty++;
			}
		}
		if (empty == 0)
			return;
		int pos = rand() % empty;
		int count = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (board[i][j] == 0)
				{
					if (count == pos)
					{
						board[i][j] = 1;
						return;
					}
					count++;
				}
			}
		}
	}

public:
	game_2048()
	{
		score = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				board[i][j] = 0;
			}
		}
	}
	~game_2048() {}

	void play()
	{
		std::cout
			<< "Quick who to:" << std::endl
			<< "- Choose direction to slide board: w (up), a (left), s (down), d (right)" << std::endl
			<< "- Tiles with the same number merge into one when they touch" << std::endl
			<< "- If you get one tile with 2048 you win!" << std::endl;

		add_number();
		int direction = -1;
		while (check() == 0)
		{
			add_number();
			display_board();
			std::cout << "Enter a direction (w, a, s, d): " << dye::bright_green;
			do
			{
				std::string input;
				std::cin >> input;
				std::cout << dye::reset << std::endl;
				if (input == "w")
					direction = 0;
				else if (input == "a")
					direction = 1;
				else if (input == "s")
					direction = 2;
				else if (input == "d")
					direction = 3;
				else
				{
					std::cout << dye::red << "ERR: " << dye::bold << "Invalid input" << std::endl << dye::reset;
					continue;
				}
			} while (direction < 0 || direction > 3);
			slide_board(direction);
		}

	}
};

class game_subtraction : private nim {
};

class game_21 : private nim
{
private:
	int bot_turn() {
		return 1;
	}

public:
	game_21() {
		turn = 0;
		value = 20;
	}
	~game_21() {}

	void play(bool bot) {
		std::cout
			<< "Quick who to:" << std::endl
			<< "- Choose number beetwen 1 - 3" << std::endl
			<< "- When the number reaches zero, the last player wins" << std::endl;
		if (bot) {
			std::cout << "- Bot you play with is a tough opponent ;)" << std::endl;
		}

		int pos;
		while (value > 0)
		{
			std::cout << colors[turn % 2] << "Player " << turn % 2 << "\'s " << dye::reset << "turn: " << dye::bright_green;
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
						if (pos < 1 || pos > 3) {
							std::cout << dye::red << "ERR: " << dye::bold << "Invalid input" << std::endl << dye::reset;
							continue;
						}
					}
					catch (std::exception e)
					{
						std::cout << dye::red << "ERR: " << dye::bold << "Invalid input" << std::endl << dye::reset;
						continue;
					}
				} while (pos < 1 || pos > 3);
			}
			value -= pos;
			turn++;
		}
		std::cout << "Game over!" << std::endl;
	}
};

int main()
{	
	std::cout << "Which game do you want to play?" << std::endl
		<< dye::bright_magenta << "1. " << dye::reset << "Tic Tac Toe" << std::endl
		<< dye::bright_magenta << "2. " << dye::reset << "2048: " << std::endl
		<< dye::bright_magenta << "3. " << dye::reset << "Choose 20: " << std::endl
		<< dye::bright_magenta << "4. " << dye::reset << "Choose 100: " << std::endl
		<< dye::bright_green;

	int game;
	std::string bot;
	std::string input;

	std::cin >> input;
	std::cout << dye::reset;

	try
	{
		game = std::stoi(input);
	}
	catch (std::exception e)
	{
		std::cout << dye::bold << dye::red << "ERR: Invalid input" << dye::reset << std::endl;
		return 1;
	}
	switch (game)
	{
	case 1:
	{
		std::cout << "Choose: Tic Tac Toe" << std::endl
			<< "Do you want to play against a bot?" << dye::bright_blue << " (y/n): " << dye::bright_green << std::flush;
		std::cin >> bot;
		std::cout << dye::reset << std::endl;
		tic_tac_toe game;
		if (bot == "y")
			game.play(true);
		else
			game.play(false);
		break;
	}
	case 2:
	{
		game_2048 game;
		game.play();
		break;
	}
	case 3:
	{
		game_21 game;
		game.play(false);
		break;
	}
	default:
		std::cout << dye::bold << dye::red << "ERR: Invalid input" << dye::reset << std::endl;
	}
}

/*
games:
	tictactoe
	2048
	choose20

todo:
	choose100
	heap
	marienbad
	dice(31)
	boxslice
	Jianshizi
	rescuequeen
	minesweeper
	wordle
	connect4

  maybe:
	chess
	checkers
	wordpuzzle
	sudoku
	battleship
	hangman
	tetris
	pacman
	snake
*/