#include <fstream>

#include "yeet.hpp"

#define WINDOW_SIZE_X 1280
#define WINDOW_SIZE_Y 720
#define LEVEL_FILE_NAME "zorlo.txt"

void load_state() {
    std::ifstream ifs(LEVEL_FILE_NAME);
    ifs.exceptions(std::ifstream::failbit | std::ifstream::badbit | std::ifstream::eofbit);
}

void save_state() {
    std::ofstream ofs(LEVEL_FILE_NAME);
    ofs.close();
}

int main() {
    load_state();

    // Display window and move objects

    save_state();
    return 0;
}
