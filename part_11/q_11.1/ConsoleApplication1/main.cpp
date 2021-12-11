// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Stonewt {
	static const int Pds_per_stn = 14;
	enum Mode {st, StoneAndPds, poundS};
	int stone;
	double pds_left;
	double pounds;
	Mode mode_;
public:
	Stonewt(double amount, Stonewt::Mode mode);
	Stonewt(int stn, double pds);
	Stonewt();
	~Stonewt() {};

	void show_pds() const;
	void show_stn() const;

	operator int() const;
	operator double() const;

	Stonewt operator*(double m) const;
	friend Stonewt operator*(double m, const Stonewt& st);
};

Stonewt::Stonewt(double amount, Stonewt::Mode mode) {
	mode_ = mode;

	if (mode == st) {
		stone = amount;
		pds_left = 0;
		pounds = amount * Pds_per_stn;
	}
	else if (mode == poundS) {
		pounds = amount;
		stone = int(amount) / Pds_per_stn;
		pds_left = int(amount) % Pds_per_stn + amount - int(amount);
	}
	else
		std::cout << "Incorrect mode for this construct/a/n";
}

Stonewt::Stonewt(int stn, double pds) {
	stone = stn;
	pds_left = pds;
	pounds = stn * Pds_per_stn + pds;
	mode_ = StoneAndPds;
}

Stonewt::Stonewt() {
	stone = pounds = pds_left = 0;
	mode_ = poundS;
}

void Stonewt::show_stn() const {
	std::cout << stone << " stone "
		<< pds_left << " pounds\n";
}

void Stonewt::show_pds() const {
	std::cout << pounds << " pounds\n";
}

Stonewt::operator int() const {
	return int(pounds + 0.5);
}

Stonewt::operator double() const {
	return pounds;
}

Stonewt Stonewt::operator*(double m) const {
	return Stonewt(pounds* m);
}

Stonewt operator*(double m, const Stonewt& st) {
	return Stonewt(st * m);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Stonewt poppins(10, 8);
	poppins.show_stn();
	poppins.show_pds();
	Stonewt new_poppins = poppins * 2.0;
	new_poppins.show_stn();
	new_poppins.show_pds();
	Stonewt another_new_pop = 2.0 * poppins;
	another_new_pop.show_stn();
	another_new_pop.show_pds();

	return 0;
}