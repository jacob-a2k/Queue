#include "Person.hpp"
#include <string>

bool isValid(std::string number);

int Person::getAge() {
	return this->age;
}
void Person::putAge() {
	int tmp = 0;
	std::string number;
	bool valid = false;
	std::cin.get();
	while (!valid) {
		std::cout << "Input age: ";
		getline(std::cin, number);
		valid = isValid(number);
		if (!valid) {
			std::cout << "Invalid input!" << std::endl;
		}
	}
	tmp = stoi(number);
	this->age = tmp;
}
bool isValid(std::string number) {
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