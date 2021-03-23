#pragma once
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
	float Angle;
	float Speed;
	float MaxSpeed;
	void turnLeft();
	void turnRight();
	void increaseSpeed();
	void decreaseSpeed();
	NeuralMind MindShape = NeuralMind(4, (int)5 * get_rand_float() + 1, (int)35 * get_rand_float() + 1, 4);
};