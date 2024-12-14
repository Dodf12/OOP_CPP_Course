// Driver program for CSCI 60 Homework 9; due Thursday 12/5/24
//
// MILESTONE 0: Implement stub functions in the other .cpp files to make sure
// this compiles. Once you do, add test code as you work through Milestones 1-4
// to make sure each function is implemented correctly before moving on.
// This file is just for you; do not turn it in.

#include <iostream>
#include "parity.h"

using namespace std;

int main() {
  Parity lists;
  std::cout << "intersting 0" << std::endl;
  lists.insert(0);
  std::cout << "intersting 1" << std::endl;
  lists.insert(1);
  std::cout << "intersting 8" << std::endl;
  lists.insert(8);
  std::cout << "intersting -2" << std::endl;
  lists.insert(-2);
  std::cout << "intersting 7" << std::endl;
  lists.insert (7);
  lists.insert(6);
  lists.insert(6);
  lists.insert(6);
  lists.insert(6);
  lists.insert(6);
  lists.insert(6);
  lists.insert(6);
  lists.insert(6);
  
  cout << "Tests << operator " << endl;
  cout << lists << endl;

  cout << "Test Min: " << endl;
  cout << lists.min() << endl;

  cout << "Test Max: " << endl;
  cout << lists.max() << endl;



  cout << "Test copy contrsuctor" << endl;
  // Parity p1;
  // for (int i = 1; i <= 100; ++i) {
  //     p1.insert(i);
  // }
  Parity p2(lists);  // Copy a large list


  cout << "lists " << lists << endl;
  cout << "p2 " << p2 << endl;

  cout << "Test equal operator" << endl;
  Parity listsB = lists;
  cout << "original object " << lists << endl;
  cout << "Overidden Object " << listsB << endl;


  cout << "Iterator test " << endl;
  cout << "Creating new object " << endl;

  Parity b;
  b.insert(7);
  b.insert(0);
  b.insert(-2);
  b.insert(1);
  b.insert(8);
  
  cout << "At iterator " << endl;

  cout << "Testing the !=, begin, end and Prefix ++ is working" << endl;
  for (Parity::iterator it = b.begin(); it != b.end(); ++it) 
    { 
      cout << *it << endl; 
    }

  cout << "Range based for loop test " << endl;
  for (int i : b) { cout << i << endl;}

  cout << "Testing the Postfix ++ is working" << endl;
  for (Parity::iterator it = b.begin(); it != b.end(); it++)
  {
    cout << *it << endl;
  }

  cout << "Testing the < and the > operators" << endl;
  Parity Equal1;
  Parity Equal2;  

  for (int i = 0; i < 5; i++) 
    { 
      Equal1.insert(i); 
      Equal2.insert(i);
    }

  P_iterator it1 = Equal1.begin();
  P_iterator it2 = Equal1.begin();
  ++it2;
  P_iterator it3 = Equal2.end();
  P_iterator it4 = Equal1.begin();
  ++it4;

  cout << "Testing the < on two iterators pointing to same object " << endl;
  //False
  if (it1 < it2)
    std::cout << "*it1 < *it2 is true" << std::endl;
  else
    std::cout << "*it1 < *it2 is false" << std::endl;

  cout << "Testing the < on two iterators pointing to different object " << endl;
  //Should return 0
  cout << (it1 < it3) << endl;

  cout << "This should return true" << endl;
  if (it1 < it4)
    std::cout << "*it1 < *it4 is true" << std::endl;
  else
    std::cout << "*it1 < *it4 is false" << std::endl;

  cout << "This should return false" << endl;
  if (it4 < it1)
    std::cout << "*it1 < *it4 is true" << std::endl;
  else
    std::cout << "*it1 < *it4 is false" << std::endl;



  cout << "Testing the > on two iterators pointing to same object " << endl;
  //True
  if (it1 > it2)
    std::cout << "*it1 < *it2 is true" << std::endl;
  else
    std::cout << "*it1 < *it2 is false" << std::endl;

  cout << "Testing the > on two iterators pointing to different object " << endl;
  //Should return 1
  cout << (it1 > it3) << endl;

  cout << "This should return false" << endl;
  if (it1 > it4)
    std::cout << "*it1 < *it4 is true" << std::endl;
  else
    std::cout << "*it1 < *it4 is false" << std::endl;

  cout << "This should return true" << endl;
  if (it4 > it1)
    std::cout << "*it1 < *it4 is true" << std::endl;
  else
    std::cout << "*it1 < *it4 is false" << std::endl;

  
  cout << "test destructor " << endl;
  lists.~Parity();
  cout << "Should be empty " << lists << endl;

  cout << endl;

  return 0;
}

