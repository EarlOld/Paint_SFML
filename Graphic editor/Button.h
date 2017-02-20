#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cmath>
using namespace sf;

class Button {
public:
	
	RectangleShape button;

	std::string text;
	Vector2f setposition;

	Button(std::string text1, int x, int y,  RenderWindow &window);
	void show(RenderWindow &window, int x, int y);

	~Button(void);
};

