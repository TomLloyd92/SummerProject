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
	//Test Player;
	sf::CircleShape m_playerShape;

	//Position
	sf::Vector2f m_pos;
	sf::Vector2f m_vel;

	//Movement
	void m_movement();
	void m_increaseRotation();
	void m_decreaseRotation();
	void m_increaseSpeed();
	void m_decreaseSpeed();
	void m_movementHandler();
	float m_speed = 0;
	float m_maxSpeed = 100;
	float m_minSpeed = 0;
};