#pragma once

#include <array>
#include <cmath>

enum class play_res {
    none = 0,
    win,
};

enum class tictac_state {
    play,
    gameover,
};

/// Just make sure that sqrt(BOARD_SIZE) returns a non-decimal number
template <size_t BOARD_SIZE = 9>
class tictac {
  public:
    int ply = 0;

    /// Game board.
    ///
    /// 0 = empty
    /// 1 = crosses
    /// 2 = noughts
    std::array<int, BOARD_SIZE> board;

    bool cross = true;
    tictac_state state = tictac_state::play;

    int run() {
        for (;;) {
            draw();

            switch (state) {
                case tictac_state::play: {
                    player_play(cross);
                    cross = !cross;
                } break;

                case tictac_state::gameover: {
                    return 0;
                } break;
            }
        }
    }

    play_res player_play(bool cross) {
        for (;;) {
            int input = get_player_input(cross);
            if (input < board.size() || board[input] == 0) {
                board[input] = cross ? 1 : 2;
                // TODO: check win
                return play_res::none;
            }
        }
    }

    virtual int get_player_input(bool cross) = 0;
    virtual void draw() = 0;
};

class tictac_tui : public tictac<> {
  public:
    virtual int get_player_input(bool cross) override {}

    virtual void draw() override {
        switch (state) {
            case tictac_state::play: {
                std::cout << "Ply: " << ply << std::endl;
                std::cout << "Current player: " << (cross ? "Crosses" : "Noughts") << std::endl << std::endl;
                draw_board();
            } break;
            case tictac_state::gameover: {
                std::cout << "Game over" << std::endl;
                std::cout << "Winner : todo" << std::endl;
            } break;
        }
    }

  private:
    void draw_board() {
        int axis_length = std::sqrt(board.size());
        for (int i = 0; i < board.size(); i++) {
            std::cout << int_to_mark(board[i]);

            if (i > 0 && (i + 1) % axis_length == 0) {
                std::cout << std::endl;
            }
        }
    }

    const char* int_to_mark(int x) {
        switch (x) {
            case 0:
                return " ";
            case 1:
                return "X";
            case 2:
                return "O";
            default:
                return "?";
        }
    }
};

class tictac_gui : public tictac<> {};
