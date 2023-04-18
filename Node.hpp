#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include "Person.hpp"

class Node {
	Person object;
	Node* next;
public:
	Node(Person o = NULL, Node* n = nullptr) : object(o), next(n) {}
	Node* getNext();
	Person getObject();
	void putObject();
};
Node* Node::getNext() {
	return this->next;
}
Person Node::getObject() {
	return this->object;
}
void Node::putObject() {
	this->object.putAge();
}
#endif	//NODE_HPP