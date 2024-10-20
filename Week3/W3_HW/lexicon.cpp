//Name: Abhinav Pala
//Date: 10-17-24

//Helpers
/*
Consulting my friend Kevin on the and function. He suggest I 
try using two nestedfor loops instead of two seperate loops. 
This fixed my code.

My == operator was bugging me, so I asked another friend named 
Shayan, and he suggestI change lin 183 from if 
(lhs.contains(rhs[i]) == false) to !lhs.contains(rhs[i]),
and see if it worked. It did end up fixing my code.
*/

//File Location and Confirmation of Using Terminal to ensure 
//code is running
/*
This assignment in my SCU C++ and OOP folder. I ran it in 
the terminal and it runs without compiler errors
*/


#include "lexicon.h"


/*
Constructor accepts words from a file, and makes sure each word
*/
Lexicon::Lexicon(string filename) : size_(0) 
{
  ifstream in(filename);
  string word;
  while (in >> word && size_<CAPACITY) {

    //My code Starts here +++++++++++++++++++++++++++++

    //Checks if word is in array already
    bool isInList = false;
    
    //Loops through all elements in array to see if word is already in it
    for (int i = 0; i < size_; i++)
    {
      if (data_[i] == word) { isInList = true; }
    }
    
    if (isInList == false) { data_[size_++] = word; }
  }
  in.close();
}


/*Functions checks if the Lexicon object contains a word in the list.
Returns false if the word is in the array, and true if it IS.
*/
bool Lexicon::contains(string word) const
{
    bool isInList = false;
    
    //Loops through all elements in array to see if word is already in it
    for (int i = 0; i < size(); i++)
    {
      if (data_[i] == word) { isInList = true; }
    }

    return isInList;
}


/*
This functions is essentially removes the element from an array.
Looks through the array 
*/
bool Lexicon::remove(string word)
{
  //Checks if word is in array in order to save time and circumvent bugs
  if (contains(word) == false) { return false; }

  for (int i = 0; i <size_; i++)
  {
    if (data_[i] == word)
    {
      size_=size_ -1;
        for (int j = i; j < size_; j++) { data_[j] = data_[j+1]; }
        break;
    }
  }

  return true;
}


/*
  Checks to see if word is in the array, 
  or the size is greater than or equal to capactiy first to prevent
  errors. 
  Checks if word is already in the array.
  Adds word at the end of the array if there is space or word
  is not previously in the array
*/
bool Lexicon::insert(string word)
{
    bool isInList = false;
    
    //Loops through all elements in array to see if word is already in it
    if ( (contains(word)) || (size_ >= CAPACITY) ) { return false; }
    data_[size_++] = word;
    return true;
}


/*
  Takes two objects, and finds the union(combines) the arrays
  of the object's. Utilizes insert operator, which doesnt
  allow repeating words
*/
Lexicon Lexicon::operator |(const Lexicon& rhs) const
{
  Lexicon union_obj;

  //Inserts all the elements from the calling objec
  for (int i = 0; i < size_; i++)
  {
    //Checking to see output is greater than Capacity
    if (i >= CAPACITY){ return union_obj; }
    union_obj.insert(data_[i]);
  }

  //INserts all element from calling object
  for (int j = 0; j < rhs.size_ ; j++)
  {
    //Checking to see output is greater than Capacity
    if (j>= CAPACITY) { return union_obj; }
    union_obj.insert(rhs.data_[j]);
  }

  return union_obj;

}


/*
  Takes two objects, and finds the intersection(commong elements) 
  the arrays of the object's. Utilizes insert operator, which doesnt
  allow repeating words
*/
Lexicon Lexicon::operator &(const Lexicon& rhs) const
{
  Lexicon intersection;

  for (int i = 0; i < size_; i++)
  {
    //Checking to see output is greater than Capacity
    if (i >= CAPACITY){ return intersection; }
    for (int j = 0; j < rhs.size_; j++)
    {
      //Checking to see output is greater than Capacity
      if (i >= CAPACITY){ return intersection; }
      else if (data_[i] == rhs.data_[j]) { intersection.insert(data_[i]); }
    }
  }

  return intersection;
}


/*
  Takes two objects, and finds the XOR(an element that is in one
  array, but not in the other) of the arrays of the object's. 
  Utilizes insert operator, which doesnt allow repeating words
*/

Lexicon Lexicon::operator ^(const Lexicon& rhs) const
{
  Lexicon XOR;

  Lexicon intersection;
  for (int i = 0; i < size_; i++)
  {

    if (i >= CAPACITY){ return XOR; }     //Checking to see output is greater than Capacity
    for (int j = 0; j < rhs.size_; j++)
    {
      if (i >= CAPACITY){ return XOR; }     //Checking to see output is greater than Capacity
      else if (data_[i] == rhs.data_[j]) { intersection.insert(data_[i]); }
    }
  }


  //Checks to see if an element is in both in the two for loops below

  for (int i = 0; i < size_; i++)
  {
    if (i >= CAPACITY){ return XOR; }
    else if (data_[i] != intersection[i]) { XOR.insert(data_[i]); }
  }

  for (int j = 0; j < size_; j++)
  {
    if (j >= CAPACITY){ return XOR; }
    else if (rhs.data_[j] != intersection[j]) { XOR.insert(data_[j]); }
  }

  return XOR;
}


/*
Checks if all elements in one object's array is equal to all 
elements in another object's array
*/
bool operator ==(const Lexicon& lhs, const Lexicon& rhs)
{
  if ( lhs.size() == rhs.size() )
  {
    for (int i =0; i < rhs.size(); i++)
    {
      if (!lhs.contains(rhs[i])) { return false; }
    }

    return true;
  }
  else { return false; }
}

/*
  Checks if two different object's array's are not equal.
  We just check if operator == returns false, and return
  true for it
*/

bool operator !=(const Lexicon& lhs, const Lexicon& rhs)
{
  if (rhs==lhs) { return false; }
  return true;
}

/*
  Checks if each element in the left side is equal 
  to every element in the right side.
  Returns true if above is true
  and false if not

  Ex 1: LHS = {1,2} and RHS = {1,2,}. Returns true
  Ex 2: LHS = {1,2} and RHS = {1}. Returns false
*/


bool operator <=(const Lexicon& lhs, const Lexicon& rhs)
{
  if ((lhs & rhs).size() == lhs.size()) { return true; }
  return false;
}

/*
  Checks if each element in the left side is equal 
  to every element in the right side.
  An additional thing it does it to make sure 
  the left is a subset of the right, but
  not EXACTLy equal to right
  Returns true if above is true
  and false if not

  Ex 1: LHS = {1,2} and RHS = {1,2,3}. Returns true
  Ex 2: LHS = {1,2} and RHS = {1,2}. Returns false

*/


bool operator <(const Lexicon& lhs, const Lexicon& rhs)
{
  if ( ((lhs & rhs).size() == lhs.size()) && ( rhs.size() > lhs.size() ) ) { return true; }
  return false;
}

/*
  This function is similar to <=, but instead you are 
  checking if every element of the rhs is equal to lhs
  
  Refer to comment above operator <=
*/


bool operator >=(const Lexicon& lhs, const Lexicon& rhs)
{
  if ((lhs & rhs).size() == rhs.size()) { return true; }
  return false;
}

/*
  Same thing as <, but checks if every element in right
  side is equal to left side.

  Refer to comment above operator <

*/


bool operator >(const Lexicon& lhs, const Lexicon& rhs)
{
  if ( ((lhs & rhs).size() == lhs.size()) && ( rhs.size() < lhs.size() ) ) { return true; }
  return false;
}



//++++++++++++END OF MY CODE ++++++++++++++++++++++++++++++


// Inserts contents of lex in out in order, separated by spaces
ostream& operator <<(ostream& out, const Lexicon & lex) {
  size_t n = lex.size();
  for (size_t i=0; i<n; i++) 
  {
    out << lex[i] << " ";
  }
  return out;
}
