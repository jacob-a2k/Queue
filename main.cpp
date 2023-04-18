#include <iostream>
#include "ConsoleQueueDemo.hpp"

using namespace std;

int main() {
	Queue queue_obj;
	ConsoleQueueDemo theQ;
	theQ.queue_methods(&queue_obj);
	return 0;
}