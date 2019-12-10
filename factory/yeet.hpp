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

class invalid_type_exception : std::exception {
  public:
    invalid_type_exception(std::string err) : err(err) {}

    const char* what() noexcept {
        std::stringstream ss;
        ss << "Invalid type. Got '" << err << "'.";
        return ss.str().c_str();
    }

  private:
    std::string err;
};

class unkown_color_exception : std::exception {
  public:
    unkown_color_exception(std::string color) : color(color) {}

    const char* what() noexcept {
        std::stringstream ss;
        ss << "Unknown color '" << color << "'.";
        return ss.str().c_str();
    }

  private:
    std::string color;
};

std::istream& operator>>(std::istream& is, sf::Vector2f& vec) {
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

std::istream& operator>>(std::istream& is, sf::Color& color) {
    std::string str;
    is >> str;
    if (str == "Red")
        color = sf::Color::Red;
    else if (str == "Green")
        color = sf::Color::Green;
    else if (str == "Blue")
        color = sf::Color::Blue;
    else if (str == "White")
        color = sf::Color::White;
    else if (str == "Magenta")
        color = sf::Color::Magenta;
    else
        throw new unkown_color_exception(str);
    return is;
}

class drawable {
  public:
    drawable(sf::Vector2f position) : position(position) {}

    virtual ~drawable() {}
    virtual void draw(sf::RenderTarget& disp) = 0;
    virtual sf::Transformable& getTransformable() = 0;

    virtual void update() {}

    // virtual bool isSelected() { return false; }

  protected:
    sf::Vector2f position;
    bool isSelected = false;
};

class circle : public drawable {
  public:
    circle(sf::Vector2f position, float diameter, sf::Color color)
        : drawable(position), diameter(diameter), color(color), shape(diameter / 2) {}

    virtual sf::Transformable& getTransformable() override { return shape; }

    virtual void draw(sf::RenderTarget& disp) override {
        shape.setPosition(position);
        shape.setFillColor(color);
        disp.draw(shape);
    }

  protected:
    float diameter;
    sf::Color color;
    sf::CircleShape shape;
};

class rectangle : public drawable {
  public:
    rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color)
        : drawable(position), size(size), color(color), shape(size) {}

    virtual sf::Transformable& getTransformable() override { return shape; }

    virtual void draw(sf::RenderTarget& disp) override {
        shape.setPosition(position);
        shape.setFillColor(color);
        disp.draw(shape);
    }

  protected:
    sf::Vector2f size;
    sf::Color color;
    sf::RectangleShape shape;
};

class line : public drawable {
  public:
    line(sf::Vector2f position, float length, float rotation, sf::Color color)
        : drawable(position), length(length), rotation(rotation), color(color), shape(sf::Vector2f(length, 10)) {}

    virtual sf::Transformable& getTransformable() override { return shape; }

    virtual void draw(sf::RenderTarget& disp) override {
        shape.setPosition(position);
        shape.setRotation(rotation);
        shape.setFillColor(color);
        disp.draw(shape);
    }

  protected:
    float length;
    float rotation;
    sf::Color color;
    sf::RectangleShape shape;
};

class picture : public drawable {
  public:
    picture(sf::Vector2f position, sf::Vector2f size, std::string img) : drawable(position), size(size), img(img) {}

    virtual sf::Transformable& getTransformable() override { return shape; }

    virtual void draw(sf::RenderTarget& disp) override {}

  protected:
    sf::Vector2f size;
    std::string img;
    sf::RectangleShape shape;
};
