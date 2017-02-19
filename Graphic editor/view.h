#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class view
{
private:
	RectangleShape scene;
	RectangleShape button;
	RectangleShape line;
	int menuNum = 0;

	void draw(RenderWindow &window);
public:
	view(RenderWindow& window);
	~view(void);
	
};

