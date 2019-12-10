#include <fstream>

#include "yeet.hpp"

#define WINDOW_SIZE_X 1280
#define WINDOW_SIZE_Y 720
#define FRAMERATE 60
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
        sf::Vector2f size;
        sf::Color color;
        is >> size;
        is >> color;
        return new rectangle(pos, size, color);
    } else if (type == "Line") {
        float length;
        float rotation;
        sf::Color color;
        is >> length;
        is >> rotation;
        is >> color;
        return new line(pos, length, rotation, color);
    } else if (type == "Picture") {
        sf::Vector2f scale;
        std::string img;
        is >> scale;
        is >> img;
        return new picture(pos, scale, img);
    } else {
        throw new invalid_type_exception(type);
    }
}

void load_state() {
    std::ifstream ifs(LEVEL_FILE_NAME);

    if (!ifs.is_open()) {
        throw new std::runtime_error("Coudln't open file.");
    }

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
    // std::ofstream ofs(LEVEL_FILE_NAME);
    // ofs.close();
}

int main() {
    try {
        load_state();
    } catch (std::exception& e) {
        // Garbage language
        // https://codereview.stackexchange.com/questions/57829/better-option-than-errno-for-file-io-error-handling
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }

    // Display window and move objects
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Fabriek");
    window.setFramerateLimit(FRAMERATE);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        for (auto& x : drawables)
            x->draw(window);

        window.display();
    }

    save_state();
    cleanup();
    return 0;
}
