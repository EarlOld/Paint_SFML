#include "Button.h"


Button::Button(const Texture *texture1, const Texture *texture2): bg1(texture1), bg2(texture2), sw(false)
{
	button.setSize(Vector2f(90, 50));

}


Button::~Button(void)
{
}
