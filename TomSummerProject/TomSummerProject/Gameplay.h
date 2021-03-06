#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Objective.h"
#include "Enemy.h"
#include <array>
#include "AIController.h"
#include "PathPoint.h"
#include "VectorMaths.h"
#include "Map.h"

class GamePlay
{
public:
	GamePlay();
	~GamePlay();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void setup(sf::Font& t_font);
	void initialise();
private:
	//Font
	sf::Font m_font;

	//Objects
	Player m_player;
	Objective m_objective;
	std::array<Enemy, 2> m_enemys;
	//std::array<PathPoint, 2> m_pathPoints;
	AIController AI;
	bool test = true;
	Map m_map;

	VectorMaths VM;
};