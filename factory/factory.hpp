#pragma once
#include <fstream>
#include "picture.hpp"
#include "rectangle.hpp"
#include "ball.hpp"
#include "exceptions.hpp"

void writeToFile(std::vector<std::unique_ptr<Entity>>& entities)
{
	std::ofstream file;
	file.open("objects.txt");

	for (auto& entity : entities)
	{
		file << entity->getString();
	}

	file.close();
}

std::ifstream& operator>>(std::ifstream& input, sf::Color& rhs) {
	std::string s;
	input >> s;
	const struct { const char* name; sf::Color color; } colors[]{
		{ "yellow", sf::Color::Yellow },
		{ "red",    sf::Color::Red },
		{ "blue",    sf::Color::Blue },
		{ "green",    sf::Color::Green }
	};
	for (auto const& color : colors) {
		if (color.name == s) {
			rhs = color.color;
			return input;
		}
	}
	if (s == "") {
		throw end_of_file();
	}
	throw unknown_color(s);
}

std::ifstream& operator>>(std::ifstream& input, sf::Vector2f& rhs) {
	char c;

	if (!(input >> c)) { throw end_of_file(); }
	if (c != '(') { throw invalid_position(c); }
	if (!(input >> rhs.x)) { throw invalid_type(c); }
	if (!(input >> c)) { throw end_of_file(); }
	if (!(input >> rhs.y)) { throw invalid_type(c); }
	if (!(input >> c)) { throw end_of_file(); }
	if (c != ')') { throw invalid_position(c); }

	return input;
}

std::unique_ptr<Entity> screen_object_read(std::ifstream& input) {
	sf::Vector2f position;
	std::string name;
	input >> position >> name;

	if (name == "CIRCLE")
	{
		float size;
		sf::Color color;
		input >> color >> size;
		return std::make_unique<Ball>(position, size, color);

	}
	else if (name == "RECTANGLE")
	{
		vec2 size;
		sf::Color color;
		input >> color >> size;
		return std::make_unique<Rectangle>(position, size, color);

	}
	else if (name == "PICTURE")
	{
		std::string file;
		input >> file;
		return std::make_unique<Picture>(position, file);

	}
	else if (name == "") {
		throw end_of_file();
	}

	throw unknown_shape(name);
}
