#include "Node.hpp"

Node* Node::getNext() {
	return this->next;
}
Node* Node::chengeNext(Node* obj) {
	return this->next = obj;
}
Person Node::getObject() {
	return this->object;
}
void Node::putObject() {
	this->object.putAge();
}