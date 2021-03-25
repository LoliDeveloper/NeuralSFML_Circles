#pragma once
#include <SFML/Graphics.hpp>
#include "MyFunctions.h"
#include <chrono>
#include "NeuralMind.h"

class Circle
{
public:
	explicit Circle(float speed, float maxSpeed, float angle, float radius);
	void Die();
	void Draw(sf::RenderWindow& window);
	void Update();
	void set_random_position();
	~Circle();
	sf::CircleShape Shape;	
	NeuralMind MindShape;// = NeuralMind(4, static_cast<int>(10 * get_rand_float()) + 1, static_cast <int>(10 * get_rand_float() + 1), 4);

private:
	sf::Vector2f Direction;
	std::chrono::system_clock::time_point start;
	double liveTime;
	float Radius;
	float Angle;
	float Speed;
	float MaxSpeed;
	void turnLeft();
	void turnRight();
	void increaseSpeed();
	void decreaseSpeed();
	void RecalculateDirection();
};