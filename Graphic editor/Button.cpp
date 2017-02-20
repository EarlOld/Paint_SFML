#include "Button.h"


Button::Button(std::string text1, int x, int y, RenderWindow &window)
{
	
	
	setposition.x = x;
	setposition.y = y;
	text = text1;

	button.setSize(Vector2f(90, 30));
	button.setOutlineColor(Color::Black);
	button.setOutlineThickness(2);
	button.setPosition(690, 35);
	button.setFillColor(Color::White);

	
	
	
	
	
}

void Button::show(RenderWindow &window)
{
	window.draw(button);

	Font font;
	font.loadFromFile("impact.ttf");
	Text autor(text, font, 20);
	autor.setFillColor(Color::Black);
	autor.setPosition(Vector2f(setposition.x +22,setposition.y +3)) ;
	

	window.draw(autor);
}



Button::~Button(void)
{
}
