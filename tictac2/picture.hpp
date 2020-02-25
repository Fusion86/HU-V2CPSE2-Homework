#ifndef PICTURE_HPP
#define PICTURE_HPP

#include "drawable.hpp"

class picture : public drawable {
public:
    picture(sf::Vector2f position, std::string filename):
        drawable(position),
        filename(filename) 
    {
        texture.loadFromFile(filename);
        sprite.setTexture(texture);
        sprite.setPosition(position);
        sprite.setScale(sf::Vector2f(0.2, 0.2));
    }

    void draw( sf::RenderWindow & window)const override {
		window.draw(sprite);
	}

    bool contains(const sf::Vector2i & point) override {
        sf::Rect<float> rect = sprite.getGlobalBounds();
        return point.x >= rect.left && 
                point.x <= rect.left + rect.width && 
                // When using a custom window size, some of the Y coordinates end up offset by about 40 pixels
                point.y >= rect.top + 40.0 && 
                point.y <= rect.top + rect.height + 40.0; 
    }

    void jump(sf::Vector2f target) override {
        sf::Rect<float> rect = sprite.getGlobalBounds();
        position.x = target.x - rect.width / 2;
        position.y = target.y - rect.height / 2;
        sprite.setPosition(position);
    }

    void writeType(std::ofstream & output) override { output << "PICTURE ";}

    void writeSpecific(std::ofstream & output) override {
        output << filename << '\n';
    }

    
private:
    std::string filename;
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif