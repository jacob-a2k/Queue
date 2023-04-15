#ifndef CONSOLEQUEUEDEMO_HPP
#define CONSOLEQUEUEDEMO_HPP

#include <iostream>
#include "Queue.hpp"

class ConsoleQueueDemo {
public:
	void menu();
	char chooseChar();
	void display(Queue& obj);
	void queue_methods(Queue* queue_ptr);
};
#endif // CONSOLEQUEUEDEMO_HPP
