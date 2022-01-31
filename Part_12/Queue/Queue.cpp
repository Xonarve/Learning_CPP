// Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

const int MIN_PER_HR = 60;
bool newcustomer(double x);

class Customer {
	long arrive;
	long processtime;
public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when() const { return arrive; }
	long ptime() const { return processtime; }
};

typedef Customer Item;

class Queue {
	enum { Q_SIZE = 10 };
	struct Node {
		Item item;
		Node *next;
	};
	Node *front;
	Node *rear;
	int items;
	const int qsize;

	Queue(const Queue &q) : qsize(0) {  };
	Queue &operator=(const Queue &q) { return *this; };
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queueconst() const;
	bool enqueue(const Item& item);
	bool dequeue(Item& item);
};

int _tmain(int argc, _TCHAR* argv[])
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::ios_base;

	std::srand(std::time(0));
	cout << "Case study: Bank of Heahter Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;

	Queue line(qs);

	cout << "Enter the number of simulation hours: ";
	int hours;
	cin >> hours;
	
	long cyclelimit = MIN_PER_HR * hours;
	cout << "Enter the number of customers per hour: ";
	double perhour;
	cin >> perhour;

	double min_per_cust;
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	long wait_time = 0;
	long line_wait = 0;

	for (int cycle = 0; cycle < cyclelimit; ++cycle) {
		if (newcustomer(min_per_cust)) {
			if (line.isfull())
				++turnaways;
			else {
				++customers;
				temp.set(cycle);
				line.enqueue(temp);
			}
		}
		if (wait_time <= 0 && !line.isempty()) {
			line.dequeue(temp);
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			++served;
		}
		if (wait_time > 0)
			--wait_time;
		sum_line += line.queueconst();
	}
	if (customers > 0) {
		cout << "customers accepted: " << customers << endl;
		cout << "customers served: " << served << endl;
		cout << "turnaways: " << turnaways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / cyclelimit << endl;
		cout << "average wait time: "
			<< (double)line_wait / served << " minutes\n";
	}
	else
		cout << "No customers!\n";
	
	cout << "Done!\n";
	return 0;
}

Queue::Queue(int qs) : qsize(qs) {
	front = rear = nullptr;
	items = 0;
}

bool Queue::isempty() const {
	return items;
}

bool Queue::isfull() const {
	return (items == qsize);
}

int Queue::queueconst() const {
	return items;
}

bool Queue::enqueue(const Item &item) {
	if (isfull())
		return false;
	Node *add = new Node;
	add->item = item;
	add->next = nullptr;
	++items;
	if (front == nullptr)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}

bool Queue::dequeue(Item &item) {
	if (front == nullptr)
		return false;
	item = front->item;
	--items;
	Node *temp = front;
	front = front->next;
	delete temp;
	if (!items)
		rear = nullptr;
	return true;
}

Queue::~Queue() {
	Node *temp;
	while (front != nullptr){
		temp = front;
		front = front->next;
		delete temp;
	}
}

void Customer::set(long when) {
	processtime = std::rand() % 3 + 1;
}

bool newcustomer(double x) {
	return std::rand() * x / RAND_MAX < 1;
}