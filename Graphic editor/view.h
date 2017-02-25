#pragma once



#include "Button.h"
#include "Text.h"

using namespace sf;

class view
{
private:
	
	Button* button;
	Button* button1;
	Button* button2;
	Button* button3;
	Button* button4;
	Button* button5;
	Button* button6;
	Button_color* button_color;
	Button_color* button_color1;
	Button_color* button_color6;
	Button_color* button_color3;
	Button_color* button_color4;
	Button_color* button_color5;
	bool isMenu;
	Vector2f position;
	RectangleShape scene;
	//RectangleShape button;
	RectangleShape line;
	int menuNum;

	
public:

	void draw(RenderWindow &window);
	view(RenderWindow& window);
	~view(void);
	
};

