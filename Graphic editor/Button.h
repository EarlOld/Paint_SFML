#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Button {
public:
	Texture texture1;
	Texture texture2;
	Sprite sprite;
	Text text;
	Button(Texture texture1, Texture texture2, Text text, Vector2f position);
	void show(RenderWindow &window);
	~Button(void);
};

