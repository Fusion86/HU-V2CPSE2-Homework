#include <SFML/Graphics.hpp>

#include "objects.hpp"

#define WINDOW_SIZE_X 1280
#define WINDOW_SIZE_Y 720
#define MUUR_THICC 20

int main() {
    // Window setup
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Stuiter");
    window.setFramerateLimit(60);

    // Setup other objects
    std::vector<drawable*> objects;
    ball ball(25);
    ball.setPosition(sf::Vector2f(WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 2));
    wall wall1(sf::Vector2f(0, 0), sf::Vector2f(WINDOW_SIZE_X, MUUR_THICC));                  // Top
    wall wall2(sf::Vector2f(0, 0), sf::Vector2f(MUUR_THICC, WINDOW_SIZE_Y));                  // Left
    wall wall3(sf::Vector2f(WINDOW_SIZE_X - MUUR_THICC, 0), sf::Vector2f(20, WINDOW_SIZE_Y)); // Right
    wall wall4(sf::Vector2f(0, WINDOW_SIZE_Y - MUUR_THICC), sf::Vector2f(WINDOW_SIZE_X, 20)); // Bottom
    objects.push_back(&ball);
    objects.push_back(&wall1);
    objects.push_back(&wall2);
    objects.push_back(&wall3);
    objects.push_back(&wall4);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update scene

        // Draw calls
        window.clear();

        for (auto ptr : objects)
            ptr->draw(window);

        window.display();
    }

    return 0;
}
