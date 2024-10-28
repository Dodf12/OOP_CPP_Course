// Implementation of GArray, a class for (inefficient) growable dynamic arrays 
// Sara Krehbiel, 10/21/24-10/25/24

#include "garray.h"

GArray::GArray(const GArray& other)
{
  size_ = other.size_;
  data_ = other.data_;
}
// pre: data_ points to a filled dynamic array with size_ elements
// post: size_ is incremented and data_ points to a bigger array 
void GArray::insert(int val) {
  // store a newly allocated array of size size_+1 in a temp pointer
  int *temp = new int[size_+1];
  // copy contents from data_ to temp array, add val to the last entry
  for (size_t i= 0; i<size_; i++)
  {
    temp[i] = data_[i];
  }

  delete [] data_;

  data_ = temp;
  data_[size_++] = val;
  // delete old data_
  // reassign data_ to the temp pointer
  // increment size_
}

void GArray::operator =(const GArray& rhs)
{
  delete [] data_;
  data_ = new int[rhs.size_];
  for (size_t i= 0; i<size_; i++)
  {
  data_[i]=rhs.data_[i];
  }
}


// get the length of the array and insert contents item-by-item using []
ostream& operator <<(ostream& out, const GArray& a) {
  out << "(" << a.dataAddress() << ") "; // lets you see where the arrays are
  size_t n = a.length();
  for (size_t i=0; i<n; i++) {
    out << a[i] << " ";
  }
  return out;
}
