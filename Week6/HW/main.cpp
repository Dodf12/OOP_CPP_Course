// Starter test program for CSCI 60 Homework 5; due Wednesday 10/30/24

#include <iostream>
#include "parity.h"

using namespace std;

int main()
{

	int arr[4] = {2,6,8};
	Parity p2(arr, 4);

	cout << "p: " << p2 << endl;
	p2.insert(4);
	cout << "p: " << p2 << endl;
	// p.insert(5);
	// p.insert(-1);
	// p.insert(2);
	// p.insert(6);
	// p.insert(8);
	// p.insert(10);
	// p.insert(7);
	// p.insert(-2);
	// p.insert(11);
	// p.insert(15);



	// cout << "Object p2: "<< endl << p2 << endl;

	// Parity p3;
	// p3 = p2;
	// cout << "Object p3: " << p3 << endl;

	// Parity p4(p3);
	// cout << "Object p4: " << p4 << endl;

	// cout << "Min: " << p.min() << endl;
	// cout << "Max: " << p.max() << endl;
	// cout << "Odd? " << (p.odd() ? "yes" : "no") << endl;
	// cout << p; // the stub function for << exists but doesn't output anything

	// cout << "Min: " << p.min() << endl;
	// cout << "Max: " << p.max() << endl;
	// cout << "Odd? " << (p.odd()?"yes":"no") << endl;
	return 0;
}
