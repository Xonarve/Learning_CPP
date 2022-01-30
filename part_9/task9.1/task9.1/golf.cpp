#include "stdafx.h"
#include "golf.h"
#include <iostream>

Golf::Golf(const char* name, int hc) {
	strcpy_s(fullname, Len, name);
	handicap = hc;
}

int Golf::setgolf() {
	std::cout << "Enter a name: ";
	char fulln[Len];
	std::cin.get(fulln, Len);
	int flag;
	if (std::cin) {
		flag = 1;
		if (fulln[0] == ' ')
			flag = 0;
	//проверить работу std::cin.get() при вводе пустой строки
	}
	else {
		while (std::cin.get() != '\n')
			continue;
		std::cin.clear();
		flag = 0;
	}
	std::cout << "Enter a handicap: ";
	int handic;
	std::cin >> handic;
	*this = Golf(fulln, handic);
	return flag;
}

void Golf::setHandicap(int hc) {
	handicap = hc;
}

void Golf::showgolf() const {
	std::cout << fullname << std::endl;
	std::cout << handicap << std::endl;
}