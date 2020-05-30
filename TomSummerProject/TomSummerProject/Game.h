#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>


class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();
	// used to determin which screen we're on
	//static GameMode m_currentMode;


private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();


	void setupAssets();
	sf::RenderWindow m_window; // main SFML window


	sf::Font m_ArialBlackfont; // font used all othet lcasses only loaded once and other classes
							   // use a refrence to this
	bool m_exitGame;			// control exiting game

};

#endif // !GAME
