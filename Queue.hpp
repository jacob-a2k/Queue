#include <iostream>

using namespace std;

class Person;
class Queue {
	Person* head;
	Person* tail;
public:
	Queue(Person* h = nullptr, Person* t = nullptr) :head(h), tail(t) {}
	void queue_methods();
	void enqueue(Person* newTail);
	void dequeue();
	void display();
};

class Person {
	int age;
	Person* next;
public:
	void fillData();
	void changeNext(Person* obj);
	int getAge();
	Person* getNext();
};