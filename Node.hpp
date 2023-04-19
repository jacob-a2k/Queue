#ifndef NODE_HPP
#define NODE_HPP

#include "Person.hpp"

class Node {
	Person object;
	Node* next;
public:
	Node(Person o = NULL, Node* n = nullptr) : object(o), next(n) {}
	Node* getNext();
	Node* chengeNext(Node* obj);
	Person getObject();
	void putObject();
};
#endif	//NODE_HPP