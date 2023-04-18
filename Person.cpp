#include <iostream>
#include "Person.hpp"
#include <string>

using namespace std;

bool isValid(string number);

int Person::getAge() {
	return this->age;
}
void Person::putAge() {
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
	this->age = tmp;
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