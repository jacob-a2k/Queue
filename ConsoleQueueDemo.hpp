#ifndef CONSOLEQUEUEDEMO_HPP
#define CONSOLEQUEUEDEMO_HPP

#include "Queue.hpp"

class ConsoleQueueDemo {
	void menu();
	char chooseChar();
	void display(Queue* obj);
	int getInt();
	bool isValidNumber(std::string);
public:
	void queue_methods(Queue* queue_obj);
};
#endif // CONSOLEQUEUEDEMO_HPP
