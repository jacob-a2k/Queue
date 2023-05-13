#ifndef	INTCLASS_HPP
#define	INTCLASS_HPP
#include <iostream>

class intClass
{
	int number;
public:
	intClass(int n = NULL) :number(n) {}
	int getInt();
	void putInt(const int x);
};
#endif //INTCLASS_HPP
