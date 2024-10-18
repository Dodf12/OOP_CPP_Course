#include <iostream>
#include "bag.h"

using namespace std;

int main()
{
	cout << "Any Bag has capacity " << Bag::CAPACITY << endl; // static const

    // construct an empty bag and add to it

    Bag b1; // default/0-arg constructor
    cout << "Initial bag size: " << b1.size() << endl;

    b1.insert(2); 
    b1.insert(3); 
    cout << "Size after inserting 2 and 3: " << b1.size() << "\nContents: " << b1 << endl;

    // construct a bag initialized with some contents, query, and erase from it

    int arr[5];// = {5, 4, 5, 5, 1}; // initialize an array
    arr[0]=5; arr[1]=4; arr[2]=5; arr[3]=5; arr[4]=1;
    Bag b2(arr,5); // 2-aostream& operator +(const Bag& lhs, const Bag& rhs);rg constructor
    cout << "Bag 2:\n" << b2 << endl; // use of overloaded insertion
    cout << "Bag 2 size: " << b2.size() << endl;

    cout << b2.count(5) << " 5s\n";
    
    cout << "Attempting to erase 4:\n";
    bool erased = true;
    erased = b2.erase_one(4);
    //cout << b2 << endl;
    
    Bag b3;
    b2.insert(1);
    b2.insert(2);
    b3.insert(3);
    cout << b3 << endl;
    b3.erase_one(3);
    cout << b3 << endl; 

    cout << (erased?"C":"Not c") << "hanged: " << b2 << endl;
    cout << "Attempting to erase -1:\n";
    erased = b2.erase_one(-1);
    cout << (erased?"C":"Not c") << "hanged: " << b2 << endl;
    cout << "Erasing all 5s:\n";
   // cout << b2.erase(5) << " erased: " << b2 << endl;
}