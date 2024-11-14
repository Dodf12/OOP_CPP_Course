// Starter test program for CSCI 60 Homework 5; due Wednesday 10/30/24

#include <iostream>
#include "parity.h"

using namespace std;

int main()
{

	int arr[3] = {2,6,8};
	Parity p2(arr, 3);
	p2.insert(5);
	p2.insert(-1);
	p2.insert(2);
	p2.insert(6);
	p2.insert(8);
	p2.insert(10);
	p2.insert(7);
	p2.insert(-2);
	p2.insert(11);
	p2.insert(15);
	p2.insert(5);


	//cout << "HI" << endl;
	cout << p2 << endl;

	cout << "Number of 5's removed: " << p2.remove(5) << endl;
	p2.remove(6);
	p2.remove(7);
	p2.remove(11);
	p2.remove(15);
	cout << "Removing a nonexistent value: " << p2.remove(-22) << endl;



	cout << "Object p2: "<< endl << p2 << endl;

	Parity p3;
	p3 = p2;
	cout << "Object p3: " << p3 << endl;

	Parity p4(p3);
	cout << "Object p4: " << p4 << endl;

	cout << "Min: " << p2.min() << endl;
	cout << "Max: " << p2.max() << endl;
	cout << "Odd? " << (p2.odd() ? "yes" : "no") << endl;
	cout << p2; // the stub function for << exists but doesn't output anything

	cout << "Min: " << p2.min() << endl;
	cout << "Max: " << p2.max() << endl;
	cout << "Odd? " << (p2.odd()?"yes":"no") << endl;
	return 0;
}
