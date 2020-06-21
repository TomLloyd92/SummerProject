#pragma once

#include "PathPoint.h"
#include <array>
#include <vector>

class PathConnector
{
public:
	PathConnector();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void setup();
	void initialise();
	
	//Sets
	void setConnector(sf::Vector2f t_startPoint, sf::Vector2f t_endPoint, float t_radius);

private:
	sf::VertexArray m_connector{ sf::Lines };
	sf::Vertex m_startPointVertex;
	sf::Vertex m_endPointVertex;

	sf::Vector2f m_startPoint;
	sf::Vector2f m_endPoint;

	float m_radius;

	void m_appendVertex();


};