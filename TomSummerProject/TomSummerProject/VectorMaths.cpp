#include "VectorMaths.h"

VectorMaths::VectorMaths()
{
}

float VectorMaths::magnitude(sf::Vector2f t_vec)
{
	float x = t_vec.x;
	float y = t_vec.y;

	float magnitude = std::sqrt((x * x) + (y * y));
	return magnitude;
}

sf::Vector2f VectorMaths::unitVec(sf::Vector2f t_vec)
{
	float x = t_vec.x;
	float y = t_vec.y;

	float vectorLength = magnitude(t_vec);
	if (vectorLength != 0)
	{
		x = x / vectorLength;
		y = y / vectorLength;
	}
	return sf::Vector2f(x, y);
}

float VectorMaths::dotProduct()
{

	return 0.0f;
}
