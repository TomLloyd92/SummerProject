#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"

class Objective
{
public:
	Objective();
	~Objective();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void setup(sf::Font& t_font);
	void initialise();

private:
	//Test Circle
	sf::CircleShape m_objectiveCircle;
	sf::Vector2f m_pos;
	sf::Vector2f m_vel;
	sf::Vector2f m_target;

	//Movement
	void movement();
};