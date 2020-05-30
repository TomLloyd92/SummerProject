#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>


class GamePlay
{
public:
	GamePlay();
	~GamePlay();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void setup(sf::Font& t_font);
	void initialise();
private:
	sf::Font m_font; // font used by HUD maybe??

	//Test Circle
	sf::CircleShape m_testCircle;
};