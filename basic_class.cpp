#include <iostream>
#include "Header.h"
using namespace std;

//default constructor
stack::stack() {

}

//constructor overload
stack::stack(int hi) {
	this->hi = hi;
}

//default deconstructor
stack::~stack() {

}

void stack::printhi() {
	cout << hi << endl;
}

stack stack::operator+(const stack & t) const {
	stack s;
	return s;
}


stack operator-(int & value, const stack & t) {
	stack s;

	return s;
}

void basic_class() {
	stack f_stack(10);
	f_stack.printhi();

	stack stacks[4] = {
		stack(10),
		stack(10), 
		stack(10),
		stack(10)
	};

}