#pragma once
#include <iostream>
#include "Globals.h"
#include "cmath"
#include <SFML/Graphics.hpp>

class VectorMaths
{

public:
	VectorMaths();
	float magnitude(sf::Vector2f t_vec1);
	sf::Vector2f unitVec(sf::Vector2f t_vec1);
	float dotProduct();
};