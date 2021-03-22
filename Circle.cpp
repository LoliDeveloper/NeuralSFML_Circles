#pragma once
#include <SFML/Graphics.hpp>
#include "NeuralMind.h"
#include "MyFunctions.h"
#include "Circle.h"


Circle::Circle()
{
	Shape = sf::CircleShape(20.f);
	Shape.setFillColor(get_random_color());
}

Circle::~Circle()
{
}