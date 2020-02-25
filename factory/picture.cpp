#include "picture.hpp"
#include <sstream>

Picture::Picture(vec2 pos, std::string file) :
	m_pos(pos),
	file(file)
{

}

void Picture::render(sf::RenderWindow& window)
{
	sf::Texture tex;
	tex.loadFromFile(file);
	m_rect.setPosition(m_pos);
	m_rect.setSize(sf::Vector2f(tex.getSize()));
	m_size = sf::Vector2f(tex.getSize());
	m_rect.setTexture(&tex);
	window.draw(m_rect);
}

void Picture::update(vec2 translation)
{
	m_pos = translation - m_size / 2.0f;
}

std::string Picture::getString()
{
	std::stringstream ss("",
		std::ios_base::app | std::ios_base::out);

	ss << "(" << int(m_pos.x) << "," << int(m_pos.y) << ") " << "PICTURE " << file << "\n";

	return ss.str();
}
