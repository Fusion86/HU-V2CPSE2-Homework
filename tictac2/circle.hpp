#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "drawable.hpp"

class circle : public drawable {
public:
    circle(sf::Vector2f position, float radius, sf::Color Color = sf::Color::White, sf::Vector2f size = sf::Vector2f(0.0, 0.0)):
        drawable(position, sf::Vector2f(2*radius, 2*radius), Color),
        radius(radius)
    {}

    void draw( sf::RenderWindow & window ) const override {
        sf::CircleShape circle;
        circle.setRadius(radius);
        circle.setPosition(position);
        circle.setFillColor(Color);
        window.draw(circle);
    }

    void writeType(std::ofstream & output) override { output << "CIRCLE ";}

    void writeSpecific(std::ofstream & output) override {
        writeColor(output);
        output << radius << '\n';
    }
    
protected:
    float radius; 
};

#endif