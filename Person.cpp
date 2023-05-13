#include "Person.hpp"
#include <string>

bool isValid(std::string number);

int Person::getAge() {
	return this->age;
}
void Person::putAge(const int number) {
	this->age = number;
}