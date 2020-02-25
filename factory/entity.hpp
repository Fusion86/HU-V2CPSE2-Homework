#pragma once
#include <SFML/Graphics.hpp>

using vec2 = sf::Vector2f;
using vec3 = sf::Vector3f;

class Entity
{
public:
	virtual void render(sf::RenderWindow & window) = 0;
	virtual void update(vec2 translation) = 0;
	virtual bool isInEntity(vec2 mousePos) = 0;
	virtual std::string getString() = 0;
};

