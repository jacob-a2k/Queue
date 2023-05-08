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
void ConsoleQueueDemo::queue_methods(Queue* queue_obj) {
	char sign = 0;
	while (sign != 'x') {
		menu();
		sign = chooseChar();
		switch (sign) {
		case '+': {
			Person* newPerson = new Person; // dodaje
			newPerson->putAge();
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