#include "stdafx.h"

class SomeClass {
	static const int Len = 20;
	int number_;
	char name_[Len];
public:
	SomeClass(int number = 0, char* name = " ");
	SomeClass operator+(const SomeClass& sc);
	void show() const;
};