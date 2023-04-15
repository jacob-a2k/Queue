#include <iostream>
#include <limits>
#include <string>
#include "Queue.hpp"
#include "Person.hpp"

using namespace std;

void menu();
char chooseChar();
void display(Queue& obj);
bool isValid(std::string number);

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
			display(*this);
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

void menu() {
	cout << "\n---------------QUEUE---------------" << endl;
	cout << "Choose one of the following options" << endl;
	cout << " +  enqueue " << endl;
	cout << " -  dequeue " << endl;
	cout << " x  to exit " << endl;
	cout << " d  to display" << endl;
}
char chooseChar() {
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
void display(Queue& obj) {
	Person* current = obj.getHead();
	cout << endl;
	while (current != nullptr) {
		cout << current->getAge() << ", ";
		current = current->getNext();
	}
	cout << endl;
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
Person* Queue::getHead() {
	return this->head;
}