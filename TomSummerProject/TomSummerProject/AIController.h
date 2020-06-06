#pragma once
#include <SFML/Graphics.hpp>

#include "Globals.h"

class AIController
{
public:
	AIController();
	~AIController();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void setup(sf::Font& t_font);
	void initialise();

private:
};