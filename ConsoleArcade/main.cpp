#include <iostream>
#include <string>
#include <ctime>
#include <stdio.h>
#include <bitset>

#include "colors.h"
#include "functions.h"

class nim {
public:
	const char* colors[2] = { dye::red, dye::blue };
	int turn;
	int value;

	virtual void play() {}

	nim() {
		turn = 0;
		value = 0;
	}
	~nim() {
		delete this;
	}

	int nim_sum(int value) {
		return 0 ^ value;
	}
	int nim_sum(int* heaps, size_t heap_size) {
		int nim = 0;
		for (size_t i = 0; i < heap_size; i++)
		{
			nim = nim ^ heaps[i];
		}
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
		int pos = -1;
		while (!is_winner() && !is_draw())
		{
			display_board();
			if (bot && turn % 2 == 1)
			{
				std::cout << colors[turn % 2] << "Player " << players[turn % 2] << "\'s " << dye::reset << "turn: " << dye::bright_green;
				pos = bot_turn();
				std::cout << pos << dye::reset << std::endl << std::endl;
			}
			else
			{
				do
				{
					std::cout << colors[turn % 2] << "Player " << players[turn % 2] << "\'s " << dye::reset << "turn: " << dye::bright_green;
					std::string input;
					getline(std::cin, input);
					std::cout << dye::reset << std::endl;
					try
					{
						pos = std::stoi(input);
					}
					catch (std::exception e)
					{
						std::cout << dye::red << "ERR: " << dye::bold << "Invalid input" << std::endl << dye::reset;
						continue;
					}
					if (pos < 1 || pos > 9) {
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
				getline(std::cin, input);
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
private:
	int pos = 10;
	int goal = 100;
	int limit = 10;
	int when_bot = 1;
	int bot_turn() {
		srand((int)time(NULL));

		if (value > goal / 3) {
			return (limit - value % (limit + 1)) % limit + 1;
		}
		else
			return rand() % limit + 1;

	}
public:
	game_subtraction(int goal = 100, int limit = 10) {
		this->goal = goal;
		this->limit = limit;
		turn = 0;
		value = 0;
	}
	void play(bool bot, bool graphically) {
		std::string input;

		if (bot)
			std::cout << "Wanna start? " << dye::bright_blue << "(Y/n): " << dye::green;
		getline(std::cin, input);
		std::cout << dye::reset << std::endl;
		if (input == "n" || input == "N")
			when_bot = 0;

		while (value < goal)
		{
			std::cout << "Value: " << dye::bright_magenta;
			if (graphically)
				std::cout << repeat("#", goal - value) << std::endl;
			else
				std::cout << goal - value << std::endl;
			if (bot && turn % 2 == when_bot)
			{
				std::cout << colors[turn % 2] << "Player " << turn % 2 + 1 << "\'s " << dye::reset << "turn: " << dye::bright_green;
				pos = bot_turn();
				std::cout << pos << dye::reset << std::endl << std::endl;
			}
			else
			{
				do
				{
					std::cout << colors[turn % 2] << "Player " << turn % 2 + 1 << "\'s " << dye::reset << "turn: " << dye::bright_green;
					getline(std::cin, input);
					std::cout << dye::reset << std::endl;
					try
					{
						pos = std::stoi(input);
						if (pos < 1 || pos > limit) {
							std::cout << dye::red << "ERR: " << dye::bold << "Invalid input" << std::endl << dye::reset;
						}
					}
					catch (std::exception e)
					{
						std::cout << dye::red << "ERR: " << dye::bold << "Invalid input" << std::endl << dye::reset;
					}
				} while (pos < 1 || pos > limit);
			}
			value += pos;
			turn++;
		}
		std::cout << dye::yellow << dye::bold << "Game over!" << dye::bold_off << std::endl
			<< colors[(turn) % 2] << "Player " << (turn) % 2 + 1 << dye::reset << " win!" << std::endl
			<< colors[(turn + 1) % 2] << "Player " << (turn + 1) % 2 + 1 << dye::reset << " lose!";
	}
};

class game_heap : private nim {
private:

	int* heaps;
	int pos = 10;
	int when_bot = 0;
	int* bot_turn() {
		int res[2] = { 1, 1 };
		return res;
	}
public:
	game_heap(int heap_count = 2, int heap_size = 10, int heaps_offset = 3) {
		heaps = new int[heap_count];
		for (int i = 0; i < heap_count; i++)
			heaps[i] = heap_size + (rand() % (2 * heaps_offset)) - heaps_offset;

	}
	void play(bool bot, bool graphically = false) {

	}
};

class game_boxslice {
private:
	int box_width = 10;
	int box_height = 10;
	int turn = 0;
	const char* colors[2] = { dye::red, dye::blue };

	void slice_box(bool axis, int pos) {
		if (axis)
			box_height = pos;
		else
			box_width = pos;
	}
	void draw_box(bool graphically = false) {
		int height = 0;
		int width = 0;
		if (graphically) {
			std::cout << " \\ " << dye::bright_magenta;
			for (int width = 1; width <= box_height; width++)
				printf("%2d ", width);
			for (int height = 1; height <= box_width; height++) {
				printf("\n%s%2d%s:", dye::bright_magenta, height, dye::reset);
				if (height == 1)
				{
					std::cout << dye::bright_red << " # " << dye::reset;
					std::cout << repeat(" # ", box_height - 1);
				}
				else
					std::cout << repeat(" # ", box_height);
			}
			std::cout << dye::reset << std::endl;
		}
		else
			std::cout << "Box size is: " << dye::bright_magenta << box_width << dye::reset << "x" << dye::bright_magenta << box_height << dye::reset << std::endl;
	}

public:
	game_boxslice(int box_width, int box_height) {
		this->box_width = box_width;
		this->box_height = box_height;
		turn = 0;
	}

	void play(bool bot, bool graphically = false) {
		std::string input;
		bool axis = 0;
		int pos = 0;

		while (box_height != 1 || box_width != 1) {
			draw_box(graphically);

			std::cout << colors[turn % 2] << "Player " << turn % 2 + 1 << "\'s " << dye::reset << std::endl;
			std::cout << "Choose axis " << dye::bright_blue << "Horizontal (h), Vertical (v)" << dye::reset;
			do
			{
				std::cout << ": " << dye::green;
				getline(std::cin, input);
				std::cout << dye::reset;

				if (input != "h" && input != "H" && input != "v" && input != "V") {
					std::cout << dye::red << "ERR: " << dye::bold << "Invalid input" << std::endl << dye::reset;
					continue;
				}

				axis = input == "h" || input == "H";

				std::cout << "Choose position " << dye::bright_blue << "1-" << (axis ? box_height : box_width) << dye::reset;
				do {
					std::cout << ": " << dye::green;
					getline(std::cin, input);
					std::cout << dye::reset << std::endl;

					try
					{
						pos = std::stoi(input);
						if (pos < 1 || pos >(axis ? box_height : box_width)) {
							std::cout << dye::red << "ERR: " << dye::bold << "Invalid input" << std::endl << dye::reset;
							continue;
						}
					}
					catch (std::exception e)
					{
						std::cout << dye::red << "ERR: " << dye::bold << "Invalid input" << std::endl << dye::reset;
						continue;
					}
				} while (pos < 1 || pos >(axis ? box_height : box_width));
			} while (pos < 1 || pos >(axis ? box_height : box_width));

			slice_box(axis, pos);
			turn++;
		}
		draw_box(graphically);
		std::cout << dye::yellow << dye::bold << "Game over!" << dye::bold_off << std::endl
			<< colors[(turn + 1) % 2] << "Player " << (turn + 1) % 2 + 1 << dye::reset << " win!" << std::endl
			<< colors[(turn) % 2] << "Player " << (turn) % 2 + 1 << dye::reset << " lose!";
	}
};

class minesweeper {
private:
	bool*** board; // hidden/shown [0], empty/mine [1], empty/flag [2]
	const char* symbols = " #!?*";
	const char* colors[9] = { dye::reset, dye::bright_blue, dye::green, dye::bright_red, dye::blue, dye::red, dye::cyan, dye::magenta, dye::bright_black };
	int width = 10;
	int height = 10;
	int mines = 10;

	void generate_board() {
		board = new bool** [width];
		for (int i = 0; i < width; i++) {
			board[i] = new bool* [height];
			for (int j = 0; j < height; j++) {
				board[i][j] = new bool[3];
				for (int l = 0; l < 3; l++)
					board[i][j][l] = 0;
			}
		}

		for (int i = 0; i < mines; i++) {
			int x = rand() % width;
			int y = rand() % height;

			if (board[x][y][1] == 1) {
				i--;
				continue;
			}
			board[x][y][1] = 1;
		}
	}
	void display_board() {
		std::cout << dye::bright_magenta << "   ";
		for (int x = 0; x < width; x++)
			printf("%d ", x + 1);
		for (int y = 0; y < height; y++) {
			printf("\n%s%2d%s", dye::bright_magenta, y + 1, dye::reset);
			for (int x = 0; x < width; x++) {
				std::cout << " ";
				if (board[x][y][0]) {
					if (board[x][y][1]) {
						std::cout << dye::red << symbols[4] << dye::reset;
					}
					else
					{
						int mine_count = 0;
						for (int shift_x = -1; shift_x <= 1; shift_x++)
							for (int shift_y = -1; shift_y <= 1; shift_y++) {
								if (x + shift_x < 0 || x + shift_x >= width || y + shift_y < 0 || y + shift_y >= height)
									continue;
								if (board[x + shift_x][y + shift_y][1])
									mine_count++;
							}

						std::cout << colors[mine_count];
						if (mine_count > 0)
							std::cout << mine_count;
						else
							std::cout << symbols[0];
						std::cout << dye::reset;
					}
				}
				else
				{
					std::cout << symbols[1];
				}
			}
		}
		std::cout << std::endl;
	}

public:
	void play() {
		generate_board();
		display_board();
		/*for (int x = 0; x < width; x++) {
			for (int y = 0; y < height; y++) {
				if (!board[x][y][1])
					board[x][y][0] = 1;
			}
		}*/
		board[4][7][0] = 1;
		display_board();
		board[3][6][1] = 1;
		display_board();
		board[4][6][1] = 1;
		display_board();
		board[5][6][1] = 1;
		display_board();
		board[5][7][1] = 1;
		display_board();
		board[3][8][1] = 1;
		display_board();
		board[4][8][1] = 1;
		display_board();
		board[5][8][1] = 1;
		display_board();
		board[3][7][1] = 1;
		display_board();
		board[4][7][1] = 1;
		display_board();
	}
};

int main()
{
	const char* games[] = {
		"Tic Tac Toe (Bot)",
		"2048",
		"Subtraction (NIM, Bot)",
		"\033[90mHeaps (NIM) (WIP)\033[0m",
		"\033[90mDice31 (NIM) (WIP)\033[0m",
		"Box-slice",
		"Minesweeper"
	};
	int i, game;
	std::string bot, input, again;

	do {
		i = 1;
		std::cout << "Which game do you want to play?" << std::endl;
		for (const char*& game : games) {
			std::cout << dye::bright_magenta;
			printf("%2d.%s %s\n", i++, dye::reset, game);
		}

		std::cout << dye::bright_green;
		getline(std::cin, input);
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

		std::cout << "Choose: " << dye::bright_cyan << games[game - 1] << dye::reset << std::endl;
		switch (game)
		{
		case 1:
		{
			std::cout << "Do you want to play against a bot?" << dye::bright_blue << " (y/N): " << dye::bright_green << std::flush;
			getline(std::cin, bot);
			std::cout << dye::reset << std::endl;
			tic_tac_toe game;

			std::cout << std::endl
				<< "Quick who to:" << std::endl
				<< "- Choose number beetwen 1 - 9 to select field" << std::endl
				<< "- You can't select a taken field" << std::endl
				<< "- If you place 3 of your symbols (X, O) in a column, row or diagonal, you win!" << std::endl;
			if (bot == "y" || bot == "Y") {
				std::cout << "- Bot you play with is a tough opponent ;)" << std::endl;
			}

			game.play((bot == "y" || bot == "Y"));
			break;
		}
		case 2:
		{
			std::cout << std::endl
				<< "Quick who to:" << std::endl
				<< "- Choose direction to slide board: w (up), a (left), s (down), d (right)" << std::endl
				<< "- Tiles with the same number merge into one when they touch" << std::endl
				<< "- If you get one tile with 2048 you win!" << std::endl;

			game_2048 game;
			game.play();
			break;
		}
		case 3:
		{
			std::string temp;
			int goal = 100;
			int limit = 10;
			std::cout << "Choose starting number " << std::endl
				<< dye::bright_black << "(deafult: 100, at least 21)" << std::endl << dye::reset << std::flush;
			do {
				std::cout << ": " << dye::bright_green;
				getline(std::cin, temp);
				try { goal = std::stoi(temp); }
				catch (const std::exception&) {}
				if (goal < 21)
					std::cout << dye::red << "ERR: " << dye::bold << "Invalid input" << std::endl << dye::reset;
			} while (goal < 21);

			std::cout << dye::reset << std::endl
				<< "Set highest possible to choose number " << std::endl
				<< dye::bright_black << "(deafult: 10, at least 3, less then goal/4 (" << goal / 4 << ") )" << std::endl << dye::reset << std::flush;
			do {
				std::cout << ": " << dye::bright_green;
				getline(std::cin, temp);

				try { limit = std::stoi(temp); }
				catch (const std::exception&) {}

				if (limit < 3 || limit >= goal / 4)
					std::cout << dye::red << "ERR: " << dye::bold << "Invalid input" << std::endl << dye::reset;
			} while (limit < 3 || limit >= goal / 4);

			std::cout << dye::reset << std::endl
				<< "Do you want to play against a bot?" << dye::bright_blue << " (y/N): " << dye::bright_green << std::flush;
			getline(std::cin, bot);
			std::cout << dye::reset << std::endl;

			std::string graphically;
			std::cout << "Do you want to display game \"more\" graphically? " << std::endl
				<< dye::bright_black << "(not recommended with high numbers)" << std::endl
				<< dye::bright_blue << " (y/N): " << dye::bright_green << std::flush;
			getline(std::cin, graphically);
			std::cout << dye::reset << std::endl;


			std::cout << std::endl
				<< "Quick who to:" << std::endl
				<< "- Game starts at: " << dye::magenta << goal << dye::reset << std::endl
				<< "- Choose number beetwen "
				<< dye::magenta << 1 << dye::reset << " - "
				<< dye::magenta << limit << dye::reset << std::endl
				<< "- When the number reaches zero, the last player lose" << std::endl;

			if (bot == "y" || bot == "Y") {
				std::cout << "- Bot you play with is a tough opponent ;)" << std::endl;
			}
			game_subtraction game(goal, limit);
			game.play((bot == "y" || bot == "Y"), (graphically == "y" || graphically == "Y"));
			break;
		}
		case 4:
		{
			std::cout << "Ops! sorry the game is in progress, i'm busy of NIM right now" << std::endl;
			break;
			std::string temp;
			int heaps_count = 3;
			int heaps_size = 10;
			int heaps_offset = 3;
			std::cout << "Choose number of heaps " << std::endl
				<< dye::bright_black << "(deafult: 3, at least 2)" << std::endl << dye::reset << std::flush;
			do {
				std::cout << ": " << dye::bright_green;
				getline(std::cin, temp);
				try { heaps_count = std::stoi(temp); }
				catch (const std::exception&) {}
				if (heaps_count < 2)
					std::cout << dye::red << "ERR: " << dye::bold << "Invalid input" << std::endl << dye::reset;
			} while (heaps_count < 2);

			std::cout << dye::reset << std::endl
				<< "Choose starting number of each heap: " << std::endl
				<< dye::bright_black << "(deafult: 10, at least 3, up to 26)" << std::endl << dye::reset << std::flush;
			do {
				std::cout << ": " << dye::bright_green;
				getline(std::cin, temp);
				try { heaps_size = std::stoi(temp); }
				catch (const std::exception&) {}
				if (heaps_size < 3)
					std::cout << dye::red << "ERR: " << dye::bold << "Invalid input" << std::endl << dye::reset;
			} while (heaps_size < 3);

			std::cout << dye::reset << std::endl
				<< "Choose starting number of each heap: " << std::endl
				<< dye::bright_black << "(deafult: 10, at least 3)" << std::endl << dye::reset << std::flush;
			do {
				std::cout << ": " << dye::bright_green;
				getline(std::cin, temp);
				try { heaps_size = std::stoi(temp); }
				catch (const std::exception&) {}
				if (heaps_size < 1)
					std::cout << dye::red << "ERR: " << dye::bold << "Invalid input" << std::endl << dye::reset;
			} while (heaps_size < 1);

			std::cout << dye::reset << std::endl
				<< "Do you want to play against a bot?" << dye::bright_blue << " (y/N): " << dye::bright_green << std::flush;
			getline(std::cin, bot);
			std::cout << dye::reset << std::endl;

			std::string graphically;
			std::cout << dye::reset << std::endl
				<< "Do you want to display game \"more\" graphically? (not recommended with high numbers)" << dye::bright_blue << " (y/N): " << dye::bright_green << std::flush;
			getline(std::cin, graphically);
			std::cout << dye::reset << std::endl;


			std::cout << std::endl
				<< "Quick who to:" << std::endl
				<< "- Game has " << dye::magenta << heaps_count << dye::reset << "heaps, each for" << heaps_size << "+/-" << heaps_offset << std::endl
				<< "- You can choose a heap and take any number OR take same number from all heaps"
				<< "- When the number reaches zero in every heap, the last player lose" << std::endl;

			if (bot == "y" || bot == "Y") {
				std::cout << "- Bot you play with is a tough opponent ;)" << std::endl;
			}
			game_heap game(heaps_count, heaps_size, heaps_offset);
			game.play((bot == "y" || bot == "Y"), (graphically == "y" || graphically == "Y"));
			break;
		}
		case 5:
		{
			std::cout << "Ops! sorry the game is in progress, i'm busy of NIM right now" << std::endl;
			break;
		}
		case 6:
		{
			std::string temp;
			int width = 10;
			int height = 10;
			std::cout << dye::reset << "Choose size of the box" << std::endl
				<< "width " << dye::bright_black << "(deafult: 10, at least 5)" << std::endl << dye::reset << std::flush;
			do {
				std::cout << ": " << dye::bright_green;
				getline(std::cin, temp);

				try { width = std::stoi(temp); }
				catch (const std::exception&) {}

				if (width < 5)
					std::cout << dye::red << "ERR: " << dye::bold << "Invalid input" << std::endl << dye::reset;
			} while (width < 5);


			std::cout << dye::reset << "Choose size of the box" << std::endl
				<< "height: " << dye::bright_black << "(deafult: 10, at least 5)" << std::endl << dye::reset << std::flush;
			do {
				std::cout << ": " << dye::bright_green;
				getline(std::cin, temp);

				try { height = std::stoi(temp); }
				catch (const std::exception&) {}

				if (height < 5)
					std::cout << dye::red << "ERR: " << dye::bold << "Invalid input" << std::endl << dye::reset;
			} while (height < 5);

			/*std::cout << dye::reset << std::endl
				<< "Do you want to play against a bot?" << dye::bright_blue << " (y/N): " << dye::bright_green << std::flush;
			getline(std::cin, bot);
			std::cout << dye::reset << std::endl;*/

			std::string graphically;
			std::cout << dye::reset << "Do you want to display \"more\" game graphically? " << std::endl
				<< dye::bright_black << "(not recommended with high numbers)" << std::endl
				<< dye::bright_blue << " (y/N): " << dye::bright_green << std::flush;
			getline(std::cin, graphically);
			std::cout << dye::reset << std::endl;


			std::cout << std::endl
				<< "Quick who to:" << std::endl
				<< "- Game starts width box " << dye::magenta << width << dye::reset << "x" << dye::magenta << height << dye::reset << std::endl
				<< "- Select axis and and choose how shrink the box (between 1 and the size of the selected axis)" << std::endl
				<< dye::magenta << 1 << dye::reset << " - "
				<< dye::magenta << width << "/" << height << dye::reset << std::endl
				<< "- If you take a red box (last 1x1 box), you lose" << std::endl;

			game_boxslice game(width, height);
			game.play(false, (graphically == "y" || graphically == "Y"));
			break;
		}
		case 7:
		{
			minesweeper game;
			game.play();
			break;
		}
		default:
			std::cout << dye::bold << dye::red << "ERR: Invalid input" << dye::reset << std::endl;
		}
		std::cout << std::endl << "Would you like to play something else?" << dye::bright_blue << " (Y/n): " << dye::bright_green << std::flush;
		getline(std::cin, again);
		std::cout << dye::reset << std::endl;
	} while (again != "n" || again != "N");
	return 0;
}

/*
games:
	tictactoe
	2048
	subtraction game


	boxslice
	minesweeper
todo:
	- heap -
	- dice(31) -

	Jianshizi
	rescuequeen

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
