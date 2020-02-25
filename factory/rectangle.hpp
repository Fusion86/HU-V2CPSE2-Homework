#pragma once
#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include <iostream>

class Rectangle : public Entity
{
public:
	Rectangle(vec2 pos, vec2 size, sf::Color color);

	void render(sf::RenderWindow& window) override;
	void update(vec2 translation) override;

	bool isInEntity(vec2 mousePos) override
	{
		if (mousePos.x > m_pos.x && mousePos.x < m_pos.x + m_size.x)
		{
			if(mousePos.y > m_pos.y && mousePos.y < m_pos.y + m_size.y)
			{
				return true;
			}
		}

		return false;
	}

	std::string getString() override;

private:
	sf::RectangleShape m_rect;

	vec2 m_pos;
	vec2 m_size;
	sf::Color m_color;
};
