#ifndef CONSOLEQUEUEDEMO_HPP
#define CONSOLEQUEUEDEMO_HPP

#include <iostream>
#include <limits>
#include "Queue.hpp"

class ConsoleQueueDemo {
public:
	void menu();
	char chooseChar();
	void display(Queue& obj);
	void queue_methods(Queue* queue_ptr);
};
void ConsoleQueueDemo::menu() {
	cout << "\n---------------QUEUE---------------" << endl;
	cout << "Choose one of the following options" << endl;
	cout << " +  enqueue " << endl;
	cout << " -  dequeue " << endl;
	cout << " x  to exit " << endl;
	cout << " d  to display" << endl;
}
char ConsoleQueueDemo::chooseChar() {
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
void ConsoleQueueDemo::display(Queue& obj) {
	Person* current = obj.getHead();
	cout << endl;
	while (current != nullptr) {
		cout << current->getAge() << ", ";
		current = current->getNext();
	}
	cout << endl;
}
void ConsoleQueueDemo::queue_methods(Queue* queue_ptr) {
	char sign = 0;
	while (sign != 'x') {
		menu();
		sign = chooseChar();
		switch (sign) {
		case '+': {
			Person* newPerson = new Person;
			newPerson->fillData();
			queue_ptr->enqueue(newPerson);
		}
				break;
		case '-': {
			Person* tmp = queue_ptr->dequeue();
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
			display(*queue_ptr);
			if (queue_ptr->getHead() == nullptr) {
				cout << "The Queue is empty! First add new element!" << endl;
			}
		}
				break;
		default:
			cout << "Unknow error!" << endl;
		}
	}
}
#endif // CONSOLEQUEUEDEMO_HPP
