#include "PathConnector.h"

PathConnector::PathConnector()
{
	
}

void PathConnector::update(sf::Time t_deltaTime)
{

}

void PathConnector::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_connector);
}

void PathConnector::setup()
{
	initialise();
}

void PathConnector::initialise()
{
	m_appendVertex();
}

void PathConnector::setConnector(sf::Vector2f t_startPoint, sf::Vector2f t_endPoint, float t_radius)
{
	m_radius = t_radius;
	m_startPoint = t_startPoint;
	m_endPoint = t_endPoint;
}

void PathConnector::m_appendVertex()
{
	m_startPointVertex.position.x = m_startPoint.x + m_radius;
	m_startPointVertex.position.y = m_startPoint.y + m_radius;
	m_endPointVertex.position.x = m_endPoint.x + m_radius;
	m_endPointVertex.position.y = m_endPoint.y + m_radius;

	m_connector.append(m_startPointVertex);
	m_connector.append(m_endPointVertex);
}
