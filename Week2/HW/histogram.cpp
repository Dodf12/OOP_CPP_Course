// Implementation starter file for CSCI 60 Homework 2; due due Wednesday 10/9/24
// Comment functions below; list any collaborators and write your name here
#include "histogram.h"
#include <fstream>
#include <iostream>

/*
Abhinav Pala 10-8-24
Main.cpp is testing to make sure the historgram file
is working correctly. Created objects and am testing
function here.
The min, max, mode, mean, median and variance where 100% my own
I had to refer to textbook to figure out how to use the operator[] overloading
I also referred to geeksforgeeks for this

Last problem, me and my friend Kevin worked on it together.
It kept printing only one star per line, but friend
suggested the for loop to only go as much as frequency.

All code was 100% written by me, and only outside help was for
minor debugging of last function 

The Autograder gave me trouble,
so I asked my friend tate and we tried to figure it out,
but we werent able to so I referred to DR. Krehbiel 
during office hours
*/


//!!!!!!!!!!
//Ask if comments/documentation is good enough
//figure out autograder issues
//Ask if must account for empty array

//!!!


/*
Single arg constructor intializes array with 0s,
Reads in integers from file name and stores in 
counts array
*/

Histogram::Histogram(string filename) 
{
// TODO: implement this stub function here!

	for (int i = 0; i < MAX + 1; i++)
	{
		counts[i]=0;
	}

	ifstream in(filename); // open a file called data.txt as an input stream in
	int val; // var to store one int at a time
	while (in >> val) 
	{ // read int tokens from stream 1-by-1 until end of file
		counts[val] += 1; // add value of each token to total
	}
	in.close(); // close file
}
/* TODO: implement the functions declared in histogram.h here */


//Making 0 arg constructor to intialize array with all 0s
Histogram::Histogram()
{
	for (int i = 0;i < MAX + 1;i++)
	{
		counts[i] = 0;
	}
}

/*
Outputs the number of elements in the array/
file you pass to the function
*/

size_t Histogram::size() const
{
	size_t sum = 0;

	// if (sizeof(counts) == 0)
	// {
	// 	return 0;
	// }

	for (int i = 0; i < MAX + 1; i++)
	{
		sum += counts[i];
		//cout << counts[i] << endl;
	}

	return sum;
}

/*
Returns the largest value in the counts array
*/
size_t Histogram::max() const
{
	//Makes sure teo check if array is blank
	if (size() == 0)
	{
		return MAX+1;
	}
	size_t largest = 0;

	//Uses variable largest as a holder
	/*
	Uses variable largest as a holder
	At each iteration, it is on the 
	current largest value, and tests
	it out
	 */
	for (int i = 0; i <MAX + 1; i++)
	{
		//Makes sures the value isn't 0 so it ignores
		if (counts[i] != 0)
		{
			if (i > largest)
			{
				largest = i;
			}

		}
	}

	return largest;
}

/*
Returns the smallest value in the counts array
*/
size_t Histogram::min() const
{
	if (size() == 0)
	{
		return MAX+1;
	}
	size_t min = 0;

	//min will will always be the first value
	for (int i = 0; i <MAX + 1; i++)
	{
		if (counts[i] != 0)
		{
			min = i;
			return min;
		}
	}

	return min;
}

/*
Returns the mode of the counts array
*/
size_t Histogram::mode() const
{
	//Does same thing as max, except checks for frequency 
	//instead of actually value

	// if (sizeof(counts) == 0)
	// {
	// 	return 0;
	// }

	size_t mode = 0;
	size_t temp = 0;
	for (int i = 0; i < MAX + 1; i++)
	{
		if (counts[i] != 0)
		{
			if (temp < counts[i])
			{
				temp = counts[i];
				mode = i;
			}
		}
	}

	return mode;

}

/*
Returns the median of the counts array
*/
size_t Histogram::median() const
{

	/*First must find the size of teh array
	and find the halfway point
	*/

	// if (sizeof(counts) == 0)
	// {
	// 	return 0;
	// }
	size_t median = 0;
	//Finds the size of the array
	size_t size = 0;

	for (int i = 0; i < MAX + 1; i++)
	{
		size += counts[i];
	}

	size_t midway = size / 2;

	size_t sum = 0; 

	/*Adds all the numbers in order 
	to make sure it doesnt go past the midway point*/

	//For loop keeps going until the values have reached
	//past midway

	for (int index = 0 ; index < MAX + 1; index++)
	{
		sum+= counts[index];

		if (sum > midway)
		{
			median = index;
			return median;
		}
	}

	median = -1;
	return median;
}

/*
Returns the mean of the counts array
*/
double Histogram::mean() const
{
	//First must calculate size of array so we know what to divide by
	// if (sizeof(counts) == 0)
	// {
	// 	return 0;
	// }
	double size_ = 0.0;

	// for (int i = 0; i < MAX + 1; i++)
	// {
	// 	size += counts[i];
	// }
	size_ = size();

	//actually adding up the mean value
	//Making sure to account for the frequencies by using for loop
	double mean = 0.0;
	
	for (int j = 0; j < MAX + 1; j++)
	{

		mean = mean + (counts[j] * j);
	}
	return mean / size_;
}

/*
Returns the variance of the counts array
*/
double Histogram::variance() const
{

	//Finding the Mean in order to use in future calculations
 	// if (sizeof(counts) == 0)
	// {
	// 	return 0;
	// }
	int size_ = 0;
	size_ = size();

	// for (int i = 0; i < MAX + 1; i++)
	// {
	// 	size += counts[i];
	// 	//cout << counts[i] << endl;
	// }
	double mean_ = 0.0;
	
	// for (int j = 0; j < MAX + 1; j++)
	// {

	// 	mean = mean + (counts[j] * j);
	// }
	// mean = mean / size;
	mean_ = mean();

	//The code above is for getting the mean

	//Actually calculating the variance according to formula
	double variance = 0.0;

	for (int k = 0; k < MAX + 1; k++)
	{
		if (counts[k] != 0)
		{
			variance += (counts[k] * ( (k - mean_) * (k - mean_) ) );
		}
	}

	return variance / size_;
}


//Adds and updates an existing objects values to another objects
 void Histogram::operator +=(const Histogram& rhs)
 {

 	for (int i = 0; i < MAX + 1; i++)
 	{
 		counts[i] = counts[i] + rhs.counts[i];
 	}

 }

//self explanatory

 size_t Histogram::operator[](size_t val) const
 {
 	return counts[val];
 }

/*Create the array by having two for loops

*/
ostream& operator <<(ostream& out, const Histogram& h)
{
	int min = h.min();
	for (int i = min; i <= (h.max()); i++)
	{
		//Must have here to avoid printing a million times
		out << i << ": " ;
		for (int j = 0; j < h[i]; j++)
		{
				out << '*';
		}
		//Must end line in order to have seperation
		out << endl;
	}
	return out;
}

