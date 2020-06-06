#include "Objective.h"

Objective::Objective()
{
}

Objective::~Objective()
{
}

void Objective::update(sf::Time t_deltaTime)
{
	movement();


	m_objectiveCircle.setPosition(m_pos);
}

void Objective::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_objectiveCircle);
}

void Objective::setup(sf::Font& t_font)
{
	initialise();
}

void Objective::initialise()
{
	m_objectiveCircle.setFillColor(sf::Color(0, 255, 255));
	m_objectiveCircle.setRadius(10);
	m_pos = sf::Vector2f(100,100);
	m_objectiveCircle.setPosition(m_pos);
}

void Objective::movement()
{
	sf::Vector2i mouseClick;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		mouseClick = sf::Mouse::getPosition();
		m_pos.x = mouseClick.x;
		m_pos.y = mouseClick.y;
	}
}
