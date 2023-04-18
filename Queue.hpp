#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include "Node.hpp"
#include "Person.hpp"	

using namespace std;

class Queue {
	Node* head;
	Node* tail;
public:
	Queue(Node* h = nullptr, Node* t = nullptr) :head(h), tail(t) {}
	void enqueue(Node* newTail);
	Node* dequeue();
	Node* getHead();
	Node* getTail();
};
#endif //QUEUE_HPP