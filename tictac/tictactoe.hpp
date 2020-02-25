#pragma once
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

class tictactoe {
public:
	virtual void play() = 0;

protected:
	//function checks whether someone won
	bool check_win() {
		for (const auto& win : winning_moves) {
			if (get_square(win[0]) == get_square(win[1]) && get_square(win[1]) == get_square(win[2]) && get_square(win[0]) != ' ') {
				std::cout << get_square(win[0]) << " wins!";
				return true;
			}
		}
		return false;
	}

	bool check_draw() {
		if (moves.size() == 9) {
			std::cout << "draw!";
			return true;
		}
		return false;
	}
	//function returns whether a square is a x, an o or not filled yet
	char get_square(int square) {
		for (const auto& move : moves) {
			if (move == square) {
				auto iterator = std::find(moves.begin(), moves.end(), move);
				auto index = std::distance(moves.begin(), iterator);
				return index % 2 == 0 ? 'x' : 'o';
			}
		}
		return ' ';
	}

	const std::vector<std::array<int, 3>> winning_moves = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6} };
	std::vector<int> moves = {};
};
