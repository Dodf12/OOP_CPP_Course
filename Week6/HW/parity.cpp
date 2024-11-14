// Name: Abhinav Pala
// File: parity.cpp
// File Location: SCU coursework folder in CSCI 60 Folder
// Date 11-6-24
// Collaborators:
/*
    I was getting a **malloc error, and didnt know what 
    that so i had to google it.
*/
// Descrption: Implementation file for parity.h redone for HW 6

#include "parity.h"

// Two Argument Constructor
Parity::Parity(int *a, size_t n)
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

// Copy Constructor
Parity::Parity(const Parity& rhs)
{
    nEven_ = rhs.nEven_;
    nOdd_ = rhs.nOdd_;

    evens_ = new int[nEven_];
    odds_ = new int[nOdd_];

    for (int i = 0; i < nEven_; i++)
        {
            evens_[i] = rhs.evens_[i];
        }
    for (int j = 0; j < nOdd_; j++)
        {
            odds_[j] = rhs.odds_[j];
        }
}

// Destructor
Parity::~Parity()
{
    delete[] evens_;
    delete[] odds_;

    evens_ = nullptr;
    odds_ = nullptr;

    nEven_ = 0;
    nOdd_ = 0;
}

// Overloaded = operator to perform a deep copy of values from rhs into lhs
Parity& Parity::operator=(const Parity& rhs)
{
    nEven_ = rhs.nEven_;
    nOdd_ = rhs.nOdd_;

    // Delete lhs dynamic memory so I can reassign with rhs
    delete[] evens_;
    delete[] odds_;

    evens_ = new int[nEven_];
    odds_ = new int[nOdd_];

    for (int i = 0; i < nEven_; i++)
        {
            evens_[i] = rhs.evens_[i];
        }
    for (int j = 0; j < nOdd_; j++)
        {
            odds_[j] = rhs.odds_[j];
        }
    return *this;
}

// From HW5
int Parity::min() const
{
    int min = INT_MAX;

    for (int i = 0; i < nEven_; i++)
        {
            if (evens_[i] < min)
                {
                    min = evens_[i];
                }
        }

    for (int j = 0; j < nOdd_; j++)
        {
            if (odds_[j] < min)
                {
                    min = odds_[j];
                }
        }

    return min;
}

// From HW5
int Parity::max() const
{
    int max = INT_MIN;

    for (int i = 0; i < nEven_; i++)
        {
            if (evens_[i] > max)
                {
                    max = evens_[i];
                }
        }

    for (int j = 0; j < nOdd_; j++)
        {
            if (odds_[j] > max)
                {
                    max = odds_[j];
                }
        }

    return max;
}

// From HW5
ostream& operator<<(ostream& out, const Parity& p)
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

// The insert and remove function are the CURRENT HOMEWORK
void Parity::insert(int val)
{
    // Stores index of where val should be stored
    int index = 0;
    int *tempArray = nullptr;

    if (val % 2 == 0)
        {
            // Only creates a new array if current size is multiple of Cap
            if (nEven_ % CAP == 0)
                {
                    // Copy all values into tempArray
                    tempArray = new int[nEven_ + CAP];
                    for (int i = 0; i < nEven_; i++)
                        {
                            tempArray[i] = evens_[i];
                        }

                    // Set evens_ array to new one
                    delete[] evens_;
                    evens_ = tempArray;
                    tempArray = nullptr;
                }

            // Finds the index of the place where val must be inserted
            index = 0;
            while (val > evens_[index] && index < nEven_)
                {
                    index++;
                }

            /*
            Moves the elements to the right starting from the right edge to
            the index of insertion
            */
            for (int i = nEven_; i > index; i--)
                {
                    evens_[i] = evens_[i - 1];
                }

            /*
                Increments size variable of the even array and adds the value
                at the correct index
            */
            nEven_++;
            evens_[index] = val;
        }

    // If val is odd, it goes here. Exact same logic as top
    else
        {
            if (nOdd_ % CAP == 0)
                {
                    tempArray = new int[nOdd_ + CAP];
                    for (int i = 0; i < nOdd_; i++)
                        {
                            tempArray[i] = odds_[i];
                        }

                    delete[] odds_;
                    odds_ = tempArray;
                    tempArray = nullptr;
                }

            index = 0;
            while (val > odds_[index] && index < nOdd_)
                {
                    index++;
                }

            for (int i = nOdd_; i > index; i--)
                {
                    odds_[i] = odds_[i - 1];
                }

            nOdd_++;
            odds_[index] = val;
        }
}

// Removes all elements of val that are in the array
size_t Parity::remove(int val)
{
    int *temp = nullptr;

    // Tracks number of values in the array
    int numOfVal = 0;

    // Check if its even
    if (val % 2 == 0)
        {

            for (int i = 0; i < nEven_; i++)
                {
                    // Doesnt add value if equal to array
                    if (val == evens_[i])
                        {
                            numOfVal++;
                        }
                    // Adds to array only if not equal to value,
                    // and adds it in place of val
                    else
                        {
                            evens_[i - numOfVal] = evens_[i];
                        }
                }

            // Decreasing size variable
            nEven_ -= numOfVal;

            // If val is not in array, returns 0(saves time)
            if (numOfVal == 0)
                {
                    return 0;
                }

            // Resizing the array if it needs to be resized

            /*
                Resizing here in order to avoid having too many spaces allocated
                for small array
            */
            /*
                Updating at the end since I am removing an unkown amount of
               elements. I knew how many I was adding in insert (one) so I could
               adjust, but here I cannot.
            */

            /*
                As discussed in office hours, I am resizing array based on
               number of elements and CAP. For example, if I go from 11 to 8
                elements, I decrease the cap from 15 to 10 in this logic.
                I don't decrease it based on if the size is a multiple of 5
                or not.
            */

            if (((nEven_ + numOfVal) / CAP) > (nEven_ / CAP))
                {
                    temp = new int[(((nEven_ / CAP) + 1) * CAP)];

                    for (int i = 0; i < nEven_; i++)
                        {
                            temp[i] = evens_[i];
                        }

                    delete[] evens_;
                    evens_ = temp;
                }
        }

    // Exact same logic as above, except for odd
    else
        {
            for (int i = 0; i < nOdd_; i++)
                {
                    if (val == odds_[i])
                        {
                            numOfVal++;
                        }
                    else
                        {
                            odds_[i - numOfVal] = odds_[i];
                        }
                }

            nOdd_ -= numOfVal;

            if (numOfVal == 0)
                {
                    return 0;
                }

            if (((nOdd_ + numOfVal) / CAP) > (nOdd_ / CAP))
                {
                    temp = new int[(((nOdd_ / CAP) + 1) * CAP)];

                    for (int i = 0; i < nOdd_; i++)
                        {
                            temp[i] = odds_[i];
                        }

                    delete[] odds_;
                    odds_ = temp;
                    temp = nullptr;
                }
        }

    return numOfVal;
}

// FROM HW 5
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
bool Parity::odd() const
{

    if (nOdd_ % 2 == 0)
        {
            return false;
        }
    return true;
}
