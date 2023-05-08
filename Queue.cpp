#include "Queue.hpp"

void Queue::enqueue(Person* newPerson) {
	Node* newNode = new Node;
	newNode->putObject(newPerson);	// dodaje
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->chengeNext(newNode);
		tail = newNode;
	}
}
Node* Queue::dequeue() {
	Node* tmp = this->head;
	if (tmp == nullptr) {
		this->tail = nullptr;
	}
	else {
		this->head = tmp->getNext();
	}
	return tmp;
}
Node* Queue::getHead() {
	return this->head;
}