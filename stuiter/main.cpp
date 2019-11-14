#include <SFML/Graphics.hpp>

#include "action.hpp"
#include "objects.hpp"

#define WINDOW_SIZE_X 1280
#define WINDOW_SIZE_Y 720
#define MUUR_THICC 20
#define BALL_SPEED 1 // Dont change this, the collision system will break
#define FRAMERATE 60
#define UPDATES_PER_FRAME 4

int main() {
    // Window setup
    uint64_t updateCount = 0;
    uint64_t frameCount = 0;
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "Stuiter");
    window.setFramerateLimit(FRAMERATE);

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

    action actions[] = {
        action([] { return true; },
               [&] { ball.move(sf::Vector2f(ball.direction.x * BALL_SPEED, ball.direction.y * BALL_SPEED)); }),

        // Not scalable, very sad!
        action([&] { return ball.intersects(wall1.getGlobalBounds()); }, [&] { ball.direction.y *= -1; }),
        action([&] { return ball.intersects(wall2.getGlobalBounds()); }, [&] { ball.direction.x *= -1; }),
        action([&] { return ball.intersects(wall3.getGlobalBounds()); }, [&] { ball.direction.x *= -1; }),
        action([&] { return ball.intersects(wall4.getGlobalBounds()); }, [&] { ball.direction.y *= -1; })};

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update scene
        for (auto& action : actions)
            action();

        if (updateCount % UPDATES_PER_FRAME == 0) {
            // Draw calls
            window.clear();

            ball.draw(window);
            for (auto wall : walls)
                wall->draw(window);

            window.display();
            frameCount++;
        }

        updateCount++;
    }

    return 0;
}
