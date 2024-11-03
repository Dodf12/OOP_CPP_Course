// Name: Abhinav Pala
// File: parity.cpp
// File Location: SCU coursework folder in CSCI 60 Folder
// Date: 10-27-24
// Collaborators:
/*
Asked my friend Kevin since I was stuck on insert function.
It would print
E: 0 2 6 8 10
O: 0 3 5 -1 7 0.

He suggest I switch linse 98 and 99, and it worked when I did that.
It was a very minor fix, that I wasn't able to catch since teh debug
statements matche dup with what was supposed to be the correct output
*/

// Descrptin: Source file for parity.h header file
#include "parity.h" // Do NOT add any additional libraries/namespaces!

// Two Argument Constructor
Parity::Parity (int *a, size_t n)
{
    // Checks if there are no elements passed in, and assigns null pointer
    if (n == 0)
        {
            evens_ = nullptr;
            odds_ = nullptr;
        }
    else
        {
            nEven_ = 0;
            nOdd_ = 0;
            evens_ = new int[CAP];
            odds_ = new int[CAP];

            /*
            Inserting elements from *a
            into the respective
            dynamic arrays
            */
            for (int i = 0; i < n; i++)
                {
                    insert (a[i]);
                }
        }
}

// Finds minimum value of all the numbers in both arrays
int Parity::min () const
{
    int minValue = INT_MAX;

    // Finding smallest number in even array
    for (int i = 0; i < nEven_; i++)
        {
            if (evens_[i] < minValue)
                {
                    minValue = evens_[i];
                }
        }

    // Finds if number in oddarray is smaller than smallest number in even array
    for (int j = 0; j < nOdd_; j++)
        {
            if (odds_[j] < minValue)
                {
                    minValue = odds_[j];
                }
        }

    return minValue;
}

// Finds largest value of the numbers in both the arrays
// Same logiv as min value, except finds largest number
int Parity::max () const
{
    int maxVal = INT_MIN;

    for (int i = 0; i < nEven_; i++)
        {
            if (evens_[i] > maxVal)
                {
                    maxVal = evens_[i];
                }
        }

    for (int j = 0; j < nOdd_; j++)
        {
            if (odds_[j] > maxVal)
                {
                    maxVal = odds_[j];
                }
        }

    return maxVal;
}

// Overloading << to get the even numbers
ostream& operator<< (ostream &out, const Parity &p)
{
    // Printing even numbers
    out << "E: ";
    for (int i = 0; i < p.nEven_; i++)
        {
            out << p.evens_[i] << " ";
        }

    /*
    I cannot put endl in the for loop because it will
    print all the numbers in a different line, which
    is not the output requirement
    */

    out << " " << endl;

    // Printing odd numbers
    out << "O: ";
    for (int j = 0; j < p.nOdd_; j++)
        {
            out << p.odds_[j] << " ";
        }
    out << " " << endl;
    return out;
}

void Parity::insert (int val)
{
    // Following code executes if val is even
    if (val % 2 == 0)
        {
            // Checks if array needs to be expanded
            if (nEven_ % CAP == 0)
                {
                    // New temporary dynamic array with updated size
                    int newEvenSize = nEven_ + CAP;
                    int *temp = new int[newEvenSize];

                    // Copy values from old array
                    for (int i = 0; i < nEven_; i++)
                        {
                            temp[i] = evens_[i];
                        }

                    // Deleting old heap memory and reassigning bigger array
                    delete[] evens_;

                    // Assign expanded array to the member pointer variable
                    evens_ = temp;

                    evens_[nEven_] = val;
                    nEven_++;
                }

            // If array doesnt need to be expanded, then goes here
            else
                {
                    // Adds value to end of array and increased size
                    evens_[nEven_] = val;
                    nEven_++;
                }
        }
    // Else is executed if val is odd
    else
        {
            if (nOdd_ % CAP == 0)
                {
                    int newOddSize = nOdd_ + CAP;

                    int *temp2 = new int[newOddSize];

                    for (int i = 0; i < nOdd_; i++)
                        {
                            temp2[i] = odds_[i];
                        }

                    delete[] odds_;
                    odds_ = temp2;

                    odds_[nOdd_] = val;
                    nOdd_++;
                }
            else
                {
                    odds_[nOdd_] = val;
                    nOdd_++;
                }
        }
}

// Odd Stub Function
/*
Logic:
IF an even number of ODD integers are added,
their sum will be even.
Even number plus an even will always be even,
regardless of how many are added together

I am checking for odd number of ODD integers.
If there are, then the total sum will be odd.
Otherwise it will be even
*/
bool Parity::odd () const
{

    if (nOdd_ % 2 == 0)
        {
            return false;
        }
    return true;
}