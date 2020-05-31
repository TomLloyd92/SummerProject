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
	t_window.draw(m_testCircle);
}

void Player::setup(sf::Font& t_font)
{
	initialise();
}

void Player::initialise()
{
	m_testCircle.setFillColor(sf::Color(255, 0, 255));
	m_testCircle.setRadius(10);
	m_pos = sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	m_testCircle.setPosition(m_pos);
}
