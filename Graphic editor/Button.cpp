#include "Button.h"


Button::Button(Texture texture1, Texture texture2, Text text, Vector2f position)
{
	this->texture1 = texture1;
	this->texture2 = texture2;
	this->text = text;
	sprite.setTexture(texture1);
	sprite.setPosition(position.x, position.y);
	text.setPosition(position.x, position.y);
}

void Button::show(RenderWindow &window)
{
	window.draw(sprite);
}



Button::~Button(void)
{
}
