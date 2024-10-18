//Name: Abhinav Pala
//Date: 10-17-24
//Helpers
/*
Consulting my friend Kevin on the and function. He suggest I try using two nested
for loops instead of two seperate loops. This fixed my code.

My == operator was bugging me, so I asked another friend named Shayan, and he suggest
I change lin 183 from if (lhs.contains(rhs[i]) == false) to !lhs.contains(rhs[i]),
and see if it worked. It did end up fixing my code.
*/
#include "lexicon.h"


//EDIT TEH STYLEEEEE

Lexicon::Lexicon(string filename) : size_(0) 
{
  ifstream in(filename);
  string word;
  while (in >> word && size_<CAPACITY) {

    //My code Starts here

    //Checks if word is in array already
    bool isInList = false;
    
    //Loops through all elements in array to see if word is already in it
    for (int i = 0; i < size_; i++)
    {
      if (data_[i] == word)
      {
        isInList = true;
      }
    }
    
    if (isInList == false) { data_[size_++] = word; }
  }
  in.close();

}


bool Lexicon::contains(string word) const
{
    bool isInList = false;
    
    //Loops through all elements in array to see if word is already in it
    for (int i = 0; i < size(); i++)
    {
      if (data_[i] == word)
      {
        isInList = true;
      }
    }

    return isInList;

}

bool Lexicon::remove(string word)
{

  if (contains(word) == false) { return false; }


  string temp = " ";
  for (int i = 0; i <size_; i++)
  {
    if (data_[i] == word)
    {
      size_=size_ -1;
        for (int j = i; j < size_; j++)
        {
          data_[j] = data_[j+1];
        }
        break;
    }
  }

  return true;
}

bool Lexicon::insert(string word)
{
    bool isInList = false;
    
    //Loops through all elements in array to see if word is already in it
    if ( (contains(word)) || (size_ >= CAPACITY) )
    {
      return false;
    }
    data_[size_++] = word;
    return true;
}


Lexicon Lexicon::operator |(const Lexicon& rhs) const
{
  Lexicon union_obj;

  /*First ads the lhs objects elements into teh array.
  _data[i] is the LHS sides' array
  */

  //Inserts all the elements from the calling objec
  for (int i = 0; i < size_; i++)
  {
    union_obj.insert(data_[i]);
  }

  //INserts all element from calling object
  for (int j = 0; j < rhs.size_ ; j++)
  {
    union_obj.insert(rhs.data_[j]);
  }

  return union_obj;

}

Lexicon Lexicon::operator &(const Lexicon& rhs) const
{
  Lexicon intersection;

  for (int i = 0; i < size_; i++)
  {
    for (int j = 0; j < rhs.size_; j++)
    {
      if (intersection.contains(data_[i]) || intersection.contains(data_[i]) ) { }
      if (data_[i] == rhs.data_[j]) { intersection.insert(data_[i]); }
    }
  }

  return intersection;
}

Lexicon Lexicon::operator ^(const Lexicon& rhs) const
{
  Lexicon XOR;

  //Getting the intersection of lhs and rhs and storing in intersection
  Lexicon intersection;

  for (int i = 0; i < size_; i++)
  {
    for (int j = 0; j < rhs.size_; j++)
    {
      if (intersection.contains(data_[i]) || intersection.contains(data_[i]) ) { }
      if (data_[i] == rhs.data_[j]) { intersection.insert(data_[i]); }
    }
  }


  //
  for (int i = 0; i < size_; i++)
  {
    if (this->data_[i] == intersection[i]) { }
    else 
    { 
      XOR.insert(data_[i]); 
    }
  }

  for (int j = 0; j < size_; j++)
  {
    if (rhs.data_[j] == intersection[j]) { }
    else { XOR.insert(data_[j]); }
  }




  return XOR;
}


bool operator ==(const Lexicon& lhs, const Lexicon& rhs)
{
  if ( lhs.size() == rhs.size() )
  {
    for (int i =0; i < rhs.size(); i++)
    {
      if (!lhs.contains(rhs[i]))
      {
        return false;
      }
    }

    return true;
  }
  else { return false; }

}

bool operator !=(const Lexicon& lhs, const Lexicon& rhs)
{
  if (rhs==lhs)
  {
    return false;
  }
  return true;
}

bool operator <=(const Lexicon& lhs, const Lexicon& rhs)
{
  if ((lhs & rhs).size() == lhs.size()) 
    { 
      return true; 
    }
  return false;
}

bool operator <(const Lexicon& lhs, const Lexicon& rhs)
{
  if ( ((lhs & rhs).size() == lhs.size()) && ( rhs.size() > lhs.size() ) )

  {
    return true;
  }
  return false;
}

bool operator >=(const Lexicon& lhs, const Lexicon& rhs)
{
  if ((lhs & rhs).size() == rhs.size()) 
    { 
      return true; 
    }
  return false;
}

bool operator >(const Lexicon& lhs, const Lexicon& rhs)
{
  if ( ((lhs & rhs).size() == lhs.size()) && ( rhs.size() < lhs.size() ) )

  {
    return true;
  }
  return false;
}


// Inserts contents of lex in out in order, separated by spaces
ostream& operator <<(ostream& out, const Lexicon & lex) {
  size_t n = lex.size();
  for (size_t i=0; i<n; i++) {
    out << lex[i] << " ";
  }
  return out;
}
