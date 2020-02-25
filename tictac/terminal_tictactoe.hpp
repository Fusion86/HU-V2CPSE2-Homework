#pragma once
#include "tictactoe.hpp"

class terminal_tictactoe : public tictactoe {
public:
	void play() override{
		while (true) {
			std::cout << "enter a square or enter z to undo last move ";
			char move;
			std::cin >> move;
			if (move == 'z') {
				moves.pop_back();
				print();
				continue;
			}else {
				move -= 48;
				if (std::find(moves.begin(), moves.end(), move) != moves.end()) {
					continue;
				}
				moves.push_back(move);
				print();
				if (check_win()) {
					return;
				}
				if (check_draw()) {
					return;
				}
			}
		}
	}
private:
	void print(){
		std::cout << get_square(0) << "|" << get_square(1) << "|" << get_square(2) << "\n";
		std::cout << "-----" << "\n";
		std::cout << get_square(3) << "|" << get_square(4) << "|" << get_square(5) << "\n";
		std::cout << "-----" << "\n";
		std::cout << get_square(6) << "|" << get_square(7) << "|" << get_square(8) << "\n";
	}

};
