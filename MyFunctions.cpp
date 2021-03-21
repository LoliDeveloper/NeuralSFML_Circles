#pragma once
#include <SFML/Graphics.hpp>
#include <inttypes.h>

sf::Color get_random_color();
float get_rand_float(); 
double get_rand_double();

sf::Color get_random_color()
{
	int8_t color1 = (int8_t)(get_rand_double() * 255);
	int8_t color2 = (int8_t)(get_rand_double() * 255);
	int8_t color3 = (int8_t)(get_rand_double() * 255);
	return sf::Color(color1, color2, color3, 255u);
}

float get_rand_float()
{
	return (static_cast<float>(rand())) / RAND_MAX;
}

double get_rand_double()
{
	return (static_cast<double>(rand())) / RAND_MAX;
}