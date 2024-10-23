// Test file illustrating memory management for classes, specifically GArray.
// Sara Krehbiel, 10/21/24-10/25/24

#include <iostream>
#include "garray.h"

using namespace std;

void insertTests();
void memoryTests();
GArray passByValueAndReturnObject(GArray arr);

int main() {
  cout << "main is beginning\n";
  insertTests();
	//memoryTests();
  cout << "main is returning\n";
	return 0;
}

void insertTests() {
  cout << "insertTests is beginning\n\n";

  GArray arr;
  cout << "arr after 0-arg construction: " << arr << endl;

  arr.insert(2);
  arr.insert(4);
  arr.insert(6);
  arr.insert(8);
  cout << "arr after four inserts: " << arr << endl;

  cout << "\ninsertTests is returning\n";
}

void memoryTests() {
  cout << "memoryTests is beginning\n";
  // set up two GArray objects and cout their contents
  GArray first;
  first.insert(1);
  first.insert(2);
  GArray second;
  second.insert(3);
  second.insert(4);
  second.insert(5);
  cout << "\nFirst: " << first << endl;
  cout << "Second: " << second << endl;

  // assignment: enforces correct memory (non-)sharing for identical objects
  cout << "\nsecond = first;\n";
  second = first; // without overloading =, this makes a shallow copy
  cout << "\nFirst: " << first << endl;
  cout << "Second: " << second << endl;

  // copy-constructor: makes a new object by deep copying an existing one 
  cout << "\nGArray third(first);\n";
  GArray third(first); 
  cout << "\nFirst: " << first << endl;
  cout << "Second: " << second << endl;
  cout << "Third: " << third << endl;

  // modifying one object shouldn't affect others if dynamic memory isn't shared
  cout << "\nfirst.insert(6);\n";
  first.insert(6); 
  cout << "\nFirst: " << first << endl;
  cout << "Second: " << second << endl;
  cout << "Third: " << third << endl;

  // uncommon, but can call destructor explicitly
  cout << "\nfirst.~GArray();\n";
  first.~GArray();

  // chained assignment requires GArray& as return type for = overload
  cout << "\nthird = second = first;\n";
  third = second = first; // chained assignment
  cout << "\nFirst: " << first << endl;
  cout << "Second: " << second << endl;
  cout << "Third: " << third << endl;

  cout << "\nEnter any character to continue: ";
  string ignore;
  cin >> ignore;

  // note other places that copy-constructor is called automatically
  cout << "\nfirst = passByValueAndReturnObject(second);\n";
  first = passByValueAndReturnObject(second);

  cout << "\nmemoryTests is returning\n"; 
  // locally declared objects call their destructors when the function returns;
  // define it to avoid orphaning memory when local vars pop off the stack
}

// note: the copy-constructor gets called when parameters are passed by val
// and when objects are returned by value; note destructor calls, too!
GArray passByValueAndReturnObject(GArray arr) { 
  cout << "fn\n"; 
  return arr; 
}

