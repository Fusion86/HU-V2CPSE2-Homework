#include "rectangle.hpp"
#include <sstream>

Rectangle::Rectangle(vec2 pos, vec2 size, sf::Color color) :
	m_pos(pos),
	m_size(size),
	m_color(color)
{

}

void Rectangle::render(sf::RenderWindow & window)
{
	m_rect.setPosition(m_pos);
	m_rect.setSize(m_size);
	m_rect.setFillColor(m_color);
	window.draw(m_rect);
}

void Rectangle::update(vec2 translation)
{
	m_pos = translation - m_size / 2.0f;
}

std::string Rectangle::getString()
{
	std::stringstream ss("",
		std::ios_base::app | std::ios_base::out);

	auto color = "";
	if (m_color == sf::Color::Yellow) color = "yellow";
	if (m_color == sf::Color::Red)    color = "red";
	if (m_color == sf::Color::Green)  color = "green";
	if (m_color == sf::Color::Blue)   color = "blue";

	ss << "(" << int(m_pos.x) << "," << int(m_pos.y) << ") " << "RECTANGLE " << color << " " << "(" << int(m_size.x) << "," << int(m_size.y) << ") " << "\n";
	return ss.str();
}
