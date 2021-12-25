// String.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>

class String {
	/*char* str_;*/
	int len;
	/*static int num_strings;*/
public:
	String(int value);
	String() {};
	//String();
	//~String();

	//friend std::ostream& operator<<(std::ostream& os, const String& str);
};

int _tmain(int argc, _TCHAR* argv[])
{
	String s(5);
	String s1;
	return 0;
}

//int String::num_strings = 0;

String::String(int value) {
	/*len = std::strlen(str);
	str = new char[len + 1];
	strcpy_s(str_, len, str);
	num_strings++;
	std::cout << num_strings << ": " << str_ << "object created\n";*/

}

//String::String() {
//	len = 4;
//	str_ = new char[len];
//	strcpy_s(str_, len, "C++");
//	num_strings++;
//	std::cout << num_strings << ": " << str_ << "object created\n";
//}
//
//String::~String() {
//	std::cout << str_ << " object deleted\n";
//	--num_strings;
//	delete[] str_;
//	std::cout << "Objects left: " << num_strings << std::endl;
//}
//
//std::ostream &operator<<(std::ostream& os, const String& str) {
//	os << str.str_ << std::endl;
//
//	return os;
//}