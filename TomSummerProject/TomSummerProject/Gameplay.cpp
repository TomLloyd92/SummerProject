#include "Gameplay.h"

GamePlay::GamePlay()
{
}

GamePlay::~GamePlay()
{
}

void GamePlay::update(sf::Time t_deltaTime)
{
	//Update Objects
	m_player.update(t_deltaTime);
	m_objective.update(t_deltaTime);
}

void GamePlay::render(sf::RenderWindow& t_window)
{
	//Render Objects
	m_player.render(t_window);
	m_objective.render(t_window);
}

void GamePlay::setup(sf::Font& t_font)
{
	//Initialise Objects
	initialise();
	m_player.setup(t_font);
	m_objective.setup(t_font);
}

void GamePlay::initialise()
{

}
