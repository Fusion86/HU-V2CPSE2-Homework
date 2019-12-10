#include <fstream>

#include "yeet.hpp"

#define WINDOW_SIZE_X 1280
#define WINDOW_SIZE_Y 720
#define LEVEL_FILE_NAME "zorlo.txt"

static std::vector<drawable*> drawables;

drawable* read_object(std::istream& is) {
    std::string type;
    sf::Vector2f pos;
    is >> type >> pos;

    if (type == "Circle") {
        float diameter;
        is >> diameter;
        return new circle(pos, diameter);
    } else if (type == "Rect") {
        sf::Vector2f end;
        sf::Color color;
        is >> end;
        is >> color;
        return new rectangle(pos, end, color);
    } else if (type == "Line") {
        float length;
        sf::Color color;
        is >> length;
        is >> color;
        return new line(pos, length, color);
    } else if (type == "Picture") {
        sf::Vector2f end;
        std::string img;
        is >> end;
        is >> img;
        return new picture(pos, end, img);
    } else {
        throw new invalid_type_exception(type);
    }
}

void load_state() {
    std::ifstream ifs(LEVEL_FILE_NAME);
    ifs.exceptions(std::ifstream::failbit | std::ifstream::badbit | std::ifstream::eofbit);

    do {
        drawables.push_back(read_object(ifs));
    } while (1);
}

void cleanup() {
    for (auto x : drawables)
        delete x;

    drawables.clear();
}

void save_state() {
    std::ofstream ofs(LEVEL_FILE_NAME);
    ofs.close();
}

int main() {
    load_state();

    // Display window and move objects

    save_state();
    cleanup();
    return 0;
}
