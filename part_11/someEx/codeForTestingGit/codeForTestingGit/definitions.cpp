#include "stdafx.h"
#include <iostream>
#include "header.h"

SomeClass::SomeClass(int number, char* name) {
	number_ = number;
	strcpy_s(name_, Len, name);
}

SomeClass SomeClass::operator+(const SomeClass& sc) {
	SomeClass tempClass;
	tempClass.number_ = number_ + sc.number_;
	std::cout << "Would you like to set a name? (y/n) ";
	char check[1];
	std::cin >> check; //corrupted
	std::cout << check << std::endl;
	if (check[0] == 'y') {
		char tempName[Len];
		std::cin >> tempName;
		strcpy_s(tempClass.name_, Len, tempName);
	}
	return tempClass;
}

void SomeClass::show() const {
	using namespace std;
	cout << "name: " << name_ << endl
		<< "number: " << number_ << endl;
}