#include <iostream>

using namespace std;

class Person :public Queue {
	int age;
	Person* next;
};

class Queue {
	Person* head;
	Person* tail;
public:
	Queue(Person* h = nullptr, Person* t = nullptr) :head(h), tail(t) {}
	void queue_methods();
	void enqueue();
};