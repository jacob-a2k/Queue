#include <iostream>
#include <limits>
#include <conio.h>
#include "Queue.hpp"

using namespace std;

void Queue::queue_methods() {
	char sign = 0;
	while (sign != 'x') {
		menu();
		sign = chooseChar();
		switch (sign) {
		case '+': {
			Person* newPerson = new Person;
			newPerson->fillData();
			this->enqueue(newPerson);
		}
				break;
		case '-': {
			Person* tmp = this->dequeue();
			if (tmp == nullptr) {
				cout << "The Queue is empty! First add new element!" << endl;
			}
			delete tmp;
			tmp = nullptr;
		}
				break;
		case 'x':
			break;
		case 'd': {
			this->display();
			if (head == nullptr) {
				cout << "The Queue is empty! First add new element!" << endl;
			}
		}
				break;
		default:
			cout << "Unknow error!" << endl;
		}
	}
}

void Queue::menu() {
	cout << "---------------QUEUE---------------" << endl;
	cout << "Choose one of the following options" << endl;
	cout << " +  enqueue " << endl;
	cout << " -  dequeue " << endl;
	cout << " x  to exit " << endl;
	cout << " d  to display" << endl;
}
char Queue:: chooseChar() {
	char sign;
	cin >> sign;
	while (sign != '+' && sign != '-' && sign != 'x' && sign != 'd') {
		cout << "Please input correct sign" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> sign;
	}
	return sign;
}
void Person::fillData() {
	cout << "Input age: ";
	this->age = this->putAge();
	this->next = nullptr;
}
void Person::changeNext(Person* obj) {
	this->next = obj;
}
int Person::putAge() {		// trzeba ta funkcje poprawic, ale to nie jest najwazniejsze
	int tmp = 0;
	cin >> tmp;
	while (!cin.good()) {
		cout << "Put number!" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> tmp;
	}
	return tmp;
}
void Queue::enqueue(Person* newTail) {
	if (head == nullptr) {
		head = newTail;
		tail = newTail;
	}
	else {
		tail->changeNext(newTail);
		tail = newTail;
	}
}
Person* Person::getNext() {
	return this->next;
}
int Person::getAge() {
	return this->age;
}
void Queue::display() {
	Person* current = this->head;
	while (current != nullptr) {
		cout << current->getAge() << endl;
		current = current->getNext();
	}
}
Person* Queue::dequeue() {
	Person* tmp = this->head;
	if (tmp == nullptr) {
		this->tail = nullptr;
	}
	else {
		this->head = tmp->getNext();
	}
	return tmp;
}