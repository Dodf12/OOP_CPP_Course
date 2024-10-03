//This is the driver 

#ifndef DURATION_H
#define DURATION_H

#include <iostream>
using namespace std;

class Duration
{
public:
	Duration() : mins(0) {}
	Duration(int mins) : mins(mins) {}
	Duration(int hrs, int mins) : mins(hrs*60 + mins) { }

	
	string toString();

	//accessor
	// int getMins() { return mins};

	friend Duration sumDuration(const Duration &lhs, const Duration &rhs);
	

	friend Duration operator +(const Duration& lhs, const Duration& rhs);

private:
	int mins;

};

//Mine doesnt even comile


#endif