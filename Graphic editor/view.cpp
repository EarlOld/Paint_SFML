#include "view.h"


view::view(RenderWindow &window)
{
	menuNum = 0;
	isMenu = 1;
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
	
	
	button = new Button("Point",position.x, position.y  , window);
	button1 = new Button("Line", position.x, position.y + 45 , window);
	button2 = new Button("Rectangl", position.x, position.y + 45 + 45 , window);
	button3 = new Button("Circle", position.x, position.y + 45 + 45 + 45 , window);
	button4 = new Button("Text", position.x, position.y + 45 + 45 + 45 + 45 , window);
	button5 = new Button("Cls", position.x, position.y + 45 + 45 + 45 + 45 + 45, window);
	//line.setSize(Vector2f(80, 20));
	//line.setOutlineColor(Color::Red);
	//line.setOutlineThickness(1);
	//line.setPosition(695, 40);
	//line.setFillColor(Color::Transparent);
	//button.setTextureRect(sf::IntRect(90, 30, 690, 35));

	Font font;
	font.loadFromFile("impact.ttf");


	draw(window);
	
}


view::~view(void)
{
}

FocusController fc;
void view::draw(RenderWindow &window)
{
	Font font;
	font.loadFromFile("impact.ttf");
	Text text;
	text.setFont(font);
	text.setPosition(200,200);
	text.setString(L"My string");
	int x = 0;
	TextBox tb(text);
	
	fc.setFocusObject(&tb);
	int flag = 0;
	while (window.isOpen())
	{


		

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

//-------------------------------------------------Point-----------------------------------------------------	
		if (IntRect(position.x, position.y, 90, 30).contains(Mouse::getPosition(window)))
			{
				menuNum = 1; button->button.setFillColor((Color(180,180,180,155))); std::cout << menuNum << std::endl;

				if (Mouse::isButtonPressed(Mouse::Left))
				{
					if (menuNum == 1) 

						{
						if (flag == 0)
						{
							isMenu = true; 
							std::cout << "isMenu"<< isMenu << std::endl;
							flag++;
						}
						while(isMenu){
						
						if(IntRect(20, 30, 650, 550).contains(Mouse::getPosition(window)))
								if (Mouse::isButtonPressed(Mouse::Left))
								{
									flag = 0;
									Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
									Vector2f pos = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд ок
									RectangleShape tmp;
									tmp.setSize(Vector2f(1, 1));
									tmp.setPosition(pos.x, pos.y);
									tmp.setFillColor(Color::Black);
									window.draw(tmp);
		
									window.display();
								}
							if (flag == 0)
							{	  
							if (IntRect(position.x, position.y + 45 + 45 + 45 + 45 + 45, 90, 30).contains(Mouse::getPosition(window))) 
							if (Mouse::isButtonPressed(Mouse::Left)) {isMenu = false; std::cout << "isMenu"<< isMenu << std::endl;}
							}
						}
					}
				
				}

			}
		else if (!IntRect(position.x, position.y, 90, 30).contains(Mouse::getPosition(window))) { menuNum = 0; button->button.setFillColor(Color::White); std::cout << menuNum << std::endl;}
		
//-------------------------------------------------Line-----------------------------------------------------		
		if (IntRect(position.x, position.y + 45, 90, 30).contains(Mouse::getPosition(window))) 
		{
			menuNum = 2; button1->button.setFillColor((Color(180,180,180,155))); std::cout << menuNum << std::endl;
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (menuNum == 2)
					{
						if (flag == 0)
						{
							isMenu = true; 
							std::cout << "isMenu"<< isMenu << std::endl;
							flag++;
						}
						Vector2f start, finish;
						while(isMenu){
						
						if(IntRect(20, 30, 650, 550).contains(Mouse::getPosition(window)))
						{
							

							if (Mouse::isButtonPressed(Mouse::Left))
							{
								Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
								start = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд ок
								
							}


							if (Mouse::isButtonPressed(Mouse::Right))
							{
								Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
								finish = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд ок
								std::cout << "isStart "<< start.x << "\t" << start.y << std::endl;
								std::cout << "isFinish "<< finish.x << "\t" << finish.y << std::endl;
									flag = 0;
									sf::Vertex line[2];
					
									line[0].position = start;
									line[0].color  = sf::Color::Red;
									line[1].position = finish;
									line[1].color = sf::Color::Red;
								
									window.draw(line, 2, sf::Lines);
									/*RectangleShape line(Vector2f(1, finish.x-start.x));
									line.rotate(90);
									line.setPosition(start.x, start.y);
									
									line.setFillColor(Color::Black);
									window.draw(line);*/
		
									window.display();
								}
						}
							if (flag == 0)
							{	  
							if (IntRect(position.x, position.y + 45 + 45 + 45 + 45 + 45, 90, 30).contains(Mouse::getPosition(window))) 
							if (Mouse::isButtonPressed(Mouse::Left)) {isMenu = false; std::cout << "isMenu"<< isMenu << std::endl;}
							}
						}
					}
					
			}

		}
		else if (!IntRect(position.x, position.y + 45 , 90, 30).contains(Mouse::getPosition(window))) {menuNum; button1->button.setFillColor(Color::White); std::cout << menuNum << std::endl;  menuNum = 0;}
		
//-------------------------------------------------Rectangl-----------------------------------------------------
		if (IntRect(position.x, position.y + 45 + 45, 90, 30).contains(Mouse::getPosition(window))) 
		{
			menuNum = 3; button2->button.setFillColor((Color(180,180,180,155))); std::cout << menuNum << std::endl;
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (menuNum == 3)
					{
						if (flag == 0)
						{
							isMenu = true; 
							std::cout << "isMenu"<< isMenu << std::endl;
							flag++;
						}
						Vector2f start, finish;
						while(isMenu){
						
						if(IntRect(20, 30, 650, 550).contains(Mouse::getPosition(window)))
						{
							

							if (Mouse::isButtonPressed(Mouse::Left))
							{
								Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
								start = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд ок
								
							}


							if (Mouse::isButtonPressed(Mouse::Right))
							{
								Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
								finish = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд ок
								std::cout << "isStart "<< start.x << "\t" << start.y << std::endl;
								std::cout << "isFinish "<< finish.x << "\t" << finish.y << std::endl;
									flag = 0;
									sf::Vertex line[2];
					
									RectangleShape rectangle(Vector2f(finish.x-start.x, finish.y-start.y));
									rectangle.setOutlineColor(sf::Color::Red);
									rectangle.setFillColor(Color::Transparent);
									rectangle.setOutlineThickness(2);
									rectangle.setPosition(start);
									window.draw(rectangle);
		
									window.display();
								}
						}
							if (flag == 0)
							{	  
							if (IntRect(position.x, position.y + 45 + 45 + 45 + 45 + 45, 90, 30).contains(Mouse::getPosition(window))) 
							if (Mouse::isButtonPressed(Mouse::Left)) {isMenu = false; std::cout << "isMenu"<< isMenu << std::endl;}
							}
						}
					}
					
			}
			}

		}
		else if (!IntRect(position.x, position.y + 45 + 45, 90, 30).contains(Mouse::getPosition(window))) {menuNum; button2->button.setFillColor(Color::White); std::cout << menuNum << std::endl;  menuNum = 0;}
		
//-------------------------------------------------Circle-----------------------------------------------------
		if (IntRect(position.x, position.y + 45 + 45 + 45, 90, 30).contains(Mouse::getPosition(window))) 
		{
			menuNum = 4; button3->button.setFillColor((Color(180,180,180,155))); std::cout << menuNum << std::endl;
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (menuNum == 4)
					{
						if (flag == 0)
						{
							isMenu = true; 
							std::cout << "isMenu"<< isMenu << std::endl;
							flag++;
						}
						Vector2f start, finish;
						while(isMenu){
						
						if(IntRect(20, 30, 650, 550).contains(Mouse::getPosition(window)))
						{
							if (Mouse::isButtonPressed(Mouse::Left))
							{
								Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
								start = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд ок
													}
							
							if (Mouse::isButtonPressed(Mouse::Right))
							{
								
								Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
								finish = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд ок
								std::cout << "isStart "<< start.x << "\t" << start.y << std::endl;
								std::cout << "isFinish "<< finish.x << "\t" << finish.y << std::endl;
									flag = 0;
								
									int radius = sqrt((finish.y - start.y)*(finish.y - start.y) + (finish.x - start.x)*(finish.x - start.x));
									if(start.x + radius < 670 )
										if(start.x - radius > 20)
											if(start.y + radius < 580)
												if(start.y - radius > 30)
									{
									CircleShape circle;
									circle.setRadius(radius);

									circle.setOutlineColor(sf::Color::Red);
									circle.setOutlineThickness(2);
									circle.setPosition(Vector2f(start.x - radius, start.y - radius));
									circle.setFillColor(Color::Transparent);
									std::cout << "Radius "<< sqrt((finish.y - start.y)*(finish.y - start.y) + (finish.x - start.x)*(finish.x - start.x)) << std::endl;
									window.draw(circle);
		
									window.display();
									}
								}
						}
							if (flag == 0)
							{	  
							if (IntRect(position.x, position.y + 45 + 45 + 45 + 45 + 45, 90, 30).contains(Mouse::getPosition(window))) 
							if (Mouse::isButtonPressed(Mouse::Left)) {isMenu = false; std::cout << "isMenu"<< isMenu << std::endl;}
							}
						}
					}
					
			}
			}
			}

		}
		else if (!IntRect(position.x, position.y + 45+ 45+ 45, 90, 30).contains(Mouse::getPosition(window))) {menuNum; button3->button.setFillColor(Color::White); std::cout << menuNum << std::endl;  menuNum = 0;}
		
//-------------------------------------------------Text-----------------------------------------------------
		if (IntRect(position.x, position.y + 45+ 45+ 45+ 45, 90, 30).contains(Mouse::getPosition(window))) 
		{
			menuNum = 5; button4->button.setFillColor((Color(180,180,180,155))); std::cout << menuNum << std::endl;
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				
					if (menuNum == 5)
					{
						if (flag == 0)
						{
							isMenu = true; 
							std::cout << "isMenu"<< isMenu << std::endl;
							flag++;
						}
						Vector2f start, finish;
					while(isMenu)
					{
						
					Event event1;
					while (window.pollEvent(event1))
								{
								std::cout << "event1 "<< std::endl;
								FocusObject * fo = fc.getFocusObject();
								if(fo != 0)
									fo->event(event1);
								}
						if(IntRect(20, 30, 650, 550).contains(Mouse::getPosition(window)))
						{
							if (Mouse::isButtonPressed(Mouse::Left))
							{
								flag = 0;
								Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
								start = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд ок
								std::cout << "isStart "<< start.x << "\t" << start.y << std::endl;
								//text.setPosition(start);
								
							
								

							
							
							//}
							}
							
						}
						
						scene.setFillColor(Color::White);
						window.draw(scene);
						window.draw(tb);
						
						window.display();
						if (flag == 0)
							{	  
							if (IntRect(position.x, position.y + 45 + 45 + 45 + 45 + 45, 90, 30).contains(Mouse::getPosition(window))) 
							if (Mouse::isButtonPressed(Mouse::Left)) {isMenu = false; std::cout << "isMenu"<< isMenu << std::endl;}
							}
					}
							
						}
					}

					
			}

		
		else if (!IntRect(position.x, position.y + 45+ 45+ 45+ 45, 90, 30).contains(Mouse::getPosition(window))) {menuNum; button4->button.setFillColor(Color::White); std::cout << menuNum << std::endl;  menuNum = 0;}
		

		window.clear(Color(205,215,230,255));
		button->show(window, 0, 0);
		button1->show(window, 0, 0);
		button2->show(window, -20, 0);
		button3->show(window, 0, 0);
		button4->show(window, 0, 0);
		button5->show(window, 0, 0);
		window.draw(scene);
		
		window.display();
	}



}
