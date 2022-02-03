// Cow(task1).cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>

const int len = 20;

class Cow {
	char name[len];
	char *hobby;
	double weight;
public:
	Cow();
	Cow(const char *nm, const char *ho, double wt);
	Cow(const Cow &c);
	~Cow();
	Cow &operator=(const Cow &c);
	Cow operator+(const Cow &c);
	void ShowCow() const;
};

int _tmain(int argc, _TCHAR* argv[])
{
	Cow c1;
	c1.ShowCow();
	
	Cow c2("A little cow", "just chilling", 13.75);
	c2.ShowCow();
	
	Cow c3 = c1;
	c3.ShowCow();
	c3 = c2;
	c3.ShowCow();

	Cow c4 = c2 + c3;
	c4.ShowCow();
	Cow c5;
	c5 = c3 + c4;

	return 0;
}

Cow::Cow() {
	name[0] = '\0';
	hobby = new char[strlen("no hobby") + 1];
	strcpy_s(hobby, strlen("no hobby") + 1, "no hobby");
	weight = 0;
}

Cow::Cow(const char *nm, const char *ho, double wt) {
	strcpy_s(name, len, nm);
	hobby = new char[strlen(ho) + 1];
	strcpy_s(hobby, strlen(ho) + 1, ho);
	weight = wt;
}

Cow::Cow(const Cow &c) {
	if (strlen(c.hobby) > len - 1)
		std::cout << "To much symbols for name (max is 19)" << std::endl;
	else
		strcpy_s(name, len, c.name);
	/*delete[] hobby; not required cause only in initialisation*/
	/*if (hobby)
		delete[] hobby;*/
	hobby = new char[strlen(c.hobby) + 1];
	strcpy_s(hobby, strlen(c.hobby) + 1, c.hobby);
	weight = c.weight;
}

Cow::~Cow() {
	delete[] hobby;
}

Cow & Cow::operator=(const Cow &c) {
	if (strlen(c.hobby) > len - 1)
		std::cout << "To much symbols for name (max is 19)" << std::endl;
	if (this == &c)
		return *this;
	strcpy_s(name, len, c.name);
	delete[] hobby;
	hobby = new char[strlen(c.hobby) + 1];
	strcpy_s(hobby, strlen(c.hobby) + 1, c.hobby);
	weight = c.weight;
	return *this;
}

Cow Cow::operator+(const Cow &c) {
	Cow temp; //creating a temporary object
	/*If I were to change this pointer - a hobby, I would need to delete it first*/
	temp.weight = weight + c.weight;
	return temp;
}

void Cow::ShowCow() const {
	using std::cout;
	using std::endl;
	
	cout << "Name: " << name << endl;
	cout << "Hobby: " << hobby << endl;
	cout << "Weight: " << weight << endl;
}