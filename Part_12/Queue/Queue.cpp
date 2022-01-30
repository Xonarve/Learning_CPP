// Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

typedef int Item;

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