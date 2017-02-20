#include "view.h"


view::view(RenderWindow &window)
{
	
	scene.setSize(Vector2f(650, 550));
	scene.setOutlineColor(Color(150,150,150,155));
	scene.setOutlineThickness(2);
	scene.setPosition(20, 30);
	scene.setFillColor(Color::White);

	//button.setSize(Vector2f(90, 30));
	//button.setOutlineColor(Color::Red);
	//button.setOutlineThickness(2);
	//button.setPosition(690, 35);
	//button.setFillColor(Color::White);
	position.x = 690; position.y = 35;

	Image heroimage; //создаем объект Image (изображение)
	
	
	button = new Button("Start", 690, 35, window);
	button1 = new Button("Exit", position.x, position.y + 90 , window);

	//line.setSize(Vector2f(80, 20));
	//line.setOutlineColor(Color::Red);
	//line.setOutlineThickness(1);
	//line.setPosition(695, 40);
	//line.setFillColor(Color::Transparent);
	//button.setTextureRect(sf::IntRect(90, 30, 690, 35));

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
		if (IntRect(690, 35, 90, 30).contains(Mouse::getPosition(window))) { menuNum = 1; button->button.setFillColor(Color::Blue); }
		if (!IntRect(690, 35, 90, 30).contains(Mouse::getPosition(window))) {button->button.setFillColor(Color::White); }
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) scene.setFillColor(Color::Black); //если нажали первую кнопку, то выходим из меню 
			
		}

		window.clear(Color(205,215,230,255));
		button->show(window);
		button1->show(window);
		window.draw(scene);
		
		window.display();
	}



}
