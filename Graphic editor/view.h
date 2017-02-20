#pragma once



#include "Button.h"


using namespace sf;

class view
{
private:
	
	Button* button;
	Button* button1;
	Vector2f position;
	RectangleShape scene;
	//RectangleShape button;
	RectangleShape line;
	int menuNum = 0;

	void draw(RenderWindow &window);
public:
	view(RenderWindow& window);
	~view(void);
	
};

