// String.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

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
	String &operator=(const String &s);
	String &operator=(const char *s);
	String operator+(const String &s);
	char &operator[](int i);
	const char &operator[](int i) const;
	friend std::ostream &operator<<(std::ostream &os, const String &s);
	friend std::istream &operator>>(std::istream &is, String &s);
	friend bool operator<(const String &s1, const String &s2);
	friend bool operator>(const String &s1, const String &s2);
	friend bool operator==(const String &s1, const String &s2);
	static int HowMany() { return num_strings; }

	void show_string() const;
};

const int arsize = 10;
const int MaxLen = 81;

int _tmain(int argc, _TCHAR* argv[])
{
	using std::cout;
	using std::cin;
	using std::endl;
	String word1("first Word_1");
	String word2("second Word_2");
	String sum_word = word1 + word2;
	cout << sum_word << endl;
	/*String name;
	cout << "Hi, what is your name?\n>> ";
	cin >> name;
	cout << name << ", please enter up to " << arsize
		<< " short sayings <empty line to quit>:\n";
	String sayings[arsize];
	char temp[MaxLen];
	int i;
	for (i = 0; i < arsize; ++i) {
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
			continue;
		if (!(cin) || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}
	int total = i;
	if (total > 0) {
		cout << "Here are your sayings:\n";
		for (i = 0; i < total; ++i)
			cout << sayings[i][0] << ": " << sayings[i] << endl;
		String *shortest = &sayings[0];
		String *first = &sayings[0];
		for (i = 1; i < total; ++i) {
			if (shortest->length() > sayings[i].length())
				shortest = &sayings[i];
			if (*first > sayings[i])
				first = &sayings[i];
		}
		cout << "Shortest saying:\n" << *shortest << endl;
		cout << "First alphabetically:\n" << *first << endl;

		srand(time(0));
		int choice = rand() % total;

		String *favorite = new String(sayings[choice]);
		cout << "My favorite saying:\n" << *favorite << endl;
		delete favorite;
	}
	else
		cout << "No input! Bye.\n";
*/
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

String String::operator+(const String &s) {
	String temp;
	delete[] temp.str;
	temp.len = strlen(str) + strlen(s.str);
	temp.str = new char[temp.len + 1];
	strcpy_s(temp.str, len + 1, str);
	std::cout << temp.len - len << std::endl;
	std::cout << strlen(s.str) << std::endl;
	strcat_s(temp.str, temp.len - len + 1, s.str);
	/*temp.len = 500;
	temp.str = new char[temp.len + 1];
	strcpy_s(temp.str, temp.len + 1, str);
	strcat_s(temp.str, temp.len + 1, s.str);*/
	return temp;
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


void String::show_string() const {
	std::cout << str << std::endl;
}