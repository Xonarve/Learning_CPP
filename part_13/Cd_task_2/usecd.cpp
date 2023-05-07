#include "stdafx.h"
#include "cd.h"

void Bravo(const Cd& disk);

int _tmain(int argc, _TCHAR* argv[])
{
	using std::cout;
	using std::endl;

	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);

	Cd* pcd = &c1;
	cout << "Using object directly:\n";
	c1.Report();
	cout << endl;
	c2.Report();
	cout << "Using type cd * pointer to objects:\n";
	pcd->Report();
	cout << endl;
	pcd = &c2;
	pcd->Report();
	cout << endl;
	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	cout << endl;
	Bravo(c2);
	cout << std::endl << std::endl;
	cout << "Testing assignment:\n";
	Classic copy;
	copy.Report();

	copy = c2;
	copy.Report();

	return 0;
}

void Bravo(const Cd& disk) {
	disk.Report();
}