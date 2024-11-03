
// Implementation starter file for CSCI 60 Homework 5; due Wednesday 10/30/24
// List any collaborators and write your name here

// Name: Abhinav Pala
// File: parity.cpp
// File Location: SCU coursework folder in CSCI 60 Folder
// Data 10-27-24
// Collaborators:
/*Asked my friend Kevin since I was stuck on insert function.
It would print
E: 0 2 6 8 10
O: 0 3 5 -1 7 0.

He suggest I switch linse 98 and 99, and it worked when I did that.
It was a very minor fix, that I wasn't able to catch since teh debug
statements matche dup with what was supposed to be the correct output
*/
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
                    insert(a[i]);
                }
        }
}

//Copy COnstructor
Parity::Parity(const Parity& rhs)
{
    nEven_ = rhs.nEven_;
    nOdd_ = rhs.nOdd_;


    evens_ = new int[nEven_];
    odds_ = new int[nOdd_];

    for (int i = 0; i < nEven_; i++) { evens_[i] = rhs.evens_[i]; }
    for (int j = 0; j < nOdd_; j++) { odds_[j] = rhs.odds_[j]; }
}

//Destructor
Parity::~Parity()
 {
    delete evens_;
    delete odds_;

    evens_ = nullptr;
    odds_ = nullptr;

    nEven_ = 0;
    nOdd_ = 0;
 }

Parity& Parity::operator =(const Parity& rhs)
{
    cout << "Hi1" << endl;
    nEven_ = rhs.nEven_;
    nOdd_ = rhs.nOdd_;

    cout << "Hi2" << endl;
    delete evens_;
    delete odds_;


    cout << "Hi3" << endl;
    evens_ = new int[nEven_];
    odds_ = new int[nOdd_];

    cout << "Hi4" << endl;
    for (int i = 0; i < nEven_; i++) { evens_[i] = rhs.evens_[i]; }
    for (int j = 0; j < nOdd_; j++) { odds_[j] = rhs.odds_[j]; }
    return *this;
}

int Parity::min () const
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

int Parity::max () const
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

ostream &operator<< (ostream &out, const Parity &p)
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
    int tempIndex = 0;
    if ( val % 2 == 0)
        {
            if ( nEven_ % CAP == 0 )
                {
                    
                }

            int i = 0;
            int *tempEvenArray = new int[nEven_++];
            bool ifStatementUsed = false;

            cout << "total even numbers" << nEven_ << endl;

            while (i < nEven_)
            {
                if (evens_[i] > val && ifStatementUsed == false) 
                    { 
                        tempEvenArray[i] = val;
                        //cout << "New element " << tempEvenArray[i] << endl;
                        ifStatementUsed = true;
                    }
                else if(evens_[i] > val && ifStatementUsed )
                    {
                       tempEvenArray[i] =  evens_[i];
                    }
                else
                    {
                        cout << evens_[i] << endl;
                        tempEvenArray[i] = evens_[i];
                        cout << "Wew element: " << tempEvenArray[i] << endl;
                    }
                i++;
            }

            delete[] evens_;
            evens_ = tempEvenArray;
        }
    // else
    //     {

    //     }

    //Following code executes if val is even
    // if (val % 2 == 0)
    //     {
    //         // Goes into if, if there are spots left22
    //         if (nEven_ % CAP == 0)
    //             {
    //                 /*
    //                 I know I could directly put the
    //                 nEven_ + CAP in the array
    //                 declaration, but I wanted to
    //                 make it more readable
    //                 */

    //                 int newEvenSize = nEven_ + CAP;
    //                 int *temp = new int[newEvenSize];

    //                 for (int i = 0; i < nEven_; i++)
    //                     {
    //                         temp[i] = evens_[i];
    //                     }

    //                 delete[] evens_;
    //                 evens_ = temp;

    //                 evens_[nEven_] = val;
    //                 nEven_++;
    //             }
    //         else
    //             {
    //                 evens_[nEven_] = val;
    //                 nEven_++;
    //             }
    //     }

    // else
    //     {
    //         if (nOdd_ % CAP == 0)
    //             {
    //                 int newOddSize = nOdd_ + CAP;

    //                 int *temp2 = new int[newOddSize];

    //                 for (int i = 0; i < nOdd_; i++)
    //                     {
    //                         temp2[i] = odds_[i];
    //                     }
    //                 delete[] odds_;
    //                 odds_ = temp2;

    //                 odds_[nOdd_] = val;
    //                 nOdd_++;
    //             }
    //         else
    //             {
    //                 odds_[nOdd_] = val;
    //                 nOdd_++;
    //             }
    //     }
}

size_t remove(int val)
    {
        return 0;
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
