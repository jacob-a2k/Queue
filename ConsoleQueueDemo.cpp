#include "ConsoleQueueDemo.hpp"
#include <limits>


void ConsoleQueueDemo::menu() {
	std::cout << "\n---------------QUEUE---------------" << std::endl;
	std::cout << "Choose one of the following options" << std::endl;
	std::cout << " +  enqueue " << std::endl;
	std::cout << " -  dequeue " << std::endl;
	std::cout << " x  to exit " << std::endl;
	std::cout << " d  to display" << std::endl;
}
char ConsoleQueueDemo::chooseChar() {
	char sign;
	std::cin >> sign;
	while (sign != '+' && sign != '-' && sign != 'x' && sign != 'd') {
		std::cout << "Please input correct sign" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> sign;
	}
	return sign;
}
void ConsoleQueueDemo::display(Queue* obj) {
	Node* current = obj->getHead();
	std::cout << std::endl;
	while (current != nullptr) {
		Person tmp = current->getObject();
		std::cout << tmp.getAge() << ", ";
		current = current->getNext();
	}
	std::cout << std::endl;
}
#include <string>

bool ConsoleQueueDemo::isValidNumber(std::string number) {
	int size = number.length();
	bool valid = true;
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
int ConsoleQueueDemo::getInt() {
	int tmp = 0;
	std::string number;
	bool valid = false;
	std::cin.get();
	while (!valid) {
		std::cout << "Input nubmer: ";
		getline(std::cin, number);
		valid = isValidNumber(number);
		if (!valid) {
			std::cout << "Invalid input!" << std::endl;
		}
	}
	tmp = stoi(number);
	return tmp;
}
void ConsoleQueueDemo::queue_methods(Queue* queue_obj) {
	char sign = 0;
	while (sign != 'x') {
		menu();
		sign = chooseChar();
		switch (sign) {
		case '+': {
			Person* newPerson = new Person; // dodaje
			int age = getInt();
			newPerson->putAge(age);
			queue_obj->enqueue(newPerson);
		}
				break;
		case '-': {
			Node* tmp = queue_obj->dequeue();
			if (tmp == nullptr) {
				std::cout << "The Queue is empty! First add new element!" << std::endl;
			}
			delete tmp;
			tmp = nullptr;
		}
				break;
		case 'x':
			break;
		case 'd': {
			display(queue_obj);
			if (queue_obj->getHead() == nullptr) {
				std::cout << "The Queue is empty! First add new element!" << std::endl;
			}
		}
				break;
		default:
			std::cout << "Unknow error!" << std::endl;
		}
	}
}