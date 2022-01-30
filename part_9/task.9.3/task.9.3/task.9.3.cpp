// task.9.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

struct chaff {
	char dross[20];
	int slag;
};

int _tmain(int argc, _TCHAR* argv[])
{
	char buffer1[300];
	char* buffer2 = new char[1500];

	chaff* ch1 = new (buffer1) chaff[2];
	chaff* ch2 = new (buffer2) chaff[3];

	for (int i = 0; i < 2; i++) {
		std::cout << i + 1 << " element:\n";
		char temp[100];
		std::cin.get(temp, 100);
		strcpy_s(ch1[i].dross, 100, temp);
		std::cin >> ch1[i].slag;
		std::cin.get();
	}

	for (int i = 0; i < 2; i++)
		std::cout << ch1[i].dross << '\t' << ch1[i].slag << std::endl;

	for (int i = 0; i < 3; i++) {
		std::cout << i + 1 << " element:\n";
		char temp[100];
		std::cin.get(temp, 100);
		strcpy_s(ch2[i].dross, 100, temp);
		std::cin >> ch2[i].slag;
		std::cin.get();
	}
	for (int i = 0; i < 3; i++)
		std::cout << ch2[i].dross << '\t' << ch2[i].slag << std::endl;
	delete[] buffer2;

	while (std::cin.get() != 'x')
		continue;

	return 0;
}

