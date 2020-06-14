#pragma once
#include <SFML/Graphics.hpp>

#include "Globals.h"
#include "Enemy.h"
#include "Player.h"
#include "cmath"

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
private:
};