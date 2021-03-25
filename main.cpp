#include <SFML/Graphics.hpp>
#include <iostream>
#include "Circle.h"
#include "Globals.h"
#include <vector>

void Draw(sf::RenderWindow&);
void Update();
std::vector<Circle> circles;


int main()
{
	circles.reserve(Globals::circlesCount);
	for (int i = 0; i < Globals::circlesCount; ++i)
	{
		circles.push_back(Circle(25.f, 25.f, 1.f, 20.f));
	}
	sf::RenderWindow window(sf::VideoMode(Globals::widthWindow, Globals::heightWindow), "SFML works!");
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		Update();
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
	for(int i = 0; i < Globals::circlesCount; ++i)
		circles[i].Draw(window);
	window.display();
}

void Update()
{
	for (int i = 0; i < Globals::circlesCount; ++i)
		circles[i].Update();
}