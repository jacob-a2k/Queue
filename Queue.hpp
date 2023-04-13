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
	Person* dequeue();
	void display();
	char chooseChar();
	void menu();
};

class Person {
	int age;
	Person* next;
public:
	void fillData();
	int getAge();
	int putAge();
	Person* getNext();
	void changeNext(Person* obj);
};