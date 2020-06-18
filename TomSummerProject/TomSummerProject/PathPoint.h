#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"

class PathPoint
{
public:
	PathPoint();
	~PathPoint();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void setup(sf::Font& t_font);
	void initialise();

	//Gets
	float getRadius() { return m_raduius; };

private:
	//Test Circle
	sf::CircleShape m_pathPointCircle;
	sf::Vector2f m_pos;
	sf::Vector2f m_vel;
	float m_raduius = 20;
};