#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "action.hpp"
#include "rectangle.hpp"
#include "ball.hpp"
#include "factory.hpp"

int main(int argc, char* argv[])
{
	sf::RenderWindow window{ sf::VideoMode{ 800, 600 }, "SFML window" };
	std::vector<std::unique_ptr<Entity>> entities;
	std::ifstream input("objects.txt");
	try {
		for (;;)
		{
			entities.push_back(screen_object_read(input));
		}
	}
	catch (end_of_file) {
		// do nothing
	}
	catch (std::exception & problem) {
		std::cout << problem.what();
		for (;;) {}
	}

	// Main loop
	while (window.isOpen())
	{
		// Update actions
		for (auto& entity : entities)
		{
			static sf::Vector2i oldMousePos;
			auto mousePos = sf::Mouse::getPosition(window);
			if (entity->isInEntity(sf::Vector2f(mousePos)))
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				{
					entity->update(sf::Vector2f(mousePos));
				}
			}
			oldMousePos = mousePos;
		}

		// Render
		window.clear();
		for (auto& entity : entities)
		{
			entity->render(window);
		}
		window.display();

		// 60 FPS
		sf::sleep(sf::milliseconds(16));

		// Event handling
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
		}
	}

	writeToFile(entities);

	return 0;
}
