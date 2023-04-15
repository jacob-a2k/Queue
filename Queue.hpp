#include <iostream>
#include "Person.hpp"		

using namespace std;

class Queue {
	Person* head;
	Person* tail;
public:
	Queue(Person* h = nullptr, Person* t = nullptr) :head(h), tail(t) {}
	void queue_methods();
	void enqueue(Person* newTail);
	Person* dequeue();
	void display();
	char chooseChar();
	void menu();
};