#include "view.h"


view::view(RenderWindow &window)
{

	menuNum = 40;
	isMenu = true;
	GlobalMenu = false;
	scene.setSize(Vector2f(650, 550));
	scene.setOutlineColor(Color(150,150,150,155));
	scene.setOutlineThickness(2);
	
	rtexture = new RenderTexture;
	rtexture->create(670, 580);
	rtexture->clear(Color::White);

	scene.setPosition(20, 30);
	scene.setFillColor(Color::White);

	position.x = 690; position.y = 35;
	position_top.x = 30; position_top.y = 5;

	button = new Button("Point",position.x, position.y  , window);
	button1 = new Button("Line", position.x, position.y + 45 , window);
	button2 = new Button("Rectangl", position.x, position.y + 45 + 45 , window);
	button3 = new Button("Circle", position.x, position.y + 45 + 45 + 45 , window);
	button4 = new Button("Text", position.x, position.y + 45 + 45 + 45 + 45 , window);
	button5 = new Button("Erase", position.x, position.y + 45 + 45 + 45 + 45 + 45, window);
	button6 = new Button("Fill", position.x, position.y + 45 + 45 + 45 + 45 + 45 + 45, window);
	button7 = new Button("Clean", position.x, position.y + 45 + 45 + 45 + 45 + 45 + 45 + 45, window);

	Button_top1 = new Button_top("Open", position_top.x , position_top.y, window);
	Button_top2 = new Button_top("Save", position_top.x  + 60, position_top.y, window);
	Button_top3 = new Button_top("Copy", position_top.x + 60 + 60, position_top.y, window);
	Button_top4 = new Button_top("Extr", position_top.x  + 60 + 60 + 60, position_top.y, window);
	Button_top5 = new Button_top("Past", position_top.x  + 60 + 60 + 60 + 60, position_top.y, window);
	
	

	button_color = new Button_color("",position.x, position.y + 45 + 45 + 45 + 45 + 45 + 45 + 45 + 45+ 45,Color::Green, window);
	button_color1 = new Button_color("",position.x + 30, position.y + 45 + 45 + 45 + 45 + 45 + 45 + 45 + 45+ 45,Color::Red, window);
	button_color6 = new Button_color("",position.x + 30 + 30, position.y + 45 + 45 + 45 + 45 + 45 + 45 + 45 + 45+ 45,Color::Blue, window);
	button_color3 = new Button_color("",position.x, position.y + 45 + 45 + 45 + 45 + 45 + 45 + 45+ 45,Color::Cyan, window);
	button_color4 = new Button_color("",position.x + 30, position.y + 45 + 45 + 45 + 45 + 45 + 45 + 45+ 45,Color::Magenta, window);
	button_color5 = new Button_color("",position.x + 30 + 30, position.y + 45 + 45 + 45 + 45 + 45 + 45 + 45+ 45,Color::Yellow, window);

	

	Font font;
	font.loadFromFile("impact.ttf");
	
}

view::~view(void)
{

		delete button;
		delete button1;
		delete button2;
		delete button3;
		delete button4;
		delete button5;
		delete button6;
		delete button7;

		delete Button_top1;
		delete Button_top2;
		delete Button_top3;
		delete Button_top4;
		delete Button_top5;

		delete button_color;
		delete button_color1;
		delete button_color6;
		delete button_color3;
		delete button_color4;
		delete button_color5;
}
FocusController fc;
FocusController ff;
void view::draw(RenderWindow &window)
{
	
	
	int flag = 0, color = 0, sc = 0;
	
	while (window.isOpen())
	{

		
		window.clear(Color(205, 215, 230, 255));
		button->show(window, 0, 0);
		button1->show(window, 0, 0);
		button2->show(window, -20, 0);

		button_color->show(window, 0, 0);
		button_color1->show(window, 0, 0);
		button_color6->show(window, 0, 0);
		button_color3->show(window, 0, 0);
		button_color4->show(window, 0, 0);
		button_color5->show(window, 0, 0);

		Button_top1->show(window, 0, 0);
		Button_top2->show(window, 0, 0);
		Button_top3->show(window, 0, 0);
		Button_top4->show(window, 0, 0);
		Button_top5->show(window, 0, 0);
	
		button3->show(window, -5, 0);
		button4->show(window, -3, 0);
		button5->show(window, -5, 0);
		button6->show(window, 3, 0);
		button7->show(window, -5, 0); 
		if (sc == 0) {
			window.draw(scene); 
		}
		window.draw(sprite);
		
		window.display();

		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)
				window.close();
		}
		if (Mouse::isButtonPressed(Mouse::Left)) GlobalMenu = true;
		while (GlobalMenu)
		{
			
				Event event;
			while (window.pollEvent(event))
			{

				if (event.type == Event::Closed)
					window.close();
			}
		//-----------------------------------Open------------------------------------------------------------------
			if (IntRect(position_top.x, position_top.y, 50, 20).contains(Mouse::getPosition(window)))
			{
				sc++;
				Button_top2->button.setFillColor((Color(180, 180, 180, 155)));
				std::cout << menuNum << std::endl;
				menuNum = 10;

				if (Mouse::isButtonPressed(Mouse::Left)) if (menuNum == 10) open(window, flag);
			}

			else if (!IntRect(position_top.x, position_top.y, 50, 20).contains(Mouse::getPosition(window))) { menuNum = 0; Button_top2->button.setFillColor(Color::White); std::cout << menuNum << std::endl; }
	//-----------------------------------Save------------------------------------------------------------------
			if (IntRect(position_top.x + 60, position_top.y,50, 20).contains(Mouse::getPosition(window)))
			{
				sc++;
				Button_top2->button.setFillColor((Color(180, 180, 180, 155)));
				std::cout << menuNum << std::endl;
				menuNum = 10;

				if (Mouse::isButtonPressed(Mouse::Left)) if (menuNum == 10) save(window, flag);
			}

			else if (!IntRect(position_top.x + 60, position_top.y, 50, 20).contains(Mouse::getPosition(window))) { menuNum = 0; Button_top2->button.setFillColor(Color::White); std::cout << menuNum << std::endl; }

	//-------------------------------------------------Point-----------------------------------------------------	

			if (IntRect(position.x, position.y, 90, 30).contains(Mouse::getPosition(window)))
			{
			
				sc++;
				std::cout << menuNum << std::endl;
				menuNum = 1;
			
				if (Mouse::isButtonPressed(Mouse::Left)) if (menuNum == 1)  
				{

				/*	button->setColor((Color(180, 180, 180, 155)));
					button1->setColor((Color::White));
					button2->setColor((Color::White));
					button3->setColor((Color::White));
					button4->setColor((Color::White));
					button5->setColor((Color::White));
					button6->setColor((Color::White));
					button7->setColor((Color::White));
					button->show(window, 0, 0);
					button1->show(window, 0, 0);
					button2->show(window, -20, 0);
					button3->show(window, -5, 0);
					button4->show(window, -3, 0);
					button5->show(window, -5, 0);
					button6->show(window, 3, 0);
					button7->show(window, -5, 0);*/
					Button_top2->show(window, 0, 0);
					drawPoint(window, flag);
				}
					
				

			
			}
				
			else if (!IntRect(position.x, position.y, 90, 30).contains(Mouse::getPosition(window))) { menuNum = 0;  std::cout << menuNum << std::endl; }
	//-------------------------------------------------Line-----------------------------------------------------		
			if (IntRect(position.x, position.y + 45, 90, 30).contains(Mouse::getPosition(window)))
			{
				menuNum = 2;
				
				std::cout << menuNum << std::endl;
				if (Mouse::isButtonPressed(Mouse::Left)) if (menuNum == 2)
				{
					sc++;
					/*button->setColor((Color::White));
					button1->setColor((Color(180, 180, 180, 155)));
					button2->setColor((Color::White));
					button3->setColor((Color::White));
					button4->setColor((Color::White));
					button5->setColor((Color::White));
					button6->setColor((Color::White));
					button7->setColor((Color::White));
			
					button->show(window, 0, 0);
					button1->show(window, 0, 0);
					button2->show(window, -20, 0);
					button3->show(window, -5, 0);
					button4->show(window, -3, 0);
					button5->show(window, -5, 0);
					button6->show(window, 3, 0);
					button7->show(window, -5, 0);
					Button_top2->show(window, 0, 0);*/
					drawLine(window, flag);
				}
			}
			else if (!IntRect(position.x, position.y + 45 , 90, 30).contains(Mouse::getPosition(window))) {menuNum; std::cout << menuNum << std::endl;  menuNum = 0;}
		
	//-------------------------------------------------Rectangl-----------------------------------------------------
			if (IntRect(position.x, position.y + 45 + 45, 90, 30).contains(Mouse::getPosition(window))) 
			{
				menuNum = 3;
				
				std::cout << menuNum << std::endl;

				if (Mouse::isButtonPressed(Mouse::Left)) if (menuNum == 3)
				{
					sc++;
					drawRectangle(window, flag);
				}
			
			}
			else if (!IntRect(position.x, position.y + 45 + 45, 90, 30).contains(Mouse::getPosition(window))) {menuNum;  std::cout << menuNum << std::endl;  menuNum = 0;}
		
	//-------------------------------------------------Circle-----------------------------------------------------
			if (IntRect(position.x, position.y + 45 + 45 + 45, 90, 30).contains(Mouse::getPosition(window))) 
			{
				menuNum = 4;
				
				std::cout << menuNum << std::endl;
				sc++;
				if (Mouse::isButtonPressed(Mouse::Left)) if (menuNum == 4) 	drawCircle(window, flag);
			}
			else if (!IntRect(position.x, position.y + 45+ 45+ 45, 90, 30).contains(Mouse::getPosition(window))) {menuNum;  std::cout << menuNum << std::endl;  menuNum = 0;}
		
	//-------------------------------------------------Text-----------------------------------------------------
			if (IntRect(position.x, position.y+45 + 45+ 45+ 45, 90, 30).contains(Mouse::getPosition(window))) 
			{
				menuNum = 5;
				
				std::cout << menuNum << std::endl;
				sc++;
				if (Mouse::isButtonPressed(Mouse::Left)) if (menuNum == 5) drawText(window, flag);
				}

			else if (!IntRect(position.x, position.y + 45+ +45+45+ 45, 90, 30).contains(Mouse::getPosition(window))) {menuNum;  std::cout << menuNum << std::endl;  menuNum = 0;}
	//-------------------------------------------------Erase---------------------------------------------------------------------
			if (IntRect(position.x, position.y + 45 + 45 + 45 + 45 + 45, 90, 30).contains(Mouse::getPosition(window)))
			{
				menuNum = 6;
				sc++;
				std::cout << menuNum << std::endl;

				if (Mouse::isButtonPressed(Mouse::Left)) if (menuNum == 6) 
				{
					drawErace(window, flag);
				}
				
			}

			else if (!IntRect(position.x, position.y + 45 + 45 + 45 + 45 + 45, 90, 30).contains(Mouse::getPosition(window))) { menuNum;  std::cout << menuNum << std::endl;  menuNum = 0; }

	//-------------------------------------------------Erase---------------------------------------------------------------------
			if (IntRect(position.x, position.y + 45 + 45 + 45 + 45 + 45 + 45, 90, 30).contains(Mouse::getPosition(window)))
			{
				menuNum = 6;
				sc++;
				std::cout << menuNum << std::endl;

				if (Mouse::isButtonPressed(Mouse::Left)) if (menuNum == 6)
				{
					drawFill(window, flag);
				}

			}

			else if (!IntRect(position.x, position.y + 45 + 45 + 45 + 45 + 45, 90, 30).contains(Mouse::getPosition(window))) { menuNum;  std::cout << menuNum << std::endl;  menuNum = 0; }

	//---------------------------------------------------------Clean------------------------------------------------------------------------
			if (IntRect(position.x, position.y + 45 + 45 + 45 + 45 + 45 + 45 + 45, 90, 30).contains(Mouse::getPosition(window)))
			{
				menuNum = 14;
				
				std::cout << menuNum << std::endl;

				if (Mouse::isButtonPressed(Mouse::Left)) 
					if (menuNum == 14) 
					{
						isMenu = false; GlobalMenu = false;
						sc++;
						rtexture->clear(Color::White);;
						
						pic = rtexture->getTexture().copyToImage();
						pic.flipVertically();
						Texture texture;
						texture.loadFromImage(pic, IntRect(22, 32, 648, 548));
						sprite.setTexture(texture);
						sprite.setPosition(Vector2f(22, 32));
						window.draw(sprite);
						window.display();
					
					}
					
			}
			else if (!IntRect(position.x, position.y + 45 + 45 + 45 + 45 + 45 + 45 + 45, 90, 30).contains(Mouse::getPosition(window))) { menuNum;  std::cout << menuNum << std::endl;  menuNum = 0; }
			
			
			}
	
	}
}

void view::open(RenderWindow & window, int flag)
{
	Font font;
	font.loadFromFile("arial.ttf");
	Text text1("Input name: ", font, 14);
	text1.setPosition(30, 583);
	text1.setFillColor(Color::Black);
	std::string name;

	Text text(" ", font, 12);

	text.setPosition(105, 583);

	int x = 0;
	TextBox tb(text);

	fc.setFocusObject(&tb);

	while (!Keyboard::isKeyPressed(Keyboard::Key::Return))
	{

		Event event1;

		while (window.pollEvent(event1))
		{
			flag = 0;
			std::cout << "event1 " << std::endl;
			FocusObject * fo = fc.getFocusObject();
			if (fo != 0)
				fo->event(event1);
		}
		name = tb.GetText();
		window.draw(tb);
		window.draw(text1);
		window.display();
	}

	Image image;
	image.loadFromFile(name);


	texture.loadFromImage(image);


	scene.setTexture(&texture);
	rtexture->draw(scene);
	pic = rtexture->getTexture().copyToImage();
	pic.flipVertically();
	Texture texture1;
	texture1.loadFromImage(pic, IntRect(22, 32, 648, 548));
	sprite; sprite.setTexture(texture1);
	sprite.setPosition(Vector2f(22, 32));
	window.draw(sprite);

	window.display();
}

void view::save(RenderWindow & window, int flag)
{
	menuNum = 1;


	Font font;
	font.loadFromFile("arial.ttf");
	Text text1("Input name: ", font, 14);
	text1.setPosition(30, 583);
	text1.setFillColor(Color::Black);
	std::string name;

	Text text(" ", font, 12);

	text.setPosition(105, 583);

	int x = 0;
	TextBox tb(text);

	fc.setFocusObject(&tb);

	while (!Keyboard::isKeyPressed(Keyboard::Key::Return))
	{

		Event event1;

		while (window.pollEvent(event1))
		{
			flag = 0;
			std::cout << "event1 " << std::endl;
			FocusObject * fo = fc.getFocusObject();
			if (fo != 0)
				fo->event(event1);
		}
		name = tb.GetText();
		window.draw(tb);
		window.draw(text1);
		window.display();
	}


	pic = rtexture->getTexture().copyToImage();
	pic.flipVertically();

	texture.loadFromImage(pic, IntRect(22, 32, 648, 548));

	Image pic1 = texture.copyToImage();


	pic1.saveToFile(name);



}

void view::drawLine(RenderWindow & window, int flag)
{
	if (flag == 0)
	{
		isMenu = true;
		std::cout << "isMenu" << isMenu << std::endl;
		flag++;
	}
	Vector2f start, finish;
	int color = 0;
	while (isMenu)
	{

		setColor(color, window);

		if (IntRect(20, 30, 650, 550).contains(Mouse::getPosition(window)))
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
				std::cout << "isStart " << start.x << "\t" << start.y << std::endl;
				std::cout << "isFinish " << finish.x << "\t" << finish.y << std::endl;
				flag = 0;
				sf::Vertex line[2];

				line[0].position = start;

				line[1].position = finish;

				if (color == 0) { line[0].color = sf::Color::Black; line[1].color = sf::Color::Black; }
				if (color == 1) { line[0].color = sf::Color::Green; line[1].color = sf::Color::Green; }
				if (color == 2) { line[0].color = sf::Color::Red; line[1].color = sf::Color::Red; }
				if (color == 3) { line[0].color = sf::Color::Blue; line[1].color = sf::Color::Blue; }
				if (color == 4) { line[0].color = sf::Color::Cyan; line[1].color = sf::Color::Cyan; }
				if (color == 5) { line[0].color = sf::Color::Magenta; line[1].color = sf::Color::Magenta; }
				if (color == 6) { line[0].color = sf::Color::Yellow; line[1].color = sf::Color::Yellow; }
				
				
				rtexture->draw(line, 2, sf::Lines);
				//window.draw(line, 2, sf::Lines);
				 pic = rtexture->getTexture().copyToImage();
				pic.flipVertically();
				
				texture.loadFromImage(pic, IntRect(22, 32, 648, 548));
				sprite.setTexture(texture);
				sprite.setPosition(Vector2f(22, 32));
				window.draw(sprite);
				window.display();
			}
		}
		if (flag == 0)	root(window);
	}

}

void view::setColor(int &color, RenderWindow &window)
{
	if (IntRect(position.x, position.y + 45 + 45 + 45 + 45 + 45 + 45 + 45 + 45 + 45, 30, 30).contains(Mouse::getPosition(window)))
		if (Mouse::isButtonPressed(Mouse::Left))  color = 1;

	if (IntRect(position.x + 30, position.y + 45 + 45 + 45 + 45 + 45 + 45 + 45 + 45 + 45, 30, 30).contains(Mouse::getPosition(window)))
		if (Mouse::isButtonPressed(Mouse::Left)) color = 2;

	if (IntRect(position.x + 30 + 30, position.y + 45 + 45 + 45 + 45 + 45 + 45 + 45 + 45 + 45, 30, 30).contains(Mouse::getPosition(window)))
		if (Mouse::isButtonPressed(Mouse::Left))  color = 3;

	if (IntRect(position.x, position.y + 45 + 45 + 45 + 45 + 45 + 45 + 45 + 45, 30, 30).contains(Mouse::getPosition(window)))
		if (Mouse::isButtonPressed(Mouse::Left))  color = 4;

	if (IntRect(position.x + 30, position.y + 45 + 45 + 45 + 45 + 45 + 45 + 45 + 45, 30, 30).contains(Mouse::getPosition(window)))
		if (Mouse::isButtonPressed(Mouse::Left)) color = 5;

	if (IntRect(position.x + 30 + 30, position.y + 45 + 45 + 45 + 45 + 45 + 45 + 45 + 45, 30, 30).contains(Mouse::getPosition(window)))
		if (Mouse::isButtonPressed(Mouse::Left))  color = 6;

}

void view::drawPoint(RenderWindow & window, int flag)
{
	int color = 0;
	if (flag == 0)
	{
		isMenu = true;
		std::cout << "isMenu" << isMenu << std::endl;
		flag++;
	}
	
	while (isMenu) 
	{

		setColor(color, window);


		if (IntRect(20, 30, 650, 550).contains(Mouse::getPosition(window)))
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				flag = 0;

				Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
				Vector2f pos = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд ок
				RectangleShape tmp;
				tmp.setSize(Vector2f(2, 2));
				tmp.setPosition(pos.x, pos.y);
				if (color == 0) tmp.setFillColor(Color::Black);
				if (color == 1) tmp.setFillColor(Color::Green);
				if (color == 2) tmp.setFillColor(Color::Red);
				if (color == 3) tmp.setFillColor(Color::Blue);
				if (color == 4) tmp.setFillColor(Color::Cyan);
				if (color == 5) tmp.setFillColor(Color::Magenta);
				if (color == 6) tmp.setFillColor(Color::Yellow);

				rtexture->draw(tmp);
				Image pic = rtexture->getTexture().copyToImage();
				pic.flipVertically();
				Texture texture;
				texture.loadFromImage(pic, IntRect(22, 32, 648, 548));
				Sprite sprite; sprite.setTexture(texture);
				sprite.setPosition(Vector2f(22, 32));
				window.draw(sprite);
				window.display();



			}
		if (flag == 0)	root(window);
		
	}
}

void view::drawFill(RenderWindow & window, int flag)
{

	int color = 0;
	if (flag == 0)
	{
		isMenu = true;
		std::cout << "isMenu" << isMenu << std::endl;
		flag++;
	}

	while (isMenu)
	{

		setColor(color, window);


		if (IntRect(20, 30, 650, 550).contains(Mouse::getPosition(window)))
			if (Mouse::isButtonPressed(Mouse::Left))
			{
			
				flag = 0;

				Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
				Vector2f pos = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд ок


				Image pic = rtexture->getTexture().copyToImage();
				pic.flipVertically();
				Color color1 = pic.getPixel(pos.x, pos.y);
				floodFill(pic, pos.x, pos.y, color1, Color::Blue);
				

				Texture texture;
				texture.loadFromImage(pic, IntRect(22, 32, 648, 548));
				Sprite sprite; sprite.setTexture(texture);
				sprite.setPosition(Vector2f(22, 32));

				window.draw(sprite);
				window.display();
				



			}
		if (flag == 0)	root(window);

	}
}
	



void view::floodFill(Image &im, float x, float y, Color old, Color fill)
{
if (x < 670 && y < 580) {
	Color current;
	current = im.getPixel(x, y);
	if (current == old)
	{
		im.setPixel(x, y, fill);
		//delay(5);
		floodFill(im, x + 1, y, old, fill);
		floodFill(im, x - 1, y, old, fill);
		floodFill(im, x, y + 1, old, fill);
		floodFill(im, x, y - 1, old, fill);
	}
}
else return;
	
}

void view::drawRectangle(RenderWindow & window, int flag)
{
	if (flag == 0)
	{
		isMenu = true;
		std::cout << "isMenu" << isMenu << std::endl;
		flag++;
	}
	Vector2f start, finish;
	int color = 0;

	while (isMenu) 
	{
		setColor(color, window);

		if (IntRect(20, 30, 650, 550).contains(Mouse::getPosition(window)))
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
				std::cout << "isStart " << start.x << "\t" << start.y << std::endl;
				std::cout << "isFinish " << finish.x << "\t" << finish.y << std::endl;
				flag = 0;
				sf::Vertex line[2];

				RectangleShape rectangle(Vector2f(finish.x - start.x, finish.y - start.y));
				if (color == 0) rectangle.setOutlineColor(Color::Black);
				if (color == 1) rectangle.setOutlineColor(Color::Green);
				if (color == 2) rectangle.setOutlineColor(Color::Red);
				if (color == 3) rectangle.setOutlineColor(Color::Blue);
				if (color == 4) rectangle.setOutlineColor(Color::Cyan);
				if (color == 5) rectangle.setOutlineColor(Color::Magenta);
				if (color == 6) rectangle.setOutlineColor(Color::Yellow);

				rectangle.setFillColor(Color::Transparent);
				rectangle.setOutlineThickness(2);
				rectangle.setPosition(start);


				rtexture->draw(rectangle);

				 pic = rtexture->getTexture().copyToImage();
				pic.flipVertically();
				
				texture.loadFromImage(pic, IntRect(22, 32, 648, 548));
				sprite.setTexture(texture);
				sprite.setPosition(Vector2f(22, 32));
				window.draw(sprite);

				window.display();
			}
		}
		if (flag == 0)	root(window);
	}

}

void view::drawCircle(RenderWindow & window, int flag)
{
	
		if (flag == 0)
		{
			isMenu = true;
			std::cout << "isMenu" << isMenu << std::endl;
			flag++;
		}
		Vector2f start, finish;
		int color = 0;

		while (isMenu)
		{
		setColor(color, window);


			if (IntRect(20, 30, 650, 550).contains(Mouse::getPosition(window)))
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
					std::cout << "isStart " << start.x << "\t" << start.y << std::endl;
					std::cout << "isFinish " << finish.x << "\t" << finish.y << std::endl;
					flag = 0;

					int radius = sqrt((finish.y - start.y)*(finish.y - start.y) + (finish.x - start.x)*(finish.x - start.x));
					if (start.x + radius < 670)
						if (start.x - radius > 20)
							if (start.y + radius < 580)
								if (start.y - radius > 30)
								{
									CircleShape circle;
									circle.setRadius(radius);

									if (color == 0) circle.setOutlineColor(Color::Black);
									if (color == 1) circle.setOutlineColor(Color::Green);
									if (color == 2) circle.setOutlineColor(Color::Red);
									if (color == 3) circle.setOutlineColor(Color::Blue);
									if (color == 4) circle.setOutlineColor(Color::Cyan);
									if (color == 5) circle.setOutlineColor(Color::Magenta);
									if (color == 6) circle.setOutlineColor(Color::Yellow);

									circle.setOutlineThickness(2);
									circle.setPosition(Vector2f(start.x - radius, start.y - radius));
									circle.setFillColor(Color::Transparent);
									std::cout << "Radius " << sqrt((finish.y - start.y)*(finish.y - start.y) + (finish.x - start.x)*(finish.x - start.x)) << std::endl;

									rtexture->draw(circle);
									 pic = rtexture->getTexture().copyToImage();
									pic.flipVertically();
									
									texture.loadFromImage(pic, IntRect(22, 32, 648, 548));
								 sprite.setTexture(texture);
									sprite.setPosition(Vector2f(22, 32));
									window.draw(sprite);

									window.display();
								}
				}
			}
			if (flag == 0)	root(window);
		}
	
	
}

void view::drawText(RenderWindow & window, int flag)
{

	Font font;
	font.loadFromFile("impact.ttf");
	Text text;
	text.setFont(font);
	text.setPosition(200, 200);
	text.setString(L" ");
	int x = 0;
	TextBox tb(text);

	ff.setFocusObject(&tb);

		if (flag == 0)
		{
			isMenu = true;
			std::cout << "isMenu" << isMenu << std::endl;
			flag++;
		}
		Vector2f start, finish;
		int color = 0;

		while (isMenu)
		{
			setColor(color, window);
			Event event1;

			if (color == 0) tb.SetColor(Color::Black);
			if (color == 1) tb.SetColor(Color::Green);
			if (color == 2) tb.SetColor(Color::Red);
			if (color == 3) tb.SetColor(Color::Blue);
			if (color == 4) tb.SetColor(Color::Cyan);
			if (color == 5) tb.SetColor(Color::Magenta);
			if (color == 6) tb.SetColor(Color::Yellow);


			while (window.pollEvent(event1))
			{
				flag = 0;
				std::cout << "event1 " << std::endl;
				FocusObject * fo = ff.getFocusObject();
				if (fo != 0)
					fo->event(event1);
			}
			if (IntRect(20, 30, 650, 550).contains(Mouse::getPosition(window)))
			{
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
					start = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд ок
					std::cout << "isStart " << start.x << "\t" << start.y << std::endl;
					tb.SetPosition(start);

				}

			}

			rtexture->draw(tb);
			 pic = rtexture->getTexture().copyToImage();
			pic.flipVertically();
			
			texture.loadFromImage(pic, IntRect(22, 32, 648, 548));
			 sprite.setTexture(texture);
			sprite.setPosition(Vector2f(22, 32));
			window.draw(sprite);

			window.display();
			if (flag == 0)	root(window);
		}
}

void view::drawErace(RenderWindow & window, int flag)
{
	if (flag == 0)
	{
		isMenu = true;
		std::cout << "isMenu" << isMenu << std::endl;
		flag++;
	}
	
	int color = 0;

	while (isMenu)
	{
		Vector2f start;
		if (IntRect(20, 30, 650, 550).contains(Mouse::getPosition(window)))
		{
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
					start = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд ок
					std::cout << "isStart " << start.x << "\t" << start.y << std::endl;
					
					flag = 0;

					int radius = 20;
					if (start.x + radius < 670)
						if (start.x - radius > 20)
							if (start.y + radius < 580)
								if (start.y - radius > 30)
								{
									CircleShape circle;
									circle.setRadius(radius);
									circle.setOutlineThickness(2);
									circle.setOutlineColor(Color::Transparent);
									circle.setPosition(Vector2f(start.x - radius, start.y - radius));
									circle.setFillColor(Color::White);

									rtexture->draw(circle);
									 pic = rtexture->getTexture().copyToImage();
									pic.flipVertically();
									;
									texture.loadFromImage(pic, IntRect(22, 32, 648, 548));
									 sprite.setTexture(texture);
									sprite.setPosition(Vector2f(22, 32));
									window.draw(sprite);

									window.display();
								}
							
			}
		}
		if (flag == 0)	root(window);
	}
}

void view::root(RenderWindow &window)
{

	if (IntRect(position.x, position.y, 90, 30).contains(Mouse::getPosition(window))) if (Mouse::isButtonPressed(Mouse::Left)) 
	{ 
		button->setColor((Color(180, 180, 180, 155)));  isMenu = false; 
		button1->setColor((Color::White));
		button2->setColor((Color::White));
		button3->setColor((Color::White));
		button4->setColor((Color::White));
		button5->setColor((Color::White));
		button6->setColor((Color::White));
		button7->setColor((Color::White));
		
	}
	if (IntRect(position.x, position.y +45, 90, 30).contains(Mouse::getPosition(window))) if (Mouse::isButtonPressed(Mouse::Left)) 
	{
		button->setColor((Color::White));  isMenu = false;
		button1->setColor((Color(180, 180, 180, 155)));
		button2->setColor((Color::White));
		button3->setColor((Color::White));
		button4->setColor((Color::White));
		button5->setColor((Color::White));
		button6->setColor((Color::White));
		button7->setColor((Color::White));

	}
	if (IntRect(position.x, position.y + 45 + 45, 90, 30).contains(Mouse::getPosition(window))) if (Mouse::isButtonPressed(Mouse::Left)) 
	{
		button->setColor((Color::White));  isMenu = false;
		button1->setColor((Color::White));
		button2->setColor((Color(180, 180, 180, 155)));
		button3->setColor((Color::White));
		button4->setColor((Color::White));
		button5->setColor((Color::White));
		button6->setColor((Color::White));
		button7->setColor((Color::White));

	}
	if (IntRect(position.x, position.y + 45 + 45 + 45, 90, 30).contains(Mouse::getPosition(window))) if (Mouse::isButtonPressed(Mouse::Left))  
	{
		button->setColor((Color::White));  isMenu = false;
		button1->setColor((Color::White));
		button2->setColor((Color::White));
		button3->setColor((Color(180, 180, 180, 155)));
		button4->setColor((Color::White));
		button5->setColor((Color::White));
		button6->setColor((Color::White));
		button7->setColor((Color::White));

	}
	if (IntRect(position.x, position.y + 45 + 45 + 45 + 45, 90, 30).contains(Mouse::getPosition(window))) if (Mouse::isButtonPressed(Mouse::Left)) 
	{
		button->setColor((Color::White));  isMenu = false;
		button1->setColor((Color::White));
		button2->setColor((Color::White));
		button3->setColor((Color::White));
		button4->setColor((Color(180, 180, 180, 155)));
		button5->setColor((Color::White));
		button6->setColor((Color::White));
		button7->setColor((Color::White));

	}
	if (IntRect(position.x, position.y + 45 + 45 + 45 + 45 + 45, 90, 30).contains(Mouse::getPosition(window))) if (Mouse::isButtonPressed(Mouse::Left)) 
	{
		button->setColor((Color::White));  isMenu = false;
		button1->setColor((Color::White));
		button2->setColor((Color::White));
		button3->setColor((Color::White));
		button4->setColor((Color::White));
		button5->setColor((Color(180, 180, 180, 155)));
		button6->setColor((Color::White));
		button7->setColor((Color::White));

	}
	if (IntRect(position.x, position.y + 45 + 45 + 45 + 45 + 45 + 45, 90, 30).contains(Mouse::getPosition(window))) if (Mouse::isButtonPressed(Mouse::Left))  
	{
		button->setColor((Color::White));  isMenu = false;
		button1->setColor((Color::White));
		button2->setColor((Color::White));
		button3->setColor((Color::White));
		button4->setColor((Color::White));
		button5->setColor((Color::White));
		button6->setColor((Color(180, 180, 180, 155)));
		button7->setColor((Color::White));

	}
	if (IntRect(position.x, position.y + 45 + 45 + 45 + 45 + 45 + 45 + 45, 90, 30).contains(Mouse::getPosition(window))) if (Mouse::isButtonPressed(Mouse::Left))  
	{
		button->setColor((Color::White));  isMenu = false;
		button1->setColor((Color::White));
		button2->setColor((Color::White));
		button3->setColor((Color::White));
		button4->setColor((Color::White));
		button5->setColor((Color::White));
		button6->setColor((Color::White));
		button7->setColor((Color(180, 180, 180, 155)));

	}

	if (IntRect(position_top.x, position_top.y, 50, 30).contains(Mouse::getPosition(window))) if (Mouse::isButtonPressed(Mouse::Left))  isMenu = false;
	if (IntRect(position_top.x +60, position_top.y, 50, 30).contains(Mouse::getPosition(window))) if (Mouse::isButtonPressed(Mouse::Left))  isMenu = false;
	if (IntRect(position_top.x + 60 + 60, position_top.y, 50, 30).contains(Mouse::getPosition(window))) if (Mouse::isButtonPressed(Mouse::Left))  isMenu = false;
	if (IntRect(position_top.x + 60 + 60 + 60, position_top.y, 50, 30).contains(Mouse::getPosition(window))) if (Mouse::isButtonPressed(Mouse::Left))  isMenu = false;
	if (IntRect(position_top.x + 60 + 60 + 60 + 60, position_top.y, 50, 30).contains(Mouse::getPosition(window))) if (Mouse::isButtonPressed(Mouse::Left))  isMenu = false;
	
}
