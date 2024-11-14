// Interface for templatized dynamic array implementation of Bag.
// Also includes all the implementation normally in the cpp file
// to avoid platform-specific linking problems.
//
// Sara Krehbiel, modified code from Natalie Linnell and Nicholas Tran
// 11/4/24

#ifndef BAG_H
#define BAG_H

#include <iostream> 
using std::size_t;
using std::ostream;
using std::cout; // note: useful for cout debugging

// INTERFACE

template <typename T>
class Bag {
public:
  // CONSTRUCTORS AND DYNAMIC MEMORY MANAGEMENT
  // NOTE: DON'T templatize constructor/destructor names when declaring/defining
  Bag() : data_(nullptr), size_(0), cap_(0) {} 
  //Bag(const Bag<T>& other); // NOTE: DO templatize any Bag object, incl params
  //~Bag(); // COMPILE ERROR: can't use Bag with ~ declared but not implemented
  //Bag<T>& operator =(const Bag<T>& rhs); // NOTE: also templatize return types

  // CONSTANT ACCESSOR MEMBER FUNCTIONS
  size_t size() const { return size_; }
  size_t cap() const { return cap_; }
  T operator [](size_t i) const { return data_[i]; }
  size_t count(T val) const; 
  
  // MUTATOR MEMBER FUNCTIONS
  void insert(T val); 
  bool erase_one(T val);
  size_t erase(T val); 
  size_t erase_fast(T val); // (smarter implementation of erase)
  void operator +=(const Bag<T>& rhs); 

private:
  T *data_; // the address associated with a dynamic array
  size_t size_; // how much memory is currently used (#elements in bag)
  size_t cap_; // how much memory is currently allocated (#entries in array)
  // INVARIANTS: data_[0],...,data_[size_-1] always contain the elements,
  //             cap_*.25 < size_ <= cap_, or size_=cap_=0
};

// IMPLEMENTATION (note that this has to go in bag.h)

// WEDNESDAY TODO: 
//   1/ Finish implementing insert (comments below)
//   2/ Overload <<
//   2/ Implement copy-constructor, assignment operator, and destructor
//   3/ Implement erase_one

template <typename T>
void Bag<T>::insert(T val) {
  if (size_<cap_) {
    // insert val into the next available spot in data_ and increment size_
  } else {
    // create a new space for a new larger array
    // deep copy contents from the old array into the new one
    // delete [] data_ to avoid orphaning
    // reassign data_ to point to the new array
    // insert val into the next available spot in data_ and increment size_
  }
}

// analogous functions for alternate implementations of bag-like classes

/*void GArray::insert(int val) {
  int *temp = new int[size_+1];
  for (size_t i=0; i<size_; i++) {
    temp[i] = data_[i];
  }
  delete [] data_;
  data_ = temp;
  data_[size_++] = val;
}

ostream& operator <<(ostream& out, const GArray& a) {
  size_t n = a.length();
  for (size_t i=0; i<n; i++) {
    out << a[i] << " ";
  }
  return out;
}

GArray::GArray(const GArray& other) : size_(other.size_), data_(nullptr) {
  if (size_ == 0) return;
  data_ = new int[size_]; 
  for (size_t i=0; i<size_; i++) { 
    data_[i] = other.data_[i];
  }
}

GArray& GArray::operator =(const GArray& rhs) {
  if (&rhs == this) return *this; // don't delete your own stuff!
  if (size_ != rhs.size_) { // only need new space if my size is changing
    size_ = rhs.size_; 
    delete [] data_;
    if (size_ == 0) data_ = nullptr;
    else data_ = new int[size_];
  }
  for (size_t i=0; i<size_; i++) {
    data_[i] = rhs.data_[i];
  }
  return *this;
}

GArray::~GArray() {
  delete [] data_; 
  data_ = nullptr;
  size_ = 0;
}

bool Bag::erase_one(int val) {
  bool found = false;
  for (size_t i=0; i<size_; i++) {
    if (!found && data_[i]==val) {
      found = true;
      size_--;
    }
    if (found) data_[i] = data_[i+1];
  }
  return found;
}
*/

#endif
