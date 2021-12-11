// Time.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>

class Time {
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);

	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	//Time operator+(const Time& t) const;
	friend Time operator+(const Time& t1, const Time& t2);
	//Time operator-(const Time& t) const;
	friend Time operator-(const Time& t1, const Time& t2);
	//Time operator*(double n) const;
	friend Time operator*(const Time& t, double m);
	friend Time operator*(double m, const Time& t) {
		return t * m;
	}
	friend std::ostream& operator<<(std::ostream& os, const Time& t);
};

int _tmain(int argc, _TCHAR* argv[])
{
	using std::cout;
	using std::endl;

	Time aida(3, 35);
	Time tosca(2, 48);
	Time temp;
	cout << "Aida and Tosca:\n";
	cout << aida << "; " << tosca << endl;
	temp = aida + tosca;
	cout << "Aida + Tosca: " << temp << endl;
	temp = aida * 1.17;
	cout << "Aida * 1.17: " << temp << endl;
	cout << "10.0 * Tosca: " << 10.0 * tosca << endl;

	return 0;
}

Time::Time() {
	hours = minutes = 0;
}

Time::Time(int h, int m) {
	hours = h;
	minutes = m;
}

void Time::AddMin(int m) {
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::AddHr(int h) {
	hours += h;
}

void Time::Reset(int h, int m) {
	hours = h;
	minutes = m;
}

//Time Time::operator+(const Time& t) const {
//	Time sum;
//	sum.minutes = minutes + t.minutes;
//	sum.hours = hours + t.hours + sum.minutes / 60;
//	sum.minutes %= 60;
//
//	return sum;
//}

Time operator+(const Time& t1, const Time& t2) {
	Time sum;
	sum.minutes = t1.minutes + t2.minutes;
	sum.hours = t1.hours + t2.hours + sum.minutes / 60;
	sum.minutes %= 60;

	return sum;
}

//Time Time::operator-(const Time& t) const {
//	Time diff;
//	int tot1, tot2;
//	tot1 = t.minutes + 60 * t.hours;
//	tot2 = minutes * 60 * hours;
//	diff.minutes = (tot2 - tot1) / 60;
//	diff.hours = (tot2 - tot1) / 60;
//
//	return diff;
//}

Time operator-(const Time& t1, const Time& t2) {
	Time diff;
	int tot1, tot2;
	tot1 = t1.minutes + 60 * t1.hours;
	tot2 = t2.minutes * 60 * t2.hours;
	diff.minutes = (tot2 - tot1) / 60;
	diff.hours = (tot2 - tot1) / 60;
	return diff;
}

//Time Time::operator*(double mult) const {
//	Time result;
//	long totalminutes = hours * mult * 60 + minutes * mult;
//	result.hours = totalminutes / 60;
//	result.minutes = totalminutes % 60;
//
//	return result;
//}

Time operator*(const Time& t, double m) {
	Time result;
	long totalminutes = t.hours * m * 60 + t.minutes * m;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

std::ostream& operator<<(std::ostream& os, const Time& t) {
	os << t.hours << " hours, " << t.minutes << " minutes";

	return os;
}