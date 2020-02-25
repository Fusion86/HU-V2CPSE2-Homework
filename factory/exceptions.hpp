#pragma once
#include <string>

class unknown_color : public std::exception {
public:
	unknown_color(const std::string& name) :
		s{ std::string{ "unknown color [" } +name + "]" }
	{}
	const char* what() const noexcept override {
		return s.c_str();
	}
private:
	std::string s;
};

class unknown_shape : public std::exception {
public:
	unknown_shape(const std::string& name) :
		s{ std::string{ "unknown shape [" } +name + "]" }
	{}
	const char* what() const noexcept override {
		return s.c_str();
	}
private:
	std::string s;
};

class end_of_file : public std::exception {
public:
	end_of_file()
	{}
	const char* what() const noexcept override {
		return "end of file";
	}
};

class invalid_position : public std::exception {
public:
	invalid_position(char x) : x(x)
	{}
	const char* what() const noexcept override {
		return std::string("character " + std::string(&x) + " is not ( or )").c_str();
	}
private:
	char x;
};

class invalid_type : public std::exception{
public:
	invalid_type(char x) : x(x)
	{}
	const char* what() const noexcept override {
		return std::string("character " + std::string(&x) + " is of type int or float for a position!").c_str();
	}
private:
	char x;
};