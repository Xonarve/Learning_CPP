// Vector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

class Vector {
public:
	enum Mode {RECT, POL};
private:
	double x;
	double y;
	double mag;
	double ang;
	Mode mode;

	void set_mag();
	void set_ang();
	void set_x();
	void set_y();
public:
	Vector();
	Vector(double n1, double n2, Mode form = RECT);
	void reset(double n1, double n2, Mode form = RECT);
	double xval() const { return x; }
	double yval() const { return y; }
	double magval() const { return mag; }
	double angval() const { return ang; }
	void polar_mode() { mode = POL; }
	void rect_mode() { mode = RECT; }

	Vector operator+(const Vector& v) const;
	Vector operator-(const Vector& v) const;
	Vector operator-() const;
	Vector operator*(double m) const;

	friend Vector operator*(double m, const Vector& v);
	friend std::ostream& operator<<(std::ostream& os, const Vector& v);
};

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;

	/*Vector v1(12.34, 7.42, Vector::POL);
	cout << v1 << endl;

	Vector v2(66.21, 97.15, Vector::POL);
	cout << v2 << endl;

	Vector v3(0.0, 0.0, Vector::POL);
	v3 = v1 + v2;
	cout << v3 << endl;*/ //INCORRECT! only for mode = RECT for both

	srand(time(0));
	double direction;
	Vector step;
	Vector result;
	unsigned long steps = 0;
	double target;
	double dstep;

	cout << "Enter target distance: (q to quit) ";
	while (cin >> target) {
		cout << "Enter a step length: ";
		if (!(cin >> dstep))
			break;
		while (result.magval < target) {
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = 
		}
	}

	return 0;
}

const double Rad_to_deg = 45.0 / std::atan(1.0);

void Vector::set_mag() {
	mag = std::sqrt(x * x + y * y);
}

void Vector::set_ang() {
	if (x == 0 && y == 0)
		ang = 0.0;
	else
		ang = std::atan2(y, x);
}

void Vector::set_x() {
	x = mag * cos(ang);
}

void Vector::set_y() {
	y = mag * sin(ang);
}

Vector::Vector() {
	x = y = mag = ang = 0.0;
	mode = RECT;
}

Vector::Vector(double n1, double n2, Mode form) {
	mode = form;
	if (mode == RECT) {
		x = n1;
		y = n2;
		set_mag();
		set_ang();
	}
	else if (mode == POL) {
		mag = n1;
		ang = n2 / Rad_to_deg;
		set_x();
		set_y();
	}
	else {
		std::cout << "Incorrect 3-rd argument/a";
		x = y = mag = ang = 0.0;
		mode = RECT;
	}
}

void Vector::reset(double n1, double n2, Mode form) {
	mode = form;
	if (mode == RECT) {
		x = n1;
		y = n2;
		set_mag();
		set_ang();
	}
	else if (mode == POL) {
		mag = n1;
		ang = n2 / Rad_to_deg;
		set_x();
		set_y();
	}
	else {
		std::cout << "Incorrect 3-rd argument/a";
		x = y = mag = ang = 0.0;
		mode = RECT;
	}
}

Vector Vector::operator+(const Vector& v) const {
	return Vector(x + v.x, y + v.y);
}

Vector Vector::operator-(const Vector& v) const {
	return Vector(x - v.x, y - v.y);
}

Vector Vector::operator-() const {
	return Vector(-x, -y);
}

Vector Vector::operator*(double m) const {
	return Vector(x * m, y * m);
}

Vector operator*(double m, const Vector& v) {
	return v * m;
}

std::ostream& operator<<(std::ostream& os, const Vector& v) {
	using namespace std;
	if (v.mode == Vector::RECT)
		os << "(x, y) = (" << v.x << ", " << v.y << ")";
	else if (v.mode == Vector::POL)
		os << "(m, a) = (" << v.mag << ", " << v.ang * Rad_to_deg << ")";
	else
		os << "Vector mode's invalid/a";
	return os;
}
