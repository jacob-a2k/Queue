#include "Node.hpp"

Node* Node::getNext() {
	return this->next;
}
void Node::chengeNext(Node* obj) {
	this->next = obj;
}
Person Node::getObject() {
	return this->object;
}
//void Node::putObject(Person* obj) {		// dodaje
//	this->object = *obj;
//}
void Node::putObject(Person obj) {
	this->object = obj;
}