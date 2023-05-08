#ifndef NODE_HPP
#define NODE_HPP

#include "Person.hpp"

class Node {
	Person object;
	Node* next;
public:
	Node(Person o = NULL, Node* n = nullptr) : object(o), next(n) {}
	Node* getNext();
	void chengeNext(Node* obj);
	Person getObject();
	void putObject(Person* obj);	// dodaje
};
#endif	//NODE_HPP