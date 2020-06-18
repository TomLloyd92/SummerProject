#pragma once
#include <SFML/Graphics.hpp>

#include <iostream>
#include "Globals.h"
#include "Enemy.h"
#include "Player.h"
#include "PathPoint.h"
#include "cmath"
#include "VectorMaths.h"

class AIController
{
public:
	AIController();
	~AIController();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void setup(sf::Font& t_font);
	void initialise();

	void seekOrFlee(Enemy & t_seeker, Player & t_target, bool t_seek);
	void pathFollowing(Enemy& t_Follower, PathPoint& t_pathPoint);

private:

	const float m_PREDICTED_LENGTH = 20;
	VectorMaths m_vectorMaths;



};