#pragma once  //???
#ifndef ALL_H_
#define ALL_H_
const int MAX_ITEM = 1000;

//enumeration
//"Action" is enumeration tag
enum Action {
	stop,
	sit,
	stand,
	walk,
	run
};

class stack {
	private:
		int hi;
		int count;
		int data[MAX_ITEM];

		//類別範疇常數
		enum {Months = 12};
		static const int GG = 12;
		enum class date{Months, Year};

	public:
		stack();
		stack(int hi);
		~stack();

		void printhi();

		//operator function
		//operator (argument-list)

		//operator overloading
		//ex: *
		//it can use for pointer or multiply

		stack operator+(const stack & s) const; 
		//const => can't fix any member variable
		//      => can't call any not const member function

		//not the member function : 
		//although it isn't member function, but it's permission is same as member function
		friend stack operator-(int value, const stack & s);

};

void basic_class();

#endif