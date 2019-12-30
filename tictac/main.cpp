#include <iostream>

#include "tictac.hpp"

int main(int argc, char** argv) {
    if (argv[0] == "gui") {
        std::cout << "Playing GUI version" << std::endl;
        // tictac_gui game;
        // return game.run();
    } else {
        std::cout << "Playing text version" << std::endl;
        tictac_tui game;
        return game.run();
    }
}
