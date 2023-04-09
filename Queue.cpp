#include <iostream>
#include <limits>
#include "Queue.hpp"

using namespace std;

void menu();
char chooseChar();

void Queue::queue_methods() {
	char sign = 0;
	while (sign != 'x') {
		menu();
		sign = chooseChar();
		switch (sign) {
		case '+': {
			Person* newPerson = new Person;
			newPerson->enqueue();
		}
				break;
		case '-': {

		}
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
	while (sign != '+' || sign != '-' || sign != 'x') {
		cout << "Please input correct sign" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> sign;
	}
	return sign;
}