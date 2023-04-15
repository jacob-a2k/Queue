#include <iostream>
#include "ConsoleQueueDemo.hpp"

using namespace std;

int main() {
	Queue queue_ptr;
	ConsoleQueueDemo theQ;
	theQ.queue_methods(&queue_ptr);
	return 0;
}