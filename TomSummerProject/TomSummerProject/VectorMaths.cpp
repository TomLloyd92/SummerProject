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

float VectorMaths::angleBetween(sf::Vector2f t_vec1, sf::Vector2f t_vec2)
{
	//


	float angleInDegrees = atan2(t_vec1.y - t_vec2.y, t_vec1.x - t_vec2.x) * RAD_TO_DEG;
	return angleInDegrees;
}

float VectorMaths::dotProduct(sf::Vector2f t_vec1, sf::Vector2f t_vec2)
{
	float dotProduct = (t_vec1.x * t_vec2.x) + (t_vec1.y * t_vec2.y);;

	return dotProduct;
}
