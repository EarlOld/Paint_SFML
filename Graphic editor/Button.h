#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class Button
{
protected:
	RectangleShape button;
	const Texture *bg1, *bg2;
	bool sw;
	
public:
	Button(const Texture * 	texture1,const Texture * 	texture2 );
	~Button(void);
};

