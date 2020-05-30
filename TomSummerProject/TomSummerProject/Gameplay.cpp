#include "Gameplay.h"

GamePlay::GamePlay()
{
}

GamePlay::~GamePlay()
{
}

void GamePlay::update(sf::Time t_deltaTime)
{

	m_testCircle.setPosition(10, 10);
}

void GamePlay::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_testCircle);
}

void GamePlay::setup(sf::Font& t_font)
{
	initialise();
}

void GamePlay::initialise()
{
	m_testCircle.setRadius(50);
	m_testCircle.setFillColor(sf::Color(100, 250, 50));
}
