#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "exception.hpp"
#include <fstream>
#include <memory>

std::ifstream & operator>>( std::ifstream & input, sf::Color & rhs){
    std::string s;
    input >> s;
    const struct {const char* name; sf::Color color; } colors[]
    {
        { "yellow", sf::Color::Yellow },
		{ "red",    sf::Color::Red },
		{ "green",  sf::Color::Green },
		{ "blue",   sf::Color::Blue },
		{ "black",  sf::Color::Black },
		{ "white",  sf::Color::White }
    };
    for( auto const & color : colors ){
        if(color.name == s){
            rhs = color.color;
            return input;
        }
    }
    if(s == ""){ throw end_of_file(); }
    throw unknown_color( s );    
}

std::ifstream & operator>>(std::ifstream & input, sf::Vector2f & rhs ){
    char c;
    if( ! ( input >> c )){ throw end_of_file(); }
    if( c != '(' ){ throw invalid_position( c ); }
    if( ! ( input >> rhs.x )){ throw end_of_file(); }
    if( ! ( input >> c )){ throw end_of_file(); }
    if( ! ( input >> rhs.y )){ throw end_of_file(); }
    if( ! ( input >> c )){ throw end_of_file(); }
    if( c != ')' ){ throw invalid_position( c ); }
    return input;
}

std::unique_ptr<drawable> drawable_read(std::ifstream & input){
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color color;
    std::string name;
    std::string filename;
    float radius;
    input >> position >> name;

    if(name == "CIRCLE"){
        input >> color >> radius;
        return std::make_unique<circle>(position, radius, color);
    }else if(name == "RECTANGLE"){
        input >> color >> size;
        return std::make_unique<rectangle>(position, size, color);
    }else if(name == "PICTURE"){
        input >> filename;
        return std::make_unique<picture>(position, filename);
    }else if(name == ""){
        throw end_of_file();
    }
    throw unknown_shape( name );
}

#endif