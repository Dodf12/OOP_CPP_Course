
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

int Parity::min() const
{
	int min = INT_MAX;
	for (int i = 0; i < nEven_; i++)
	{
		if (evens_[i] < min) { min = evens_[i]; }
	}

	for (int j = 0; j < nOdd_; j++)
	{
		if (odds_[j] < min) { min = odds_[j]; }
	}
	return min;

}



int Parity::max() const
{
	int max = INT_MIN;

	for (int i = 0; i < nEven_; i++)
	{
		if (evens_[i] < max) { max = evens_[i]; }
	}

	for (int j = 0; j < nOdd_; j++)
	{
		if (odds_[j] > max) { max = odds_[j]; }
	}

	return max;

	//return INT_MIN;
}



ostream &operator<<(ostream &out, const Parity &p)
{
	out << "E: ";
	for (int i = 0; i < p.nEven_; i++)
	{
		out << p.evens_[i] << " ";
	}

	out << " " << endl;

	out << "O: ";
	for (int j = 0; j < p.nOdd_; j++)
	{
		out << p.odds_[j] << " ";
	}
	out << " " << endl;
	return out;
}



// Two Argument Constructor
Parity::Parity(int *a, size_t n)
{

	Parity localObj;

	for (int i = 0; i < n; i++)
	{
		localObj.insert(a[i]);
	}

}

// Insert Stub Function
void Parity::insert(int val)
{
	if (val % 2 == 0)
	{
		// Goes into if, if there are spots left
		if (nEven_ % CAP == 0)
		{
			int newEvenSize = nEven_ + CAP;
			int *temp = new int[newEvenSize];

			for (int i = 0; i < nEven_; i++)
			{
				temp[i] = evens_[i];
			}

			delete[] evens_;
			evens_ = temp;

			evens_[nEven_] = val;
			nEven_++;
		}
		else
		{
			evens_[nEven_] = val;
			nEven_++;
		}
	}

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
bool Parity::odd() const
{
	if(nOdd_ % 2 == 0) { return false;}
	return true;
}