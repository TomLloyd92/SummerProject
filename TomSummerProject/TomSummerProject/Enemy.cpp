#include "Enemy.h"

Enemy::Enemy()
{
	srand(time(0));
}

Enemy::~Enemy()
{
}

void Enemy::update(sf::Time t_deltaTime)
{
	m_movement();
	m_enemyShape.setPosition(m_pos);
}

void Enemy::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_enemyShape);
}

void Enemy::setup(sf::Font& t_font)
{
	initialise();
}

void Enemy::initialise()
{
	m_pos.x = rand() % SCREEN_WIDTH + 1.0f;
	m_pos.y = rand() % SCREEN_HEIGHT + 1.0f;
	m_enemyShape.setPointCount(3);
	m_enemyShape.setFillColor(sf::Color(255, 0, 0));
	m_enemyShape.setRadius(m_ENEMY_RADIUS * 2);
	m_enemyShape.setPosition(m_pos);
	m_enemyShape.setOrigin(m_ENEMY_RADIUS * 2, m_ENEMY_RADIUS * 2);
}

void Enemy::m_movement()
{
}
