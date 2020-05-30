#include "MyVector2D.h"
#include <SFML/Graphics.hpp>

#pragma region constructors

MyVector2D::MyVector2D() :
	x(0.0),
	y(0.0)
{
}


MyVector2D::MyVector2D(double t_x, double t_y) :
	x(t_x),
	y(t_y)
{
}


MyVector2D::MyVector2D(sf::Vector2i t_vector) :
	x(static_cast<double>(t_vector.x)),
	y(static_cast<double>(t_vector.y))
{
}


MyVector2D::MyVector2D(sf::Vector2f t_vector)
{
	x = static_cast<double>(t_vector.x);
	y = static_cast<double>(t_vector.y);
}


MyVector2D::MyVector2D(sf::Vector2u t_vector)
{
	x = static_cast<double>(t_vector.x);
	y = static_cast<double>(t_vector.y);
}
#pragma endregion


MyVector2D::~MyVector2D()
{
}

#pragma region methods
double MyVector2D::lengthSquared() const
{
	const double result = (x * x) + (y * y);
	return result;
}


MyVector2D MyVector2D::unit() const
{
	double x = 0.0;
	double y = 0.0;
	double vectorLength = length();
	if (vectorLength != 0) 
	{
		x = x / vectorLength;
		y = y / vectorLength;
	}
	return MyVector2D(x, y);
}


void MyVector2D::normalise()
{
	double vectorLength = this->length();
	if (vectorLength != 0)
	{
		x = x / vectorLength;
		y = y / vectorLength;
	}
}



double MyVector2D::angleBetween(MyVector2D t_other) const
{
	const double PI = 3.14159265359;
	const double cosine = unit().dot(t_other.unit());
	const double angleInRadians = std::acos(cosine);
	const double angleInDegrees = angleInRadians * 180 / PI;
	return angleInDegrees;
}


double MyVector2D::dot(MyVector2D t_other) const
{
	const double result = (x * t_other.x) + (y * t_other.y);
	return result;
}


const std::string MyVector2D::toString()
{
	const std::string output = "[" + std::to_string(x) + "," + std::to_string(y) + "]";
	return output;
}

#pragma endregion
#pragma region operators

MyVector2D MyVector2D::operator + (const MyVector2D t_right) const
{
	return MyVector2D(x + t_right.x, y + t_right.y);
}



MyVector2D MyVector2D::operator - (const MyVector2D t_right) const
{
	return MyVector2D(x - t_right.x, y - t_right.y);
}


MyVector2D MyVector2D::operator / (const double t_divisor) const
{
	if (t_divisor != 0) 
	{
		return MyVector2D(x / t_divisor, y / t_divisor);
	}
	return MyVector2D();
}


MyVector2D MyVector2D::operator / (const float t_divisor) const
{
	if (t_divisor != 0) 
	{
		return MyVector2D(x / t_divisor, y / t_divisor);
	}
	return MyVector2D();
}


MyVector2D MyVector2D::operator / (const int t_divisor) const
{
	if (t_divisor != 0) 
	{
		return MyVector2D(x / t_divisor, y / t_divisor);
	}
	return MyVector2D();
}


MyVector2D MyVector2D::operator += (const MyVector2D t_right)
{
	x += t_right.x;
	y += t_right.y;
	return MyVector2D(x, y);
}


MyVector2D MyVector2D::operator -= (const MyVector2D t_right)
{
	x -= t_right.x;
	y -= t_right.y;
	return MyVector2D(x, y);
}

double MyVector2D::length() const
{
	const double result = std::sqrt(x * x + y * y);
	return result;
}


MyVector2D MyVector2D::operator-()
{
	return MyVector2D(-x, -y);
}


bool MyVector2D::operator==(const MyVector2D t_right) const
{
	return (x == t_right.x && y == t_right.y);
}


bool MyVector2D::operator!=(const MyVector2D t_right) const
{
	const bool result{ x != t_right.x || y != t_right.y };
	return result;
}


MyVector2D MyVector2D::rotateBy(float t_angleRadians)
{
	const float cos = std::cos(t_angleRadians);
	const float sin = std::sin(t_angleRadians);
	const double xComponent = (x * cos) - (y * sin);
	const double yComponent = (x * sin) + (y * cos);
	return MyVector2D(xComponent, yComponent);
}



MyVector2D MyVector2D::operator * (const double t_scalar) const
{
	return MyVector2D(x * t_scalar, y * t_scalar);
}


MyVector2D MyVector2D::operator * (const float t_scalar) const
{
	return this->operator*(static_cast<double>(t_scalar));
}


MyVector2D MyVector2D::operator * (const int t_scalar) const
{
	return this->operator*(static_cast<double>(t_scalar));
}
#pragma endregion
