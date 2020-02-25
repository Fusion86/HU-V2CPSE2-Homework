#pragma once
#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include <string>
#include <iostream>

class Picture : public Entity
{
public:
	Picture(vec2 pos, std::string file);

	void render(sf::RenderWindow& window) override;
	void update(vec2 translation) override;

	bool isInEntity(vec2 mousePos) override
	{
		if (mousePos.x > m_pos.x&& mousePos.x < m_pos.x + m_size.x)
		{
			if (mousePos.y > m_pos.y&& mousePos.y < m_pos.y + m_size.y)
			{
				return true;
			}
		}

		return false;
	}

	std::string getString() override;

private:
	vec2 m_size;
	vec2 m_pos;
	std::string file;

	sf::RectangleShape m_rect;
};
