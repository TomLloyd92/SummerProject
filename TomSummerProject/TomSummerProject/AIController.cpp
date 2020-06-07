#include "AIController.h"

AIController::AIController()
{
}

AIController::~AIController()
{
}

void AIController::update(sf::Time t_deltaTime)
{
}

void AIController::render(sf::RenderWindow& t_window)
{
}

void AIController::setup(sf::Font& t_font)
{
}

void AIController::initialise()
{
}

void AIController::seek(Enemy & t_seeker, Player & t_target)
{
	//Vector Relative to target from seeker
	sf::Vector2f relevantLocation = t_target.getPos() - t_seeker.getPos();

	//Unit vector
	float magnitude = std::sqrt(relevantLocation.x * relevantLocation.x + relevantLocation.y * relevantLocation.y);
	if (magnitude != 0)
	{
		relevantLocation.x = relevantLocation.x / magnitude;
		relevantLocation.y = relevantLocation.y / magnitude;
	}

	//Scale to Max Speed
	relevantLocation = relevantLocation * t_seeker.getMaxSpeed();

	//Subtract velocity from desiered
	sf::Vector2f steering = relevantLocation - t_seeker.getVel();

	//Limit Max force

	//Apply Steering
	t_seeker.setSteering(steering);
}
