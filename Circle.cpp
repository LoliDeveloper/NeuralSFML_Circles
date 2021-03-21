#pragma once
#include <SFML/Graphics.hpp>
#include "NeuralMind.cpp"
#include "MyFunctions.cpp"


class Circle
{
public:
	Circle();
	~Circle();

private:
	void turnLeft();
	void turnRight();
	void increaseSpeed();
	void DecreaseSpeed();

	sf::CircleShape Shape;
	NeuralMind MindShape;


};

Circle::Circle()
{
	Shape = sf::CircleShape(20.f);
	Shape.setFillColor(get_random_color());
	MindShape = NeuralMind(5 * get_rand_float() + 1, 35 * get_rand_float() + 1, 4);
}

Circle::~Circle()
{
}