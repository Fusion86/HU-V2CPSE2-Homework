#pragma once

#include <SFML/Graphics.hpp>

class drawable {
  public:
    virtual void draw(sf::RenderWindow& window) const = 0;
};

class ball : public drawable {
  private:
    sf::CircleShape circle;

  public:
    ball(float radius) {
        circle.setRadius(radius);
        circle.setFillColor(sf::Color::Green);
    }

    void draw(sf::RenderWindow& window) const override {
        window.draw(circle);
    }

    void setPosition(sf::Vector2f pos) {
        circle.setPosition(pos);
    }
};

class wall : public drawable {
  private:
    sf::RectangleShape rect;

  public:
    wall(sf::Vector2f pos, sf::Vector2f size) {
        rect.setPosition(pos);
        rect.setSize(size);
        rect.setFillColor(sf::Color::White);
    }

    void draw(sf::RenderWindow& window) const override {
        window.draw(rect);
    }
};
