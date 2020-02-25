#include "terminal_tictactoe.hpp"
#include "SFML_tictactoe.hpp"

int main(int argc, char** argv) {
    // if (argv[1] == "tui") {
        auto game = terminal_tictactoe();
        game.play();
    // } else {
    //     auto game = SFML_tictactoe();
    //     game.play();
    // }
}
