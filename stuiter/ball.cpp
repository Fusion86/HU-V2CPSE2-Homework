#include <SFML/Graphics.hpp>
#include "ball.hpp"

ball::ball( sf::Vector2f position, sf::Color Color, float size, sf::Vector2f speed ):
	drawable(position, Color, size, speed)
{}

void ball::draw( sf::RenderWindow & window ) const {
	sf::CircleShape circle;
	circle.setRadius(size);
	circle.setPosition(position);
	circle.setFillColor(Color);
	window.draw(circle);
}