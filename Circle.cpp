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


Circle::Circle(float speed, float maxspeed, float angle, float radius)
{
	Speed = speed;
	MaxSpeed = maxspeed;
	Angle = angle;
	Radius = radius;
	Shape = sf::CircleShape(Radius);
	Shape.setFillColor(get_random_color());
	RecalculateDirection(); 
	start = std::chrono::system_clock::now();
}

Circle::~Circle()
{
}

void Circle::Update()
{
	double input[4] = { (double)Speed / MaxSpeed, fmod(Angle, 2 * M_PI), (double)Shape.getPosition().x / Globals::widthWindow, (double)Shape.getPosition().y / Globals::heightWindow };
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
	sf::Vector2f pos = Shape.getPosition();
	Shape.setPosition(pos + Direction);
	pos = Shape.getPosition();
	if (pos.x < 0 || pos.x > Globals::widthWindow - 2*Radius || pos.y < 0||pos.y > Globals::heightWindow - 2 * Radius)
	{
		Die();
	}
}

void Circle::Die()
{
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end - start;

	int stop = (int)(get_rand_double() * 100 * (1. / elapsed_seconds.count()));
	if (elapsed_seconds.count() > 3.)
	{
		std::cout << "elapsed_seconds.count() = " << elapsed_seconds.count() << "\t stop = " << stop << std::endl;
		for (size_t i = 0; i < stop; ++i)
		{
			MindShape.RandomMutation();
		}
	}
	else 
	{
		MindShape = NeuralMind(4, static_cast<int>(10 * get_rand_float()) + 1, static_cast <int>(10 * get_rand_float() + 1), 4);
	}
	
	Shape.setPosition(0, 0);
	Angle = 1.f;
	Speed = 1.f;
	start = std::chrono::system_clock::now();
}

void Circle::turnLeft()
{
	Angle += 0.05f;
	RecalculateDirection();
}

void Circle::turnRight()
{
	Angle -= 0.05f;
	RecalculateDirection();
}

void Circle::increaseSpeed()
{
	if (abs(Speed) < MaxSpeed) {
		Speed += 0.05f;
		RecalculateDirection();
	}
}

void Circle::decreaseSpeed()
{
	if (abs(Speed) < MaxSpeed) {
		Speed -= 0.05f;
		RecalculateDirection();
	}
}

void Circle::RecalculateDirection()
{
	Direction.x = cos(Angle) * Speed;
	Direction.y = sin(Angle) * Speed;
}

void Circle::Draw(sf::RenderWindow& window)
{
	window.draw(Shape);
}