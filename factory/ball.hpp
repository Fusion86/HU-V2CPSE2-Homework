#pragma once
#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include <iostream>

class Ball : public Entity
{
public:
	Ball(vec2 pos, float size, sf::Color color);

	void render(sf::RenderWindow & window) override;
	void update(vec2 translation) override;


	bool isInEntity(vec2 mousePos) override
	{
		if (mousePos.x > m_pos.x&& mousePos.x < m_pos.x + m_size*2)
		{
			if (mousePos.y > m_pos.y&& mousePos.y < m_pos.y + m_size*2)
			{
				return true;
			}
		}

		return false;
	}

	std::string getString() override;

private:
	vec2 m_pos;
	float m_size;
	sf::Color m_color;

	sf::CircleShape m_circle;
};
