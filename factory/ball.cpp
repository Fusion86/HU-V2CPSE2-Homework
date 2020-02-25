#include "ball.hpp"
#include <sstream>

Ball::Ball(vec2 pos, float size, sf::Color color) :
	m_pos(pos),
	m_size(size),
	m_color(color)
{

}

void Ball::render(sf::RenderWindow & window)
{
	m_circle.setPosition(m_pos);
	m_circle.setRadius(m_size);
	m_circle.setFillColor(m_color);
	window.draw(m_circle);
}

void Ball::update(vec2 translation)
{
	m_pos = translation - sf::Vector2f(m_size, m_size) / 2.0f;
}

std::string Ball::getString()
{
	std::stringstream ss("",
		std::ios_base::app | std::ios_base::out);

	auto color = "";
	if (m_color == sf::Color::Yellow) color = "yellow";
	if (m_color == sf::Color::Red) color = "red";
	if (m_color == sf::Color::Green) color = "green";
	if (m_color == sf::Color::Blue) color = "blue";

	ss << "(" << int(m_pos.x) << "," << int(m_pos.y) << ") " << "CIRCLE " << color << " " << int(m_size) << "\n";
	return ss.str();
}
