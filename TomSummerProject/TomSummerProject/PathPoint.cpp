#include "PathPoint.h"

PathPoint::PathPoint()
{
	srand(time(0));
}

PathPoint::~PathPoint()
{
}

void PathPoint::update(sf::Time t_deltaTime)
{
}

void PathPoint::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_pathPointCircle);
}
	
void PathPoint::setup(sf::Font& t_font)
{
	initialise();
}

void PathPoint::initialise()
{
	m_pos.x = rand() % SCREEN_WIDTH + 1.0f;
	m_pos.y = rand() % SCREEN_HEIGHT + 1.0f;
	m_pathPointCircle.setFillColor(sf::Color(255, 255, 125));
	m_pathPointCircle.setRadius(m_raduius);
	m_pathPointCircle.setPosition(m_pos);
}
