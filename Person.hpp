#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>	//Should i put iostream before include guards ?

class Person {
	int age;
public:
	Person(int a = NULL) :age(a) {}
	int getAge();
	void putAge();
};
#endif	//PERSON_HPP