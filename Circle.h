#pragma once
#include <SFML/Graphics.hpp>
#include "NeuralMind.h"
#include "MyFunctions.h"

class Circle
{
public:
	Circle(float speed, float maxSpeed, float angle);
	void Die();
	void Update();
	~Circle();
	sf::CircleShape Shape;

private:
	sf::Vector2f Direction;
	float Angle;
	float Speed;
	float MaxSpeed;
	void turnLeft();
	void turnRight();
	void increaseSpeed();
	void decreaseSpeed();
	void RecalculateDirection();
	NeuralMind MindShape = NeuralMind(4, static_cast<int>(5 * get_rand_float()) + 1, static_cast <int>(35 * get_rand_float() + 1), 4);
};