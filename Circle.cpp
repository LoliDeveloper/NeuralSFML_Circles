#pragma once
#include <SFML/Graphics.hpp>
#include "NeuralMind.cpp"
#include "MyFunctions.h"


class Circle
{
public:
	Circle();
	~Circle();
	sf::CircleShape Shape;

private:
	void turnLeft();
	void turnRight();
	void increaseSpeed();
	void DecreaseSpeed();
	NeuralMind MindShape = NeuralMind(6, 5 * get_rand_float() + 1, 35 * get_rand_float() + 1, 4);


};

Circle::Circle()
{
	Shape = sf::CircleShape(20.f);
	Shape.setFillColor(get_random_color());
}

Circle::~Circle()
{
}