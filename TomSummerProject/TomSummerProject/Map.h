#pragma once
#include <array>
#include <vector>
#include "PathPoint.h"
#include "PathConnector.h"

class Map
{
public:
	Map();

	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void setup(int t_amountOfNodes);

	//Gets
	std::vector<PathConnector> getPathConnectors() { return m_connector; };
	std::vector<PathPoint> m_pointgetPathPoints() { return m_point; };

private:
	void m_generateMap(int t_amountOfNodes);
	void m_generatePathPoint();
	void m_generatePathConnector();

	std::vector<PathConnector> m_connector;
	std::vector<PathPoint> m_point;
	int m_amountOfNodes;

};