// String.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cctype>

class String {
	char *str;
	int len;
	static int num_strings;
	static const int cinlim = 80;
public:
	String(const char* s);
	String();
	String(const String& s);
	~String();

	int length() const { return len; }
	bool stringlow();
	bool stringup();
	int amountOfSymbol(char ch);

	String &operator=(const String &s);
	String &operator=(const char *s);
	char &operator[](int i);
	const char &operator[](int i) const;

	friend std::ostream &operator<<(std::ostream &os, const String &s);
	friend std::istream &operator>>(std::istream &is, String &s);
	friend bool operator<(const String &s1, const String &s2);
	friend bool operator>(const String &s1, const String &s2);
	friend bool operator==(const String &s1, const String &s2);
	friend String operator+(const String &s1, const String &s2);
	static int HowMany() { return num_strings; }
};

const int arsize = 10;
const int MaxLen = 81;

int _tmain(int argc, _TCHAR* argv[])
{
	using std::cout;
	using std::cin;
	using std::endl;
	
	String s1(" and I am a C++ student.");
	String s2("Please enter your name: ");
	String s3;

	cout << s2;
	cin >> s3;
	
	s2 = "My name is " + s3;
	cout << s2 << ".\n";

	s2 = s2 + s1;
	s2.stringup();
	cout << "The string\n" << s2 << "\ncontains " << s2.amountOfSymbol('A')
		<< " 'A' characters in it.\n";

	s1 = "red";

	String rgb[3] = { String(s1), String("green"), String("blue") };

	cout << "Enter the name of a primary color for mixing light: ";
	String ans;
	bool succsess = false;

	while (cin >> ans) {
		ans.stringlow();
		for (int i = 0; i < 3; ++i) {
			if (ans == rgb[i]) {
				cout << "That's right!\n";
				succsess = true;
				break;
			}
		}
		if (succsess)
			break;
		else
			cout << "Try again!\n";
	}
	cout << "Bye!\n";

	return 0;
}

int String::num_strings = 0;

String::String(const char *s) {
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	++num_strings;
}

String::String() {
	len = 0;
	str = new char[len + 1];
	str[0] = '\0';
	++num_strings;
}

String::String(const String &s) {
	len = s.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, s.str);
	++num_strings;
}

String::~String() {
	--num_strings;
	delete[] str;
}

bool String::stringlow() {
	for (int i = 0; i < len; ++i)
		str[i] = tolower(str[i]);
	return true;
}

bool String::stringup() {
	for (int i = 0; i < len; ++i)
		str[i] = toupper(str[i]);
	return true;
}

int String::amountOfSymbol(char ch) {
	int count = 0;
	for (int i = 0; i < len; ++i) {
		if (str[i] == ch)
			++count;
	}
	return count;
}

String & String::operator=(const String &s) {
	if (&s == this)
		return *this;
	delete[] str;
	len = s.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, s.str);
	return *this;
}

String & String::operator=(const char *s) {
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	return *this;
}

char & String::operator[](int i) {
	return str[i];
}

const char & String::operator[](int i) const {
	return str[i];
}

bool operator<(const String &s1, const String &s2) {
	return (strcmp(s1.str, s2.str) < 0);
}

bool operator>(const String &s1, const String &s2) {
	return s2.str < s1.str;
}

bool operator==(const String &s1, const String &s2) {
	return (strcmp(s1.str, s2.str) == 0);
}

String operator+(const String &s1, const String &s2) {
	String temp;
	delete[] temp.str;
	temp.len = strlen(s1.str) + strlen(s2.str);
	temp.str = new char[temp.len + 1];
	strcpy_s(temp.str, s1.len + 1, s1.str);
	strcat_s(temp.str, temp.len + 1, s2.str);
	return temp;
}

std::ostream & operator<<(std::ostream &os, const String &s) {
	os << s.str;
	return os;
}

std::istream & operator>>(std::istream &is, String &s) {
	char temp[String::cinlim];
	is.get(temp, String::cinlim);
	if (is)
		s = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}