#include "Queue.hpp"

using namespace std;

void Queue::enqueue(Node* newTail) {
	if (head == nullptr) {
		head = newTail;
		tail = newTail;
	}
	else {
		tail->chengeNext(newTail);
		tail = newTail;
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
Node* Queue::getTail() {
	return this->tail;
}