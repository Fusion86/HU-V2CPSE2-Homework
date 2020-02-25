#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include <fstream>

class drawable {
public:
  drawable(sf::Vector2f position, sf::Vector2f size = sf::Vector2f(30.0, 30.0), sf::Color Color = sf::Color::White ):
      position(position),
      size(size),
      Color(Color)
  {}

  virtual void draw(sf::RenderWindow& window) const = 0;

  virtual void jump(sf::Vector2f target) {
      position.x = target.x - size.x / 2;
      position.y = target.y - size.y / 2;
  }

  void jump(sf::Vector2i target) {
      jump(sf::Vector2f(static_cast<float>(target.x), static_cast<float>(target.y)));
  }

  virtual bool contains(const sf::Vector2i & point){
    return point.x >= position.x && 
            point.x <= position.x + size.x && 
            // When using a custom window size, some of the Y coordinates end up offset by about 40 pixels
            point.y >= position.y + 40.0 && 
            point.y <= position.y + size.y + 40.0; 
  }
  
  void writeGeneral(std::ofstream & output){
    output << "(" << position.x << "," << position.y << ") "; 
  }

  virtual void writeType(std::ofstream & output){}

  virtual void writeSpecific(std::ofstream & output){}

  void writeColor(std::ostream& output) { 
	const struct { const char* name; sf::Color color; } colors[]{
    { "yellow", sf::Color::Yellow },
    { "red",    sf::Color::Red },
    { "green",    sf::Color::Green },
    { "blue",    sf::Color::Blue },
    { "black",    sf::Color::Black },
    { "white",    sf::Color::White },
    };
    for (auto const & colour : colors) {
      if (colour.color == Color) {
        output << colour.name << " ";
      }
    }
  }
  
protected:
  sf::Vector2f position;
  sf::Vector2f size;
  sf::Color Color;
};

#endif