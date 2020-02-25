#ifndef WALL_HPP
#define WALL_HPP

#include "drawable.hpp"

class wall : public drawable {
  public:
    wall(sf::Vector2f position, sf::Vector2f formaat, sf::Color Color,  float size = 30.0) : drawable(position, Color, size), formaat(formaat) {update();}

    void draw(sf::RenderWindow& window) const {
        sf::RectangleShape rectangle;
        rectangle.setPosition(position);
        rectangle.setSize(formaat);
        rectangle.setFillColor(Color);
        window.draw(rectangle);
        
    }

    void update() override {
      floatRekt = sf::Rect<float>(position, formaat);
    }

  private:
    sf::Vector2f formaat;
};

#endif