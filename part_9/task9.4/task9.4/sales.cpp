#include "stdafx.h"
#include "sales.h"
#include <iostream>

namespace sales {
	void setSales(Sales& s, const double ar[], int n) {
		if (n == Quarters) {
			for (int i = 0; i < Quarters; i++)
				s.sales[i] = ar[i];
		}
		else if (n < Quarters) {
			for (int i = 0; i < n; i++)
				s.sales[i] = ar[i];
			for (int j = n; j < Quarters; j++)
				s.sales[j] = 0;
		}
		else {
			double* ptr = sortArray(ar, n);
			for (int i = 0; i < Quarters; i++)
				s.sales[i] = ptr[i];
			delete[] ptr;
		}

		double sum = 0;
		double max = s.sales[0];
		double min = s.sales[0];
		for (int i = 0; i < Quarters; i++) {
			sum += s.sales[i];
			if (max < s.sales[i])
				max = s.sales[i];
			if (min > s.sales[i])
				min = s.sales[i];
		}
		s.average = sum / Quarters;
		s.max = max;
		s.min = min;
	}

	void setSales(Sales& s) {
		std::cout << "Enter sales: ";
		double salesAr[Quarters];
		for (int i = 0; i < Quarters; i++)
			std::cin >> salesAr[i];
		setSales(s, salesAr, Quarters);
	}

	void showSales(const Sales& s) {
		std::cout << "Sales: ";
		for (int i = 0; i < Quarters; i++)
			std::cout << s.sales[i] << ' ';
		std::cout << std::endl;
		std::cout << "average: " << s.average << std::endl
			<< "max: " << s.max << std::endl << "min: " << s.min
			<< std::endl;
	}
}

double* sortArray(const double ar[], const int size) {
	double* newAr = new double[size]; //почему нельзя статический массив?
	cpyArray(ar, newAr, size);
	for (int j = size - 1; j >= 0; j--) {
		for (int i = 0; i < j; i++) {
			if (newAr[i + 1] < newAr[i]) {
				double temp = newAr[i];
				newAr[i] = newAr[i + 1];
				newAr[i + 1] = temp;
			}
		}
		/*for (int i = 0; i < size; i++)
			std::cout << newAr[i] << " ";
		std::cout << std::endl;*/
	}
	return newAr;
}

void cpyArray(const double sourceAr[], double destinAr[], const int size) {
	for (int i = 0; i < size; i++) {
		destinAr[i] = sourceAr[i];
		//std::cout << "destinAr" << '[' << i << "] = " << destinAr[i] << std::endl;
	}
}