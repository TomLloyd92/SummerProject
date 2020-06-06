#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::update(sf::Time t_deltaTime)
{
}

void Player::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_playerShape);
}

void Player::setup(sf::Font& t_font)
{
	initialise();
}

void Player::initialise()
{
	m_playerShape.setPointCount(3);
	m_playerShape.setFillColor(sf::Color(255, 0, 255));
	m_playerShape.setRadius(10);
	m_pos = sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	m_playerShape.setPosition(m_pos);
}

void Player::m_movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_increaseRotation();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_decreaseRotation();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_increaseSpeed();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_decreaseSpeed();
	}
}

void Player::m_increaseRotation()
{

}

void Player::m_decreaseRotation()
{
}

void Player::m_increaseSpeed()
{
	if (m_speed < m_maxSpeed)
	{
		m_speed++;
	}
}

void Player::m_decreaseSpeed()
{
	if (m_speed > m_minSpeed)
	{
		m_speed--;
	}
}

void Player::m_movementHandler()
{
}
