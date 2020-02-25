#ifndef LINE_HPP
#define LINE_HPP

#include "drawable.hpp"

class line : public drawable {
public:
    void draw(sf::RenderWindow& window) const {
        sf::VertexArray lines(sf::LinesStrip, 2);
        lines[0] = position;
        lines[1] = size;
        window.draw(lines);             
    }
};

#endif