#include <iostream>
#include <limits>
#include <string>
#include "Queue.hpp"
#include "Person.hpp"

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
	cout << "\n---------------QUEUE---------------" << endl;
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
	this->age = this->putAge();
	this->next = nullptr;
}
void Person::changeNext(Person* obj) {
	this->next = obj;
}
int Person::putAge() {		// blad gdy po cyfrach wystepuje jakas litera
	int tmp = 0;
	string number;
	bool valid = false;
	cin.get();
	while(!valid) {
		cout << "Input age: ";
		getline(cin, number);
		valid = isValid(number);
		if (!valid) {
			cout << "Invalid input!" << endl;
		}
	}
	tmp = stoi(number);
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
bool Person::isValid(string number) {
	int size = 0;
	bool valid = true;
	size = number.length();
	if (size) {
		for (int i = 0; i < size; i++) {
			if (!isdigit(number[i])) {
				valid = false;
			}
		}
	}
	else {
		valid = false;
	}
	return valid;
}