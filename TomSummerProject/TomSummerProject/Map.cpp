#include "Map.h"


Map::Map()
{
	m_amountOfNodes = rand() % 50;
}


void Map::m_generateMap(int t_amountOfNodes)
{

	m_generatePathPoint();
	//m_generatePathConnector();
	m_generatePathConnectorCentralized();
}

void Map::update(sf::Time t_deltaTime)
{
	for (PathPoint m_pathPoint : m_point)
	{
		m_pathPoint.update(t_deltaTime);
	}

	for (PathConnector m_pathConnector : m_connector)
	{
		m_pathConnector.update(t_deltaTime);
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
		m_pathConnector.render(t_window);
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
	//float radius = m_point.at(0).getRadius();

	for (int i = 0; i < m_amountOfNodes; i++)
	{
		PathConnector pathConnector;

		 float radius = m_point.at(i).getRadius();
		if (i == m_amountOfNodes - 1)
		{
			pathConnector.setConnector(m_point.at(i).getPos(), m_point.at(0).getPos(), m_point.at(i).getRadius(), m_point.at(0).getRadius());
		}
		else
		{
			pathConnector.setConnector(m_point.at(i).getPos(), m_point.at(i + 1).getPos(), m_point.at(i).getRadius(), m_point.at(i + 1).getRadius());
			//pathConnector.setRadius(radius);
		}
		
		pathConnector.setup();

		m_connector.push_back(pathConnector);
	}
}

void Map::m_generatePathConnectorCentralized()
{

	for (int i = 0; i < m_amountOfNodes; i++)
	{
		PathConnector pathConnector;


		//float radius = m_point.at(i).getRadius();


		if (i == m_amountOfNodes - 1)
		{
			pathConnector.setConnector(m_point.at(i).getPos(), m_point.at(0).getPos(), m_point.at(0).getRadius(), m_point.at(0).getRadius());
		}
		else
		{
			pathConnector.setConnector(m_point.at(i).getPos(), m_point.at(0).getPos(), m_point.at(i).getRadius(), m_point.at(0).getRadius());
			//pathConnector.setRadius(radius);
		}

		pathConnector.setup();

		m_connector.push_back(pathConnector);
	}
}
