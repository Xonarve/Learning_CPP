// AnotherStack_task4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

typedef unsigned long Item;

class Stack {
	enum {Max = 10};
	Item *pitems;
	int size; 
	int top;
public:
	Stack(int n = Max);
	Stack(const Stack &st);
	~Stack();

	bool isempty() const;
	bool isfull() const;

	bool push(const Item &item);
	bool pop(Item &item);

	Stack &operator=(const Stack &st);

	void print(const int size);
	/*friend void print(const Stack &st, const int size);*/

};

int _tmain(int argc, _TCHAR* argv[])
{	
	const int Len = 25;
	Item pull[Len];
	int i;
	for (i = 0; i < Len; ++i) {
		pull[i] = std::rand() % 100;
		std::cout << pull[i] << " ";
	}
	std::cout << std::endl;

	Stack defaultStack;
	for (i = 0; i < 10; ++i)
		defaultStack.push(pull[i]);
	std::cout << "defaultStack: ";
	defaultStack.print(10);

	Stack anotherStack = defaultStack;
	std::cout << "another stack: ";
	anotherStack.print(10);

	Stack bigStack(25);
	for (i = 0; i < Len; ++i) {
		bigStack.push(pull[i]);
	}
	std::cout << "A big stack: ";
	bigStack.print(25);

	defaultStack = bigStack;
	std::cout << "new default Stack: ";
	defaultStack.print(25);

	Item oneElement;
	defaultStack.pop(oneElement);
	std::cout << oneElement << std::endl;

	return 0;
}

Stack::Stack(int n) {
	size = n;
	pitems = new Item[size];
	top = 0;
}

Stack::Stack(const Stack &st) {
	size = st.size;
	top = st.top;
	pitems = new Item[size];
	for (int i = 0; i < top; ++i)
		pitems[i] = st.pitems[i];
}

Stack::~Stack() {
	delete[] pitems;
}

bool Stack::isempty() const {
	return (top == 0);
}

bool Stack::isfull() const {
	return (top == size);
}

bool Stack::push(const Item &item) {
	if (isfull()) {
		static int count = 1;
		std::cout << count << " Stack already is full!\a\n";
		++count;
		return false;
	}
	else {
		pitems[top] = item;
		++top;
		return true;
	}
}

bool Stack::pop(Item &item) {
	if (isempty()) {
		static int count = 1;
		std::cout << count << " Stack is empty!\a\n";
		++count;
		return false;
	}
	else {
		item = pitems[--top];
		return true;
	}
}

Stack & Stack::operator=(const Stack &st) {
	if (this == &st)
		return *this;
	else {
		delete[] pitems;
		size = st.size;
		top = st.top;
		pitems = new Item[size];
		for (int i = 0; i < top; ++i)
			pitems[i] = st.pitems[i];
		return *this;
	}
}

void Stack::print(const int size) {
	for (int i = 0; i < size; ++i)
		std::cout << pitems[i] << " ";
	std::cout << std::endl;
}