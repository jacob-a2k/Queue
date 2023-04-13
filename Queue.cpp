#include <iostream>
#include <limits>
#include <conio.h>
#include "Queue.hpp"

using namespace std;

void menu();
char chooseChar();
int putAge();

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

		}
				break;
		case 'x':
			break;
		default:
			cout << "Unknow error!" << endl;
		}
	}
}

void menu() {
	cout << "---------------QUEUE---------------" << endl;
	cout << "Choose one of the following options" << endl;
	cout << " +  enqueue " << endl;
	cout << " -  dequeue " << endl;
	cout << " x  to exit " << endl;
}
char chooseChar() {
	char sign;
	cin >> sign;
	while (sign != '+' && sign != '-' && sign != 'x') {
		cout << "Please input correct sign" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> sign;
	}
	return sign;
}
void Person::fillData() {
	cout << "Input age: ";
	this->age = putAge();
	this->next = nullptr;
}
void Person::changeNext(Person* obj) {
	this->next = obj;
}
int putAge() {		// trzeba ta funkcje poprawic, ale to nie jest najwazniejsze
	int tmp = _getch();
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