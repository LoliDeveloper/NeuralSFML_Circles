#include <SFML/Graphics.hpp>
#include <iostream>
#include "Circle.h"
#include "Globals.h"

void Draw(sf::RenderWindow&);
void Update();

Circle circle = Circle(1.f, 5.f, 1.f);

int main()
{
	sf::RenderWindow window(sf::VideoMode(widthWindow, heightWindow), "SFML works!");

	while (window.isOpen())
	{

		Draw(window);
	}

	return 0;
	
}

void Draw(sf::RenderWindow& window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
	window.clear();
	window.draw(circle.Shape);
	window.display();
}

void Update()
{
	circle.Update();
}