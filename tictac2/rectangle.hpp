#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "drawable.hpp"

class rectangle : public drawable {
public:
    rectangle(sf::Vector2f position, sf::Vector2f size = sf::Vector2f(60.0, 60.0), sf::Color Color = sf::Color::White ):
        drawable(position, size, Color)
    {}

    void draw(sf::RenderWindow& window) const {
        sf::RectangleShape rectangle;
        rectangle.setPosition(position);
        rectangle.setSize(size);
        rectangle.setFillColor(Color);
        window.draw(rectangle); 
    }

    void writeType(std::ofstream & output) override { output << "RECTANGLE ";}

    void writeSpecific(std::ofstream & output) override {
        writeColor(output);
		output << "(" << size.x << "," << size.y << ")\n";
    }


};

#endif