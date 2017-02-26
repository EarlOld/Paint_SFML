#pragma once



#include "Button.h"
#include "Text.h"

using namespace sf;

class view
{
private:
	RenderTexture *rtexture;
	Button* button;
	Button* button1;
	Button* button2;
	Button* button3;
	Button* button4;
	Button* button5;
	Button* button6;

	Button_top* Button_top1;
	Button_top* Button_top2;
	Button_top* Button_top3;
	Button_top* Button_top4;
	Button_top* Button_top5;
	Button_top* Button_top6;

	Button_color* button_color;
	Button_color* button_color1;
	Button_color* button_color6;
	Button_color* button_color3;
	Button_color* button_color4;
	Button_color* button_color5;
	bool isMenu;
	Vector2f position;
	Vector2f position_top;
	RectangleShape scene;
	//RectangleShape button;
	RectangleShape line;
	int menuNum;

	
public:

	void draw(RenderWindow &window);
	void drawLine(RenderWindow &window, int flag);
	void drawPoint(RenderWindow & window, int flag);
	void drawRectangle(RenderWindow & window, int flag);
	void drawCircle(RenderWindow & window, int flag);
	void drawText(RenderWindow & window, int flag);
	void drawErace(RenderWindow & window, int flag);
	view(RenderWindow& window);
	~view(void);
	
};

