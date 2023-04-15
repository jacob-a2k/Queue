#include <iostream>
#include "Queue.hpp"
#include "Person.hpp"

using namespace std;

void Queue::enqueue(Person* newTail) {
	if (head == nullptr) {
		head = newTail;
		tail = newTail;
	}
	else {
		tail->changeNext(newTail);
		tail = newTail;
	}
}
Person* Queue::dequeue() {
	Person* tmp = this->head;
	if (tmp == nullptr) {
		this->tail = nullptr;
	}
	else {
		this->head = tmp->getNext();
	}
	return tmp;
}
Person* Queue::getHead() {
	return this->head;
}