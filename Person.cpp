#include <iostream>
#include "Person.hpp"
#include <string>

using namespace std;

bool isValid(string number);

void Person::fillData() {
	this->age = this->putAge();
	this->next = nullptr;
}
int Person::getAge() {
	return this->age;
}
int Person::putAge() {
	int tmp = 0;
	string number;
	bool valid = false;
	cin.get();
	while (!valid) {
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
Person* Person::getNext() {
	return this->next;
}
void Person::changeNext(Person* obj) {
	this->next = obj;
}
bool isValid(string number) {
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