#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include <time.h>

class Enemy
{
public:
	Enemy();
	~Enemy();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void setup(sf::Font& t_font);
	void initialise();

	//Gets
	sf::Vector2f getPos() { return m_pos; };
	sf::Vector2f getVel() { return m_vel; };
	float getMaxSpeed() { return m_MAX_SPEED; };

	//Sets
	void setSteering(sf::Vector2f t_steering) { m_steering = t_steering; };

private:
	//Test Circle
	sf::CircleShape m_enemyShape;
	sf::Vector2f m_pos;
	sf::Vector2f m_vel;
	sf::Vector2f m_target;
	const float m_ENEMY_RADIUS = 5;

	//Movement
	void m_movement();
	sf::Vector2f m_steering;
	float m_MAX_SPEED =	1;

};