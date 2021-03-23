#ifndef _USE_MATH_DEFINES
	#define _USE_MATH_DEFINES
#endif
#include <math.h> 
#include <SFML/Graphics.hpp>
#include "NeuralMind.h"
#include "MyFunctions.h"
#include "Circle.h"
#include <iostream>
#include "Globals.h"


Circle::Circle(float speed, float maxspeed, float angle)
{
	Speed = speed;
	MaxSpeed = maxspeed;
	Angle = angle;
	Shape = sf::CircleShape(20.f);
	Shape.setFillColor(get_random_color());
}

Circle::~Circle()
{
}

void Circle::Update()
{
	double input[4] = { (double)Speed / MaxSpeed, fmod(Angle, 2 * M_PI), (double)Shape.getPosition().x / widthWindow, (double)Shape.getPosition().y / heightWindow };
	int resultDecision = MindShape.CalculateDecision(input);
	if (resultDecision == 0)
	{
		turnLeft();
	}
	else if (resultDecision == 1)
	{
		turnRight();
	}
	else if (resultDecision == 2)
	{
		increaseSpeed();
	}
	else
	{
		decreaseSpeed();
	}
}
