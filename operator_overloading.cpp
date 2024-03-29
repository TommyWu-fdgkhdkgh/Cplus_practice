/*******************************
 * Q:operator overloading, when we use it, our parameters should in order?
 * ex:our first parameter should be a specific type.
 *
 * A:Yes, it should be a specific order.
 *
 * Q:can friend function use other member function of this class?
 *
 * A:No, friend function cannot use other member function of this class.
 *
 *******************************/


 // vect.cpp -- methods for the Vector class
#include <cmath>
#include "operator_overloading.h"	// includes <iostream>

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
	// compute degrees in one radian
	const double Rad_to_deg = 45 / atan(1.0);
	// should be about 57.2957795130823

	// private methods
	// calculates magnitude from x and y
	void Vector::set_mag()
	{
		mag = sqrt(x * x + y * y);
	}

	void Vector::set_ang()
	{
		if (x == 0.0 && y == 0.0)
			ang = 0.0;
		else
			ang = atan2(y, x);
	}

	// set x from polar coordinate
	void Vector::set_x()
	{
		x = mag * cos(ang);
	}

	// set y from polar coordinate
	void Vector::set_y()
	{
		y = mag * sin(ang);
	}

	// public methods
	Vector::Vector()	// default constructor
	{
		x = y = mag = ang = 0.0;
		mode = RECT;
	}

	// construct vector from rectangular coordinates if form is r
	// (the default) or else from polar coordinates if form is p
	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;

		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "Vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "Vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	Vector::~Vector()	// destructor
	{

	}

	void Vector::polar_mode()	// set to polar mode
	{


		mode = POL;
	}

	void Vector::rect_mode()	// set to rectangular mode
	{
		mode = RECT;
	}

	Vector Vector::operator+(const Vector & b) const
	{
		return Vector(x + b.x, y + b.y);
	}

	Vector Vector::operator-(const Vector & b) const
	{
		return Vector(x - b.x, y - b.y);
	}

	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}

	Vector Vector::operator*(double n) const
	{
		

		return Vector(n * x, n * y);
	}

	// friend methods
	// multiply n by Vector a
	Vector operator*(double n, const Vector & a) 
	{

		return a * n;
	}

	// display rectangular coordinates if mode is RECT,
	// else display polar coordinates if mode is POL
	std::ostream & operator<<(std::ostream & os, const Vector & v)
	{
		if (v.mode == Vector::RECT)
			os << "(x,y) = (" << v.x << ", " << v.y << ")";
		else if (v.mode == Vector::POL)
		{
			os << "(m,a) = (" << v.mag << ", " << v.ang * Rad_to_deg << ")";
		}
		else
			os << "Vector object mode is invalid";
		return os;
	}

}

void operator_overloading() {

	VECTOR::Vector a, b;
	
	b = a * 1;
	b = 1 * a;


}
