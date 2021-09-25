#include "PathPoint.h"

PathPoint::PathPoint()
{
	m_radius = rand() % 30;
	m_col = sf::Color(rand() % 255, rand() % 255, rand() % 255);

}

PathPoint::~PathPoint()
{
}

void PathPoint::update(sf::Time t_deltaTime)
{
	m_pathPointCircle.setPosition(m_pos);
}

void PathPoint::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_pathPointCircle);
}
	
void PathPoint::setup()
{
	initialise();
}

void PathPoint::initialise()
{
	m_pos.x = rand() % SCREEN_WIDTH + 1.0f;
	m_pos.y = rand() % SCREEN_HEIGHT + 1.0f;
	m_pathPointCircle.setFillColor(m_col);
	m_pathPointCircle.setRadius(m_radius);
	m_pathPointCircle.setPosition(m_pos);
}
