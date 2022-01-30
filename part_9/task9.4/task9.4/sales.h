namespace sales {
	const int Quarters = 4;
	struct Sales {
		double sales[Quarters];
		double average;
		double max;
		double min;
	};

	void setSales(Sales& s, const double ar[], int n);
	void setSales(Sales& s);
	void showSales(const Sales& s);
}

double* sortArray(const double ar[], const int size);
void cpyArray(const double sourceAr[], double destinAr[], const int size);