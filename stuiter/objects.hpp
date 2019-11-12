#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class drawable {
  public:
    virtual void draw(sf::RenderWindow& window) const = 0;
};

class ball : public drawable {
  public:
    sf::Vector2f direction;

  private:
    sf::CircleShape circle;

  public:
    ball(float radius) : direction(1, 1) {
        circle.setRadius(radius);
        circle.setFillColor(sf::Color::Green);
    }

    void draw(sf::RenderWindow& window) const override {
        window.draw(circle);
    }

    void setPosition(sf::Vector2f pos) {
        circle.setPosition(pos);
    }

    void move(sf::Vector2f pos) {
        circle.move(pos);
    }

    void interact(sf::FloatRect other) {
        sf::FloatRect intersection;
        if (circle.getGlobalBounds().intersects(other, intersection)) {
            // Only works when BALL_SPEED == 1
            // TODO: Hoek van inval == hoek van uitval
            direction = sf::Vector2f(direction.x * -1, direction.y * -1);
        }
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

    sf::FloatRect getGlobalBounds() {
        return rect.getGlobalBounds();
    }
};
