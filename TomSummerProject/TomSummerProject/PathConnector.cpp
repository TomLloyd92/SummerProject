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

void PathConnector::setConnector(sf::Vector2f t_startPoint, sf::Vector2f t_endPoint, float t_radiusStart, float t_radiusEnd)
{
	m_radiusStart = t_radiusStart;
	m_radiusEnd = t_radiusEnd;
	m_startPoint = t_startPoint;
	m_endPoint = t_endPoint;
}

void PathConnector::m_appendVertex()
{
	m_startPointVertex.position.x = m_startPoint.x + m_radiusStart;
	m_startPointVertex.position.y = m_startPoint.y + m_radiusStart;
	
	m_endPointVertex.position.x = m_endPoint.x + m_radiusEnd;
	m_endPointVertex.position.y = m_endPoint.y + m_radiusEnd;

	m_connector.append(m_startPointVertex);
	m_connector.append(m_endPointVertex);

	
}
