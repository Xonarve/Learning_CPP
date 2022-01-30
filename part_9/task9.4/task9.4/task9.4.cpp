// task9.4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "sales.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	const int Length1 = 6;
	sales::Sales s1;
	double array1[Length1] = { 121.5, 33.17, 84.32, 47.54, 20.31, 99.18 };
	sales::setSales(s1, array1, Length1);
	sales::showSales(s1);

	const int Lenght2 = 8;
	sales::Sales s2;
	double array2[Lenght2] = { 33.56, 843.75, 294.385, 930.39, 81.89, 1.53, 122.29, 282.8 };
	sales::setSales(s2, array2, Lenght2);
	sales::showSales(s2);

	/*const int Lenght3 = 2;
	sales::Sales s3;
	double array3[Lenght3] = { 18.59, 34.78 };
	sales::setSales(s3, array3, Lenght3);
	sales::showSales(s3);

	const int Length4 = 4;
	sales::Sales s4;
	double array4[Length4] = { 78.1, 23.22, 25.21, 88.8 };
	sales::setSales(s4, array4, Length4);
	sales::showSales(s4);*/

	/*sales::Sales s5;
	sales::setSales(s5);
	sales::showSales(s5);*/

	while (std::cin.get() != 'x')
		continue;

	return 0;
}

