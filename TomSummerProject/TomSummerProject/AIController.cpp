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

void AIController::seekOrFlee(Enemy & t_seeker, sf::Vector2f t_target, bool t_seek)
{
	sf::Vector2f relevantLocation;
	if (t_seek == true)
	{
		//Vector Relative to target from seeker
		 relevantLocation = t_target - t_seeker.getPos();
	}
	else if(t_seek == false)
	{
		//FLEE
		relevantLocation =  t_seeker.getPos() - t_target;

	}
	//Unit vector
	relevantLocation = m_vectorMaths.unitVec(relevantLocation);

	//Scale to Max Speed
	relevantLocation = relevantLocation * t_seeker.getSpeed();

	//Subtract velocity from desiered
	sf::Vector2f steering = relevantLocation + t_seeker.getVel();

	//Limit Max force
	float magnitudeSteering = m_vectorMaths.magnitude(steering);

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

void AIController::pathFollowing(Enemy& t_follower, Map & t_map)
{
	//Check future location
	sf::Vector2f futureLocation;
	sf::Vector2f currentVel = t_follower.getVel() ;

	futureLocation.x = currentVel.x * m_PREDICTED_LENGTH;
	futureLocation.y = currentVel.y * m_PREDICTED_LENGTH;
	futureLocation = futureLocation + t_follower.getPos();

	//Check for collision on path
	sf::Vector2f relativePointVector = t_map.m_pointgetPathPoints().at(1).getPos()  - t_map.m_pointgetPathPoints().at(0).getPos();
	sf::Vector2f relativeFollowerVector = futureLocation - t_map.m_pointgetPathPoints().at(0).getPos();

	float angleBetween = m_vectorMaths.angleBetween(relativeFollowerVector, relativePointVector);

	sf::Vector2f target = m_vectorMaths.scalerProduct(relativeFollowerVector, relativePointVector, angleBetween) + t_map.m_pointgetPathPoints().at(0).getPos();

	seekOrFlee(t_follower, target, true);


}
