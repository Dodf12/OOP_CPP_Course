// Starter test program for CSCI 60 Homework 5; due Wednesday 10/30/24

#include <iostream>
#include "parity.h"

using namespace std;

int main()
{

	Parity p; // a 0-argument function is implemented for you
	p.insert(3);
	p.insert(5);
	p.insert(-1);
	p.insert(2);
	p.insert(6);
	p.insert(8);
	p.insert(10);
	p.insert(7);
	p.insert(-2);
	p.insert(11);
	p.insert(15);

	int arr[11] = {3, 5, -1, 2, 6, 8, 10, 7, -2, 11, 15};
	Parity p2(arr, 11);

	cout << "Min: " << p.min() << endl;
	cout << "Max: " << p.max() << endl;
	cout << "Odd? " << (p.odd() ? "yes" : "no") << endl;
	cout << p; // the stub function for << exists but doesn't output anything

	// cout << "Min: " << p.min() << endl;
	// cout << "Max: " << p.max() << endl;
	// cout << "Odd? " << (p.odd()?"yes":"no") << endl;
	return 0;
}
