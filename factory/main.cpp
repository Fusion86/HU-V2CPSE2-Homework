#include <fstream>

#include "yeet.hpp"

#define WINDOW_SIZE_X 1280
#define WINDOW_SIZE_Y 720
#define LEVEL_FILE_NAME "zorlo.txt"

static std::vector<drawable*> drawables;

drawable* read_object(std::istream& is) {
    std::string type;
    sf::Vector2f pos;
    is >> pos >> type;

    if (type == "Circle") {
        float diameter;
        sf::Color color;
        is >> diameter;
        is >> color;
        return new circle(pos, diameter, color);
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
    ifs.exceptions(std::ifstream::failbit | std::ifstream::eofbit);

    while (!ifs.eof()) {
        drawables.push_back(read_object(ifs));
    }
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
    try {
        load_state();
    } catch (std::ios_base::failure& e) {
        // Garbage language
        // https://codereview.stackexchange.com/questions/57829/better-option-than-errno-for-file-io-error-handling
        std::cout << "File error: " << e.what() << std::endl;
        return 1;
    }

    // Display window and move objects

    save_state();
    cleanup();
    return 0;
}
