#include "view.h"


int main()
{

	//// Create a new render-window
	//sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	//// Create a new render-texture
	//sf::Texture texture;
	//if (!texture.loadFromFile("test.png"))
	//	return -1;
	//sf::Sprite sprite1;
	//sprite1.setTexture(texture);
	//sprite1.setPosition(100, 100);
	//sf::RenderTexture texture1;
	//Font font;
	//font.loadFromFile("impact.ttf");
	//Text autor("1235", font, 14);
	//autor.setFillColor(Color::White);
	//autor.setPosition(100, 100);

	//if (!texture.create(500, 500))
	//	return -1;
	//// The main loop
	//while (window.isOpen())
	//{
	//	// Event processing
	//	// ...
	//	// Clear the whole texture with red color
	//	
	//	// Draw stuff to the texture
	//	texture1.draw(autor);
	//	
	//						   // We're done drawing to the texture
	//	texture1.display();
	//	// Now we start rendering to the window, clear it first
	//	//window.clear(Color::White);
	//	// Draw the texture
	//	//sf::Sprite sprite(texture1.getTexture());
	//	///window.draw(sprite);
	//	// End the current frame and display its contents on screen
	//	window.display();
	//}
	RenderWindow window(VideoMode(800, 600), "Paint SFML", Style::Titlebar | Style::Close);
	
	view scene(window);
	scene.draw(window);
	

return 0;
}

