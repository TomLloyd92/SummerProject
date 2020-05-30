#pragma once

#ifndef MYVECTOR2D
#define MYVECTOR2D

#include <string>
#include <SFML/Graphics.hpp>


class MyVector2D
{
public:
	// x component
	double x;
	// y component
	double y;

	MyVector2D();


	MyVector2D(double t_x, double t_y);


	MyVector2D(sf::Vector2i t_vector);


	MyVector2D(sf::Vector2f t_vector);


	MyVector2D(sf::Vector2u t_vector);


	~MyVector2D();

	const std::string toString();

	MyVector2D operator+ (const MyVector2D t_right) const;


	MyVector2D operator- (const MyVector2D t_right) const;


	MyVector2D operator* (const double t_scalar) const;


	MyVector2D operator* (const float t_scalar) const;


	MyVector2D operator* (const int t_scalar) const;

	MyVector2D operator/ (const double t_divisor) const;


	MyVector2D operator/ (const float t_divisor) const;

	MyVector2D operator/ (const int t_divisor) const;


	bool operator==(const MyVector2D t_right) const;

	bool operator!=(const MyVector2D t_right) const;


	MyVector2D operator +=(const MyVector2D t_right);


	MyVector2D operator -=(const MyVector2D t_right);


	MyVector2D operator- ();


	MyVector2D rotateBy(float t_angleRadians);


	double length() const;

	double lengthSquared() const;


	MyVector2D unit() const;

	void normalise();


	double angleBetween(const MyVector2D t_other) const;

	double dot(const MyVector2D t_other) const;

	operator sf::Vector2i() { return sf::Vector2i(static_cast<int>(x), static_cast<int>(y)); };
	operator sf::Vector2f() { return sf::Vector2f(static_cast<float>(x), static_cast<float>(y)); };
	operator sf::Vector2u() { return sf::Vector2u(static_cast<unsigned int>(x), static_cast<unsigned int>(y)); };
};


#endif // MYVECTOR2D
