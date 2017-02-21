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

