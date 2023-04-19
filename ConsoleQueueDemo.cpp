#include "ConsoleQueueDemo.hpp"
#include <limits>

void ConsoleQueueDemo::menu() {
	cout << "\n---------------QUEUE---------------" << endl;
	cout << "Choose one of the following options" << endl;
	cout << " +  enqueue " << endl;
	cout << " -  dequeue " << endl;
	cout << " x  to exit " << endl;
	cout << " d  to display" << endl;
}
char ConsoleQueueDemo::chooseChar() {
	char sign;
	cin >> sign;
	while (sign != '+' && sign != '-' && sign != 'x' && sign != 'd') {
		cout << "Please input correct sign" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> sign;
	}
	return sign;
}
void ConsoleQueueDemo::display(Queue* obj) {
	Node* current = obj->getHead();
	cout << endl;
	while (current != nullptr) {
		Person tmp = current->getObject();
		cout << tmp.getAge() << ", ";
		current = current->getNext();
	}
	cout << endl;
}
void ConsoleQueueDemo::queue_methods(Queue* queue_obj) {
	char sign = 0;
	while (sign != 'x') {
		menu();
		sign = chooseChar();
		switch (sign) {
		case '+': {
			Node* newNode = new Node;
			newNode->putObject();
			queue_obj->enqueue(newNode);
		}
				break;
		case '-': {
			Node* tmp = queue_obj->dequeue();
			if (tmp == nullptr) {
				cout << "The Queue is empty! First add new element!" << endl;
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
				cout << "The Queue is empty! First add new element!" << endl;
			}
		}
				break;
		default:
			cout << "Unknow error!" << endl;
		}
	}
}