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
	button.setPosition(Vector2f(setposition.x,setposition.y)) ;

}

void Button::show(RenderWindow &window, int x = 0, int y = 0)
{
	window.draw(button);

	Font font;
	font.loadFromFile("impact.ttf");
	Text autor(text, font, 20);
	autor.setFillColor(Color::Black);
	autor.setPosition(Vector2f(setposition.x +25 + x,setposition.y +3+y)) ;
	

	window.draw(autor);
}



Button::~Button(void)
{
}


Button_color::Button_color(std::string text1, int x, int y, Color color,   RenderWindow &window)
{
	
	
	setposition.x = x;
	setposition.y = y;
	text = text1;

	button.setSize(Vector2f(30, 30));
	button.setOutlineColor(Color::Black);
	button.setOutlineThickness(2);
	button.setPosition(690, 35);
	button.setFillColor(color);
	button.setPosition(Vector2f(setposition.x,setposition.y)) ;

}

void Button_color::show(RenderWindow &window, int x = 0, int y = 0)
{
	window.draw(button);

	Font font;
	font.loadFromFile("impact.ttf");
	Text autor(text, font, 20);
	autor.setFillColor(Color::Black);
	autor.setPosition(Vector2f(setposition.x +25 + x,setposition.y +3+y)) ;
	

	window.draw(autor);
}



Button_color::~Button_color(void)
{
}
