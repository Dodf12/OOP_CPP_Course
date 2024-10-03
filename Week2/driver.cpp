//Source code for Driver Program that uses duration class
//Must compile implementation file to run this ex
// g++ driver.cpp duration.cpp -std=c++11

#include <iostream>
#include "duration.h"

using namespace std;

int main()
{
Duration d0;
cout << "D0: " << d0.toString() << endl;

Duration d1(1,55);
Duration d2(100);

Duration total = d1 + d2;



cout << "Total: " << total.toString() << endl;
cout << "D1: " << d1.toString() << endl;


total = d1+d2;
cout << "Total: " << total.toString() << endl;
return 0;
}