// codeForTestingGit.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "header.h"

int _tmain(int argc, _TCHAR* argv[])
{
	SomeClass class1(55, "Peter");
	SomeClass class2(12, "Victor");

	class1.show();
	class2.show();

	SomeClass class3;
	class3 = class1 + class2;
	class3.show();

	return 0;
}

