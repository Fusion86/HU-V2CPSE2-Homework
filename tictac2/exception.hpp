#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <string>

class end_of_file final : public std::exception{
public:
    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message = "end of file";
};

class unknown_color final : public std::exception{
public:
    unknown_color(const std::string & name):
        message( std::string( "unknown color [") + name + "]")
    {}

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
std::string message;
};

class unknown_shape final : public std::exception{
public:
    unknown_shape(const std::string & name):
        message( std::string( "unknown shape [") + name + "]")
    {}

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
std::string message;
};

class invalid_position final : public std::exception{
public:
    invalid_position(const char & name):
        message( std::string( "invalid position [") + name + "]")
    {}

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
std::string message;
};

#endif