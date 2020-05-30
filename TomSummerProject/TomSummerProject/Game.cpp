#include "Game.h"
#include <SFML\Graphics.hpp>
#include <iostream>



//GameMode Game::m_currentMode{ GameMode::Splash };




Game::Game() :
	m_window{ sf::VideoMode{ 1000, 1000, 32 }, "Toms Summer Project" },
	m_exitGame{ false }
{
	setupAssets();

}


Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	while (m_window.isOpen())
	{
		processEvents(); 
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); 
			update(timePerFrame); 
		}
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type) 
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type)
		{
			/*
			if ((sf::Keyboard::Escape == event.key.code) && (Game::m_currentMode == GameMode::GamePlay))
			{
				Game::m_currentMode = GameMode::Map;
			}
			*/
		}
	}
}


void Game::update(sf::Time t_deltaTime)
{
	/*
	switch (m_currentMode)
	{
	case GameMode::Splash:
		m_splashScreen.update(t_deltaTime);
	default:
		break;
	}
	if (m_exitGame)
	{
		m_window.close();
	}
	*/
}


void Game::render()
{
	/*
	switch (m_currentMode)
	{
	case GameMode::Splash:
		m_splashScreen.render(m_window);
		break;
	default:
		break;
	}
	*/

}

void Game::setupAssets()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
}

