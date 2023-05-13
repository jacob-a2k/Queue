#include "ConsoleQueueDemo.hpp"

void testLoop();

int main() {
	Queue queue_obj;
	ConsoleQueueDemo theQ;
	theQ.queue_methods(&queue_obj);
	return 0;
}