#ifndef QUEUE_HPP
#define QUEUE_HPP

// #include "intClass.hpp"
#include "Person.hpp"
#include "Node.hpp"	

class Queue {
	Node* head;
	Node* tail;
public:
	Queue(Node* h = nullptr, Node* t = nullptr) :head(h), tail(t) {}
	void enqueue(Person* newPerson);	// dodaje
	Node* dequeue();
	Node* getHead();
};
#endif //QUEUE_HPP