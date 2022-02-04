// Stock_task3.cpp : Defines the entry point for the console application.
//
//Разобраться с установкой методов в функции вывода а также с деструкторами
#include "stdafx.h"
#include <iostream>
#include <cstring>

const int STKS = 4;

class Stock {

private:
	char *company;
	long shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }

public:
	Stock();
	Stock(const char *co, long n = 0, double pr = 0.0);
	~Stock();
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show() const;
	const Stock &topval(const Stock &s) const;

	friend std::ostream &operator<<(std::ostream &os, const Stock &s);
};

int _tmain(int argc, _TCHAR* argv[])
{
	{
		Stock stocks[STKS] = {
			Stock("NanoSmart", 12, 20.0),
			Stock("Boffo Objects", 200, 2.0),
			Stock("Monolithic Obelisks", 130, 3.25),
			Stock("Fleep Enterprices", 60, 6.5)
		};

		std::cout << "Stock holdings\n";
		int st;

		for (st = 0; st < STKS; ++st)
			std::cout << stocks[st];
		std::cout << '\n';
	}

	std::cout << "Bye!\n";
	return 0;
}

Stock::Stock() {
	int len = strlen("no name");
	company = new char[len + 1];
	strcpy_s(company, len + 1, "no name");
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const char *co, long n, double pr) {
	int len = strlen(co);
	company = new char[len + 1];
	strcpy_s(company, len + 1, co);
	if (n < 0) {
		std::cout << "Number of shares can't be negative; "
			<< company << " shares set to 0\n";
		shares = 0;
	}
	else
		shares = n;

	share_val = pr;
	set_tot();
}

Stock::~Stock() {
	std::cout << "Destructor\n";
	delete[] company;
}

void Stock::buy(long num, double price) {
	shares += num;
	share_val = price;
	set_tot();
}

void Stock::sell(long num, double price) {
	shares -= num;
	share_val = price;
	set_tot();
}

void Stock::update(double price) {
	share_val = price;
	set_tot();
}

void Stock::show() const {
	using std::ios_base;
	ios_base::fmtflags orig =
		std::cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = std::cout.precision(3);
	std::cout << "Company: " << company
		<< " Shares: " << shares << std::endl
		<< " Share Price: $" << share_val;
	std::cout.precision(2);
	std::cout << " Total Worth: $" << total_val << std::endl;
	std::cout.setf(orig, ios_base::floatfield);
	std::cout.precision(prec);
}

std::ostream &operator<<(std::ostream &os, const Stock &s) {
	using std::ios_base;
	ios_base::fmtflags orig =
		std::cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = std::cout.precision(3);
	os << "Company: " << s.company
		<< " Shares: " << s.shares << std::endl
		<< " Share Price: $" << s.share_val;
	std::cout.precision(2);
	std::cout << " Total Worth: $" << s.total_val << std::endl;
	std::cout.setf(orig, ios_base::floatfield);
	std::cout.precision(prec);

	return os;
}

const Stock & Stock::topval(const Stock &s) const {
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}