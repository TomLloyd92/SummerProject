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

void AIController::seekOrFlee(Enemy & t_seeker, Player & t_target, bool t_seek)
{
	sf::Vector2f relevantLocation;
	if (t_seek == true)
	{
		//Vector Relative to target from seeker
		 relevantLocation = t_target.getPos() - t_seeker.getPos();
	}
	else if(t_seek == false)
	{
		//FLEE
		relevantLocation =  t_seeker.getPos() - t_target.getPos();

	}
	//Unit vector
	float magnitude = std::sqrt(relevantLocation.x * relevantLocation.x + relevantLocation.y * relevantLocation.y);
	if (magnitude != 0)
	{
		relevantLocation.x = relevantLocation.x / magnitude;
		relevantLocation.y = relevantLocation.y / magnitude;
	}



	//Scale to Max Speed
	relevantLocation = relevantLocation * t_seeker.getSpeed();



	//Subtract velocity from desiered
	sf::Vector2f steering = relevantLocation + t_seeker.getVel();

	//Limit Max force

	//float magnitudeSteering = std::sqrt(relevantLocation.x * relevantLocation.x + relevantLocation.y * relevantLocation.y);	//Magnitude Steering
	float magnitudeSteering = std::sqrt(steering.x * steering.x + steering.y * steering.y);	//Magnitude Steering
	if (magnitudeSteering > t_seeker.getMaxForce())
	{
		sf::Vector2f unitSteering = steering / magnitudeSteering;
		steering = unitSteering * t_seeker.getMaxForce();
	}

	//Convert Velocity Vector into Rotation
	float dest = std::atan2f(-1.0f * steering.y, -1.0f * steering.x) / PI * 180 + 180;

	//Apply Rotation
	t_seeker.setRotiation(dest);

	//Apply Steering
	t_seeker.setVelocity(steering);
}
