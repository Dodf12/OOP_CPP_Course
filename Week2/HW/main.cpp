// Test program starter file for CSCI 60 Homework 2; due Wednesday 10/9/24
// Give a program description, list any collaborators, and write your name here

/*
Abhinav Pala 10-8-24
Main.cpp is testing to make sure the historgram file
is working correctly. Created objects and am testing
function here.
The main function was entirely written by myself
or code provided by files.
*/
#include <iostream>
#include "histogram.h"
#include <fstream>

using namespace std;
int main() {
	/* TODO: replace this comment and the code below with your unit tests */

	//Commented test code

	// int total = 0; // var to store total
	// ifstream in("data.txt"); // open a file called data.txt as an input stream in
	// int val; // var to store one int at a time
	// while (in >> val) { // read int tokens from stream 1-by-1 until end of file
	// total += val; // add value of each token to total
	// }
	// in.close(); // close file
	// cout << "Sum of all ints in a file = " << total << endl; // report total
	

	Histogram h("data.txt");
	


	//Testing out all the features I am testing
	cout << "Size of counts: "<< h.size() << endl;
	cout << "Maximum Value " <<h.max() << endl;
	cout << "Minimum Value " <<h.min() << endl;
	cout << "Mode: " << h.mode() << endl;	
	cout << "Median: " << h.median() << endl;
	cout << "Mean: " << h.mean() << endl;
	cout << "Variance: " << h.variance() << endl;


	cout << "Histogram Drawing" << endl;
	cout << h;

	/*
	Im testing operator overloader by making another object, with the
	same text file as the previous one. I am adding them together
	and using histogram drawing to show that the number of values actually
	got added
	*/
	cout << "Testing the += Operator Overloader" << endl;
	Histogram h2("data.txt");
	h+=h2;

	cout << h;




	return 0;
}
