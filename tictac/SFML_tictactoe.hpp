#pragma once
#include "tictactoe.hpp"
#include <SFML/Graphics.hpp>

class SFML_tictactoe : public tictactoe {
public:
	SFML_tictactoe() {
		texture.loadFromFile("cross.png");
		cross.setTexture(texture);
		cross.setScale(sf::Vector2f(0.1, 0.1));
		texture2.loadFromFile("dot.png");
		dot.setTexture(texture2);
		dot.setScale(sf::Vector2f(0.1, 0.1));
	}
	void play() override {
		sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
		while (window.isOpen()) {
			window.display();
			sf::sleep(sf::milliseconds(20));
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && moves.size() > 0) {
				moves.pop_back();
				sf::sleep(sf::milliseconds(100));
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				int move = select(sf::Mouse::getPosition(window));
				if (move != -1) {
					if (std::find(moves.begin(), moves.end(), move) != moves.end()) {
						continue;
					}
					moves.push_back(move);
					if (check_win()) {
						return;
					}
					if (check_draw()) {
						return;
					}
				}
			}
			window.clear();
			draw(window);

			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}
		}
	}
private:
	sf::Texture texture;
	sf::Texture texture2;
	sf::Sprite cross;
	sf::Sprite dot;
	const std::vector<sf::Vector2f> positions = { sf::Vector2f{195, 115}, sf::Vector2f{280, 115}, sf::Vector2f{365, 115}, sf::Vector2f{195, 200}, sf::Vector2f{280, 200}, sf::Vector2f{365, 200}, sf::Vector2f{195, 285}, sf::Vector2f{280, 285}, sf::Vector2f{365, 285} };
	void draw(sf::RenderWindow& window) {
		sf::RectangleShape rectangle;
		rectangle.setSize(sf::Vector2f{ 5, 250 });
		rectangle.setPosition(sf::Vector2f{ 275, 115 });
		window.draw(rectangle);
		rectangle.setPosition(sf::Vector2f{ 360, 115 });
		window.draw(rectangle);
		rectangle.setSize(sf::Vector2f{ 250, 5 });
		rectangle.setPosition(sf::Vector2f{ 195, 195 });
		window.draw(rectangle);
		rectangle.setPosition(sf::Vector2f{ 195, 280 });
		window.draw(rectangle);
		for (int i = 0; i < 9; i++) {
			if (get_square(i) == 'x') {
				cross.setPosition(positions[i]);
				window.draw(cross);
			}else if(get_square(i) == 'o') {
				dot.setPosition(positions[i]);
				window.draw(dot);
			}
		}
	}

	int select(sf::Vector2i location) {
		int move = -1;
		if (195 <= location.x && location.x <= 445 && 365 >= location.y && location.y >= 115) {
			move = 0;
			if (280 <= location.x && location.x <= 360) {
				move += 1;
			}else if (365 <= location.x && location.x <= 445) {
				move += 2;
			}

			if (200 <= location.y && location.y <= 280) {
				move += 3;
			}
			else if (285 <= location.y && location.y <= 365) {
				move += 6;
			}
		}
		return move;
	}

};