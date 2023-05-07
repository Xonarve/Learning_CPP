#include "stdafx.h"
#include <iostream>
#include "cd.h"

void Bravo(const Cd& disk);

int _tmain(int argc, _TCHAR* argv[])
{
	using std::cout;
	using std::cin;

	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);

	Cd* pcd = &c1;
	cout << "Using object directly:\n";
	c1.Report();
	c2.Report();
	cout << "Using type cd * pointer to objects:\n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();
	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);
	cout << std::endl << std::endl;
	cout << "Testing assignment: ";
	Classic copy;
	copy.Report();

	copy = c2;
	copy.Report();

	return 0;
}

void Bravo(const Cd& disk) {
	disk.Report();
}