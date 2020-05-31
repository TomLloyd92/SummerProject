#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"

class Player
{
public:
	Player();
	~Player();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void setup(sf::Font& t_font);
	void initialise();

private:
	//Test Circle
	sf::CircleShape m_testCircle;
	sf::Vector2f m_pos;
	sf::Vector2f m_vel;
};