#include "Map.h"


Map::Map()
{
}


void Map::m_generateMap(int t_amountOfNodes)
{
	m_amountOfNodes = t_amountOfNodes;
	m_generatePathPoint();
}

void Map::update(sf::Time t_deltaTime)
{
	for (PathPoint m_pathPoint : m_point)
	{
		m_pathPoint.update(t_deltaTime);
	}

	for (PathConnector m_pathConnector : m_connector)
	{
		//m_pathConnector.update(t_deltaTime);
	}
}

void Map::render(sf::RenderWindow& t_window)
{
	for (PathPoint m_pathPoint : m_point)
	{
		m_pathPoint.render(t_window);
	}
	for (PathConnector m_pathConnector : m_connector)
	{
		//m_pathConnector.render(t_window);
	}
}

void Map::setup(int t_amountOfNodes)
{

	m_generateMap(t_amountOfNodes);
}

void Map::m_generatePathPoint()
{
	for (int i = 0; i < m_amountOfNodes; i++)
	{
		PathPoint pathPoint;
		pathPoint.setup();
		m_point.push_back(pathPoint);
	}
}

void Map::m_generatePathConnector()
{
	for (int i = 0; i < m_amountOfNodes; i++)
	{

	}
}
