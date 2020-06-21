#include "Gameplay.h"

GamePlay::GamePlay()
{

}

GamePlay::~GamePlay()
{
}

void GamePlay::update(sf::Time t_deltaTime)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		if (test == true)
		{
			test = false;
			std::cout << test << std::endl;
		}
		
		else if (test == false)
		{
			test = true;
			std::cout << test << std::endl;
		}
	}


	//Update Objects
	m_player.update(t_deltaTime);
	m_objective.update(t_deltaTime);
	for (int i = 0; i < m_enemys.size(); i++)
	{
		m_enemys.at(i).update(t_deltaTime);
		
		AI.seekOrFlee(m_enemys.at(i), m_player, test);

		m_map.update(t_deltaTime);

		//AI.pathFollowing(m_enemys.at(i), m_pathPoints.at(0));
	}
	/*
	for (int i = 0; i < m_pathPoints.size(); i++)
	{
		m_pathPoints.at(i).update(t_deltaTime);
	}
	*/


	//std::cout << VM.angleBetween(m_player.getPos(), m_objective.getPos()) << std::endl;
}

void GamePlay::render(sf::RenderWindow& t_window)
{
	//Render Objects
	m_player.render(t_window);
	m_objective.render(t_window);
	for (int i = 0; i < m_enemys.size(); i++)
	{
		m_enemys.at(i).render(t_window);
	}
	m_map.render(t_window);

	/*
	for (int i = 0; i < m_pathPoints.size(); i++)
	{
		m_pathPoints.at(i).render(t_window);
	}
	*/
}

void GamePlay::setup(sf::Font& t_font)
{
	//Initialise Objects
	initialise();
	m_player.setup(t_font);
	m_objective.setup(t_font);

	for (int i = 0; i < m_enemys.size(); i++)
	{
		m_enemys.at(i).setup(t_font);
	}

	m_map.setup(5);
	/*
	for (int i = 0; i < m_pathPoints.size(); i++)
	{
		m_pathPoints.at(i).setup(t_font);
	}
	*/


}

void GamePlay::initialise()
{

}
