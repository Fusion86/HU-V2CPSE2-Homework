#pragma once

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

class invalid_format_exception : std::exception {
  public:
    invalid_format_exception(std::string expected_character) : expected_character(expected_character) {}

    const char* what() noexcept {
        std::stringstream ss;
        ss << "Invalid format. Expected '" << expected_character << "' but got something else.";
        return ss.str().c_str();
    }

  private:
    std::string expected_character;
};

std::istream& operator>>(std::istream& is, sf::Vector2f vec) {
    char c;
    is >> c;
    if (c != '(') throw new invalid_format_exception("(");
    if (!(is >> vec.x)) throw invalid_format_exception("x coordinate");
    is >> c;
    if (c != ',') throw new invalid_format_exception(",");
    if (!(is >> vec.y)) throw invalid_format_exception("y coordinate");
    is >> c;
    if (c != ')') throw new invalid_format_exception(")");
    return is;
}

class drawable {
  public:
    virtual void draw(sf::RenderWindow& window);

    std::ostream& operator<<(std::ostream& os) { return os; }

    std::istream& operator>>(std::istream& is) {
        std::string type;
        is >> position;
        is >> type;

        switch (type) {
            case "test":
                break;
        }

        return is;
    }

  protected:
    std::string name;
    sf::Vector2f position;
};

class selectable {
  public:
    bool isSelected;
};

class circle : public drawable, selectable {};

class rectangle : public drawable, selectable {};

class line : public drawable, selectable {};

class picture : public drawable, selectable {};
