#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cmath>
using namespace sf;

class Button {
private:
	
	RectangleShape button;

	std::string text;
	Vector2f setposition;
public:
	Button(std::string text1, int x, int y,  RenderWindow &window);
	void show(RenderWindow &window, int x, int y);
	void setColor(Color color);

	~Button(void);
};

class Button_top {
public:

	RectangleShape button;

	std::string text;
	Vector2f setposition;

	Button_top(std::string text1, int x, int y, RenderWindow &window);
	void show(RenderWindow &window, int x, int y);

	~Button_top(void);
};

class Button_color {
public:
	
	RectangleShape button;

	std::string text;
	Vector2f setposition;

	Button_color(std::string text1, int x, int y, Color color,   RenderWindow &window);
	void show(RenderWindow &window, int x, int y);

	~Button_color(void);
};

