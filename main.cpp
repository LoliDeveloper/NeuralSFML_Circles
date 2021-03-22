#include <SFML/Graphics.hpp>
#include <iostream>
#include "Circle.cpp"
#include "MyFunctions.cpp"

int main()
{
	//Circle circle = Circle();
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		//window.draw(/*circle.Shape*/);
		window.display();
	}

	return 0;
}