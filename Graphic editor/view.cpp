#include "view.h"


view::view(RenderWindow &window)
{
	//RectangleShape scene;
	scene.setSize(Vector2f(650, 550));
	scene.setOutlineColor(Color(150,150,150,155));
	scene.setOutlineThickness(2);
	scene.setPosition(20, 30);
	scene.setFillColor(Color::White);

	button.setSize(Vector2f(90, 30));
	button.setOutlineColor(Color::Red);
	button.setOutlineThickness(2);
	button.setPosition(690, 35);
	button.setFillColor(Color::White);

	line.setSize(Vector2f(80, 20));
	line.setOutlineColor(Color::Red);
	line.setOutlineThickness(1);
	line.setPosition(695, 40);
	line.setFillColor(Color::Transparent);
	button.setTextureRect(sf::IntRect(90, 30, 690, 35));

	draw(window);
	
}


view::~view(void)
{
}
void view::draw(RenderWindow &window)
{
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			
				sf::Mouse::setPosition(sf::Vector2i(0, 0), window);

		window.clear(Color(205,215,230,255));
		window.draw(scene);
		window.draw(button);
		window.draw(line);
		window.display();
	}



}
