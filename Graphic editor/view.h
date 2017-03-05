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
	Button* button7;

	Image pic;
	Texture texture;
	Sprite sprite;

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
	bool isMenu, GlobalMenu;
	Vector2f position;
	Vector2f position_top;
	RectangleShape scene;

	RectangleShape line;
	int menuNum;

	
public:

	void draw(RenderWindow &window);
	void open(RenderWindow &window, int flag);
	void save(RenderWindow &window, int flag);
	void drawLine(RenderWindow &window, int flag);
	void setColor(int &color, RenderWindow &window);
	void drawPoint(RenderWindow & window, int flag);
	void drawFill(RenderWindow & window, int flag);




	void floodFill(Image &im, float x, float y, Color old, Color fill);
	void drawRectangle(RenderWindow & window, int flag);
	void drawCircle(RenderWindow & window, int flag);
	void drawText(RenderWindow & window, int flag);
	void drawErace(RenderWindow & window, int flag);
	void root(RenderWindow &window);
	view(RenderWindow& window);
	~view(void);
	
};

