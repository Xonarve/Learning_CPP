#include "stdafx.h"
#include "cd.h"

Cd::Cd(char* s1, char* s2, int n, double x) : selections(n), playtime(x) {
	performers = new char[strlen(s1) + 1];
	label = new char[strlen(s2) + 1];
	strcpy_s(performers, strlen(s1) + 1, s1);
	strcpy_s(label, strlen(s2) + 1, s2);
}

Cd::Cd() : selections(0), playtime(0.0) {
	performers = new char[strlen("no - performers") + 1];
	label = new char[strlen("no-label") + 1];
	strcpy_s(performers, strlen("no-performers") + 1, "no-performers");
	strcpy_s(label, strlen("no-label") + 1, "no-label");
}

Cd::Cd(const Cd& d) : selections(d.selections), playtime(d.playtime) {
	performers = new char[strlen(d.performers) + 1];
	label = new char[strlen(d.label) + 1];
	strcpy_s(performers, strlen(d.performers) + 1, d.performers);
	strcpy_s(label, strlen(d.label) + 1, d.label);
}

Cd& Cd::operator=(const Cd& d) {
	if (this == &d)
		return *this;
	delete[] performers;
	delete[] label;
	selections = d.selections;
	playtime = d.playtime;
	performers = new char[strlen(d.performers) + 1];
	label = new char[strlen(d.label) + 1];
	strcpy_s(performers, strlen(d.performers) + 1, d.performers);
	strcpy_s(label, strlen(d.label) + 1, d.label);
	return *this;
}

void Cd::Report() const {
	using std::cout;
	using std::endl;
	cout << "Performers: " << performers << endl
		<< "Label: " << label << endl
		<< "Selections: " << selections << endl
		<< "Playtime: " << playtime << endl;
}

Cd::~Cd() {
	delete[] performers;
	delete[] label;
}

Classic::Classic(char* s1, char* s2, char* s3, int n, double x) : Cd(s1, s2, n, x) {
	main = new char[strlen(s3) + 1];
	strcpy_s(main, strlen(s3) + 1, s3);
}

Classic::Classic() : Cd() {
	main = new char[strlen("no-main") + 1];
	strcpy_s(main, strlen("no-main") + 1, "no-main");
}

Classic::Classic(const Cd& d, char* s3) : Cd(d) {
	main = new char[strlen(s3) + 1];
	strcpy_s(main, strlen(s3) + 1, s3);
}

Classic::Classic(const Classic& c) : Cd(c) {
	main = new char[strlen(c.main) + 1];
	strcpy_s(main, strlen(c.main) + 1, c.main);
}

Classic& Classic::operator=(const Classic& c) {
	if (this == &c)
		return *this;
	Cd::operator=(c);
	delete[] main;
	main = new char[strlen(c.main) + 1];
	strcpy_s(main, strlen(c.main) + 1, c.main);
	return *this;
}

void Classic::Report() const {
	Cd::Report();
	std::cout << "Main: " << main << std::endl << std::endl;
}

Classic::~Classic() {
	delete[] main;
}