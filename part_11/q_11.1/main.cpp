// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Stonewt {
private:
	static const int Pds_per_stn = 14;
	int stone;
	double pds_left;
	double pounds;
public:
	enum Mode { st, StoneAndPds, poundS };
	Stonewt(double amount, Stonewt::Mode mode);
	Stonewt(int stn, double pds);
	Stonewt();
	~Stonewt() {};

	//void show_pds() const;
	//void show_stn() const;

	operator int() const;
	operator double() const;

	Stonewt operator*(double m) const;
	friend Stonewt operator*(double m, const Stonewt& st);
	Stonewt operator+(const Stonewt& st);
	Stonewt operator-(const Stonewt& st);

	bool operator<(const Stonewt& st);
	bool operator<=(const Stonewt& st);
	bool operator>(const Stonewt& st);
	bool operator>=(const Stonewt& st);
	bool operator==(const Stonewt& st);
	bool operator!=(const Stonewt& st);

	bool operator>(int value);

	friend std::ostream& operator<<(std::ostream& os, const Stonewt& st);
private:
	Mode mode_;
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

//void Stonewt::show_stn() const {
//	std::cout << stone << " stone "
//		<< pds_left << " pounds\n";
//}
//
//void Stonewt::show_pds() const {
//	std::cout << pounds << " pounds\n";
//}

Stonewt::operator int() const {
	return int(pounds + 0.5);
}

Stonewt::operator double() const {
	return pounds;
}

Stonewt Stonewt::operator*(double m) const {
	return Stonewt(pounds* m, poundS);
}

Stonewt operator*(double m, const Stonewt& st) {
	return Stonewt(st * m);
}

Stonewt Stonewt::operator+(const Stonewt& st) {
	return Stonewt(pounds + st.pounds, Stonewt::poundS);
}

Stonewt Stonewt::operator-(const Stonewt& st) {
	return Stonewt(pounds - st.pounds, Stonewt::poundS);
}

bool Stonewt::operator<(const Stonewt& st) {
	if (pounds < st.pounds)
		return true;
	return false;
}

bool Stonewt::operator<=(const Stonewt& st) {
	if (pounds < st.pounds || pounds == st.pounds)
		return true;
	return false;
}

bool Stonewt::operator>(const Stonewt& st) {
	if (pounds > st.pounds)
		return true;
	return false;
}

bool Stonewt::operator>=(const Stonewt& st) {
	if (pounds > st.pounds || pounds == st.pounds)
		return true;
	return false;
}

bool Stonewt::operator==(const Stonewt& st) {
	if (pounds == st.pounds)
		return true;
	return false;
}

bool Stonewt::operator!=(const Stonewt& st) {
	if (pounds != st.pounds)
		return true;
	return false;
}

bool Stonewt::operator>(int value) {
	if (stone > value)
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& os, const Stonewt& st) {
	if (st.mode_ == Stonewt::st)
		os << st.stone << " stone. \n";
	else if (st.mode_ == Stonewt::StoneAndPds)
		os << st.stone << " stone, " << st.pds_left << " pds left.\n";
	else if (st.mode_ == Stonewt::poundS)
		os << st.pounds << " pounds.\n";
	else
		os << "You've incorrect mode for your class!\a\n";
	return os;
}

Stonewt minimum(Stonewt* stPtr, int size);
Stonewt maximum(Stonewt* stPtr, int size);

int _tmain(int argc, _TCHAR* argv[])
{
	/*Stonewt st1(12.0, Stonewt::st);
	std::cout << st1;

	Stonewt st2(134.0, Stonewt::poundS);
	std::cout << st2;

	Stonewt st3(15, 32.0);
	std::cout << st3;

	Stonewt st4;
	std::cout << st4;

	st4 = st1 + st2;
	std::cout << st4;

	Stonewt st5 = st4 - st3;
	std::cout << st5;

	st5 = st5 * 1.5;
	std::cout << st5;

	st1 = 3.2 * st1;
	std::cout << st1;*/

	const int Len = 6;
	Stonewt stonewts[Len] = { Stonewt(12.0, Stonewt::st), Stonewt(5, 3.0), Stonewt(354.0, Stonewt::poundS) };
	//for (int i = 0; i < Len; ++i)
		//std::cout << stonewts[i];

	std::cout << "Enter data for the remaining objects: ";
	double stone, pounds_left, pounds;
	int mode;
	for (int i = 3; i < Len; ++i) {
		std::cout << "Enter a type of object: (st - 0 or stoneAndPds - 1 or poundS - 2) ";
		std::cin >> mode;
		if (mode == Stonewt::st) {
			std::cout << "Enter amount of stone: ";
			std::cin >> stone;
			stonewts[i] = Stonewt(stone, Stonewt::st);
		}
		else if (mode == Stonewt::StoneAndPds) {
			std::cout << "Enter amount of stone: ";
			std::cin >> stone;
			std::cout << "Enter amount of pounds: ";
			std::cin >> pounds_left;
			stonewts[i] = Stonewt(stone, pounds_left);
		}
		else if (mode == Stonewt::poundS) {
			std::cout << "Enter amount of pounds: ";
			std::cin >> pounds;
			stonewts[i] = Stonewt(pounds, Stonewt::poundS);
		}
		else {
			std::cout << "You entered invalid mode for object!\a\n";
			break;
		}
	}
	std::cin.clear();

	for (int i = 0; i < Len; ++i)
		std::cout << stonewts[i];

	Stonewt min = minimum(stonewts, Len);
	Stonewt max = maximum(stonewts, Len);
	std::cout << "Min: " << min << std::endl;
	std::cout << "Max: " << max << std::endl;

	int count_1 = 0;
	for (int i = 0; i < Len; ++i) {
		if (stonewts[i] > 11)
			count_1++;
	}
	std::cout << "Amount objects, that have stone > 11 is " << count_1 << std::endl;

	int count_2 = 0;
	Stonewt st(11, 0.0);
	for (int i = 0; i < Len; ++i) {
		if (stonewts[i] > st)
			count_2++;
	}
	std::cout << "Amount objects, that have stone > 11 is " << count_2 << std::endl;

	return 0;

}

Stonewt minimum(Stonewt* stPtr, int size) {
	Stonewt min = stPtr[0];
	for (int i = 1; i < size; ++i) {
		if (min > stPtr[i])
			min = stPtr[i];
	}
	return min;
}

Stonewt maximum(Stonewt* stPtr, int size) {
	Stonewt max = stPtr[0];
	for (int i = 1; i < size; ++i) {
		if (max < stPtr[i])
			max = stPtr[i];
	}
	return max;
}

