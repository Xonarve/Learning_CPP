// Task11.7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Complex {
private:
	double real;
	double imaginary;
public:
	Complex(int r = 0, int im = 0);
	Complex operator~() const;
	Complex operator+(const Complex& c) const;
	Complex operator-(const Complex& c) const;
	Complex operator*(const Complex& c) const;
	Complex operator*(double number) const;
	friend Complex operator*(double number, const Complex& c);
	friend std::ostream& operator<<(std::ostream& os, const Complex& c);
	friend std::istream& operator>>(std::istream& is, Complex& c);
};

int _tmain(int argc, _TCHAR* argv[])
{
	using std::cout;
	using std::cin;

	Complex a(3.0, 4.0);
	Complex c;
	cout << "Entear a complex number (q to quit):\n";
	while (cin >> c) {
		cout << "c is " << c;
		cout << "complex conjugate is " << ~c;
		cout << "a is " << a;
		cout << "a + c is " << a + c;
		cout << "a - c is " << a - c;
		cout << "a * c is " << a * c;
		cout << "2 * c is " << 2 * c;
		cout << "Enter a complex number (q to quit):\n";
	}
	cout << "Done!\n";
	return 0;
}

Complex::Complex(int r, int im) {
	real = r;
	imaginary = im;
}

Complex Complex::operator~() const {
	return Complex(real, -imaginary);
}

Complex Complex::operator+(const Complex& c) const {
	return Complex(real + c.real, imaginary + c.imaginary);
}

Complex Complex::operator-(const Complex& c) const {
	return Complex(real - c.real, imaginary - c.imaginary);
}

Complex Complex::operator*(const Complex& c) const {
	return Complex(real * c.real - imaginary * c.imaginary,
		real * c.imaginary + imaginary * c.real);
}

Complex Complex::operator*(double number) const {
	return Complex(number * real, number * imaginary);
}

Complex operator*(double number, const Complex& c) {
	return c * number;
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
	using namespace std;

	os << "(" << c.real << ", " << c.imaginary << "i" << ")" << endl;
	return os;
}

std::istream& operator>>(std::istream& is, Complex& c) {
	std::cout << "real: ";
	if (!(is >> c.real))
		return is;
	std::cout << "imaginary: ";
	is >> c.imaginary;
	return is;
}