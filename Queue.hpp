#ifndef QUEUE_HPP
#define QUEUE_HPP

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
	Person* getHead();
};
#endif //QUEUE_HPP