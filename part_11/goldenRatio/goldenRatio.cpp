// goldenRatio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

const double goldenRatio = (1 + sqrt(5.0) / 5);

double function(double x);
double searhExtremum(double start, double end, double eps);

int _tmain(int argc, _TCHAR* argv[])
{
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(4);

	double min = searhExtremum(-0.5, 0.5, 0.0005);


	return 0;
}

double function(double x) {
	return (-(x * x * x)) + 3 * (1 + x) * (log(1 + x) - 1);
}

double searhExtremum(double start, double end, double eps) {
	double x1, x2, y1, y2, xmin, extremum;
	int count = 0;
	while (abs(end - start) >= eps) {
		x1 = end - (end - start) / goldenRatio;
		x2 = start + (end - start) / goldenRatio;
		y1 = function(x1);
		y2 = function(x2);
		if (y1 > y2)
			start = x1;
		else
			end = x2;
		++count;
	}
	xmin = (start + end) / 2;
	extremum = function(xmin);
	cout << "Amount of iterations: " << count << endl;
	cout << "x min: " << xmin << endl;
	cout << "y min: " << extremum << endl;
	return function(xmin);
	
}

//moreEffective 

//double searhExtremum(double start, double end, double eps) {
//	double x1, x2, y1, y2, xmin, extremum;
//	int count = 0;
//	x1 = end - (end - start) / goldenRatio;
//	x2 = start + (end - start) / goldenRatio;
//	y1 = function(x1);
//	y2 = function(x2);
//
//	while (abs(end - start) > eps) {
//		if (y1 > y2) {
//			start = x1;
//			x1 = x2;
//			x2 = start + (end - start) / goldenRatio;
//			y2 = function(x2);
//		}
//		else if (y1 <= y2) {
//			end = x2;
//			x2 = x1;
//			x1 = end - (end - start) / goldenRatio;
//			y1 = function(x1);
//		}
//		++count;
//	}
//	xmin = (start + end) / 2;
//	extremum = function(xmin);
//	cout << "Amount of iterations: " << count << endl;
//	cout << "x min: " << xmin << endl;
//	cout << "y min: " << extremum << endl;
//	return function(xmin);
//WTF IS GOIN ON RIGHT HERE??? WHY IT ISN'T WORK??
//}