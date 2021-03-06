#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::update(sf::Time t_deltaTime)
{
	m_movement();
	m_movementHandler();
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
	m_playerShape.setRadius(m_PLAYER_RADIUS * 2);
	m_pos = sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	m_playerShape.setPosition(m_pos);
	m_playerShape.setOrigin(m_PLAYER_RADIUS * 2, m_PLAYER_RADIUS * 2);
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
	m_rotation += 2;

	if (m_rotation == 360.0)
	{
		m_rotation = 0;
	}
}

void Player::m_decreaseRotation()
{
	m_rotation -= 2;

	if (m_rotation == 360.0)
	{
		m_rotation = 0;
	}
}

void Player::m_increaseSpeed()
{
	if (m_speed < m_maxSpeed)
	{
		m_speed += m_accelerator;
	}
}

void Player::m_decreaseSpeed()
{
	if (m_speed > m_minSpeed)
	{
		m_speed -= m_accelerator;
	}
}

void Player::m_movementHandler()
{
	m_playerShape.setRotation(m_rotation);

	m_pos.x = m_playerShape.getPosition().x + std::cosf((m_rotation + m_rotationCorrection) * DEG_TO_RAD) * m_speed;
	m_pos.y = m_playerShape.getPosition().y + std::sinf((m_rotation + m_rotationCorrection ) * DEG_TO_RAD) * m_speed;

	if (m_speed > 0)
	{
		m_speed = m_speed * 0.95;
	}

	m_playerShape.setPosition(m_pos);
}
