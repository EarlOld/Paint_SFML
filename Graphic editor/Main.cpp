#include "view.h"



int main()
{
	RenderWindow window(VideoMode(800, 600), "Paint SFML", Style::Titlebar | Style::Close);
	
	view scene(window);


	return 0;
}

//
//int main()
//{
//    sf::RenderWindow app(sf::VideoMode(800, 600), L"SFML window");
//     sf::String m_newText ;
//    while (app.isOpen())
//    {
//        sf::Event event;
//        while (app.pollEvent(event))
//        {
//            // Close window : exit
//            if (event.type == sf::Event::Closed)
//                app.close();
//        }
//        app.clear();
//        
//        app.display();
//    }
// 
//}