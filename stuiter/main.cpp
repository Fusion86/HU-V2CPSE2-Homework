#include <SFML/Graphics.hpp>

#include "objects.hpp"

#define WINDOW_SIZE_X 1280
#define WINDOW_SIZE_Y 720
#define MUUR_THICC 20
#define BALL_SPEED 5

int main() {
    // Window setup
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Stuiter");
    window.setFramerateLimit(60);

    // Setup other objects
    std::vector<wall*> walls;
    ball ball(25);
    ball.setPosition(sf::Vector2f(WINDOW_SIZE_X / 2, WINDOW_SIZE_Y / 2));
    wall wall1(sf::Vector2f(0, 0), sf::Vector2f(WINDOW_SIZE_X, MUUR_THICC));                  // Top
    wall wall2(sf::Vector2f(0, 0), sf::Vector2f(MUUR_THICC, WINDOW_SIZE_Y));                  // Left
    wall wall3(sf::Vector2f(WINDOW_SIZE_X - MUUR_THICC, 0), sf::Vector2f(20, WINDOW_SIZE_Y)); // Right
    wall wall4(sf::Vector2f(0, WINDOW_SIZE_Y - MUUR_THICC), sf::Vector2f(WINDOW_SIZE_X, 20)); // Bottom
    walls.push_back(&wall1);
    walls.push_back(&wall2);
    walls.push_back(&wall3);
    walls.push_back(&wall4);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update scene
        // 1. move ball
        ball.move(sf::Vector2f(ball.direction.x * BALL_SPEED, ball.direction.y * BALL_SPEED));

        // 2. boing
        for (auto wall : walls) {
            // TODO: do boing
        }

        // Draw calls
        window.clear();

        ball.draw(window);
        for (auto wall : walls)
            wall->draw(window);

        window.display();
    }

    return 0;
}
