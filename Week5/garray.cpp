// Implementation of GArray, a class for (inefficient) growable dynamic arrays 
// Sara Krehbiel, 10/21/24-10/25/24

#include "garray.h"

// pre: data_ points to a filled dynamic array with size_ elements
// post: size_ is incremented and data_ points to a bigger array 
void GArray::insert(int val) {
  // store a newly allocated array of size size_+1 in a temp pointer
  // copy contents from data_ to temp array, add val to the last entry
  // delete old data_
  // reassign data_ to the temp pointer
  // increment size_
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
