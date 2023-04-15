#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>	//Should i put iostream before include guards ?

class Person {
	int age;
	Person* next;
public:
	void fillData();
	int getAge();
	int putAge();
	Person* getNext();
	void changeNext(Person* obj);
	bool isValid(std::string number);
};
#endif	//PERSON_HPP