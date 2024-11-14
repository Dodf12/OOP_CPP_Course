//Name: Abhinav Pala
//File and File Location: bag.h and in SCU Courswork folder for CSCI 60 class
//Date: 11-13-24
//No Collaborators
//File DescrptionHeader+implementation file for the new Bag class 

/* ALL CODE FROM HERE UNTIL LINE 132 IS GIVEN TO ME.
NO EDITS HAVE BEEN MADE TO THHIS SECTION
*/
#ifndef BAG_H
#define BAG_H

#include <iostream> 
using std::size_t;
using std::ostream;
using std::cout; 


template <typename T>
class Bag {
public:
  // CONSTRUCTORS AND DYNAMIC MEMORY MANAGEMENT
  Bag() : data_(nullptr), size_(0), cap_(0) {} 
  Bag(const Bag<T>& other); 
  ~Bag(); 
  Bag<T>& operator =(const Bag<T>& rhs); 

  // CONSTANT ACCESSOR MEMBER FUNCTIONS
  size_t size() const { return size_; }
  size_t cap() const { return cap_; }
  T operator [](size_t i) const { return data_[i]; }
  size_t count(T val) const; 
  
  // MUTATOR MEMBER FUNCTIONS
  void insert(T val); 
  bool erase_one(T val); 
  size_t erase(T val); 
  size_t erase_fast(T val); 
  void operator +=(const Bag<T>& rhs); 

private:
  T *data_; // the address associated with a dynamic array
  size_t size_; // how much memory is currently used (#elements in bag)
  size_t cap_; // how much memory is currently allocated (#entries in array)
  // INVARIANTS: data_[0],...,data_[size_-1] always contain the elements,
  //             cap_*.25 < size_ <= cap_, or size_=cap_=0
};

// IMPLEMENTATION 

// pre: a well-formed bag
// post: a well-formed bag with one extra T val in the last spot 
template <typename T>
void Bag<T>::insert(T val) {
  if (size_ == cap_) {
    // create a new space for a new double-capacity array
    if (cap_==0) cap_ = 1;
    else cap_ *= 2;
    T *temp = new T[cap_];
    // deep copy contents from the old array into the new one
    for (size_t i=0; i<size_; i++) {
      temp[i] = data_[i]; // requires meaningful assignment overload for type T
    }
    // delete [] data_ to avoid orphaning, reassign data_ to point to new array
    delete [] data_;
    data_ = temp;
  }
  // insert val into the next available spot in data_ and increment size_
  data_[size_++] = val;
}

// pre: out is an ostream, b is a well-formed bag
// post: out has the contents of b inserted, b is unchanged
template <typename T>
ostream& operator <<(ostream& out, const Bag<T>& b) {
  size_t n = b.size();
  for (size_t i=0; i<n; i++) {
    out << b[i] << " ";
  }
  return out;
}

// pre: other is a well-formed bag
// post: *this is a well-formed deep copy of other, which is unchanged
template <typename T>
Bag<T>::Bag(const Bag<T>& other) : size_(other.size_), cap_(other.cap_), data_(nullptr) {
  if (size_ == 0) return; // the edge case that the other bag is empty
  data_ = new T[cap_]; 
  for (size_t i=0; i<size_; i++) { 
    data_[i] = other.data_[i];
  }
}

// pre: *this and rhs are well-formed bags
// post: *this is a deep-copy of other (unchanged), and old memory is released
template <typename T>
Bag<T>& Bag<T>::operator =(const Bag<T>& rhs) {
  if (&rhs == this) return *this;
  if (cap_ != rhs.cap_) { // only need new space if my cap is changing
    cap_ = rhs.cap_; 
    delete [] data_;
    if (rhs.size_ == 0) data_ = nullptr;
    else data_ = new T[cap_];
  }
  size_ = rhs.size_;
  for (size_t i=0; i<size_; i++) { // whether i've allocated new space or not
    data_[i] = rhs.data_[i]; // deep copy rhs contents
  }
  return *this;
}

// pre: *this is a well-formed bag
// post: old memory is released and *this is a well-formed empty bag
template <typename T>
Bag<T>::~Bag() {
  delete [] data_; 
  data_ = nullptr;
  size_ = cap_ = 0;
}

// pre: *this is a well-formed bag
// post: if val is in *this, its first occurrence is removed with true returned; 
//       otherwise false is returned with *this unchanged
template <typename T>
bool Bag<T>::erase_one(T val) {
  bool found = false;
  for (size_t i=0; i<size_; i++) {
    if (!found && data_[i]==val) {
      found = true;
      size_--;
    }
    if (found) data_[i] = data_[i+1];
  }

// MY CODE STARTS HERE

// Immedietly returns if valu
if (found == false)
    {
        return found;
    }
// Resizing array using given stat
if (size_ <= 0.25 * cap_ && cap_ > 1)
    {
        // Resizing cap
        int newCap = cap_ / 2;

        // Classic resizing array
        T *newArr = new T[newCap];
        for (int i = 0; i < size_; i++)
            {
                newArr[i] = data_[i];
            }
        delete[] data_;
        data_ = newArr;

        cap_ = newCap;
    }

return found;
}

// Erase function
template <typename T>
size_t Bag<T>::erase(T val)
{
    // Tracks number of elements removed
    int count = 0;

    // Calls erase_one until val no longer found
    bool erased = erase_one (val);
    while (erased)
        {
            erased = erase_one (val);
            count++;
        }

    return count;
}

// Erase Fast Function
template <typename T>
size_t Bag<T>::erase_fast(T val)
{
    int numRemoved = 0;
    /*overrides current array with values
    that are not equal to value*/
    for (int i = 0; i < size_; i++)
        {
            // Doesnt add value if equal to array
            if (val == data_[i])
                {
                    numRemoved++;
                }
            // Adds to array only if not equal to value,
            // and adds it in place of val
            else
                {
                    data_[i - numRemoved] = data_[i];
                }
        }

    // Decreases size based on number removed
    size_ -= numRemoved;

    // If no elements removed, immediatly quits
    if (numRemoved == 0)
        {
            return numRemoved;
        }

    // Resizes array if needed
    if (size_ <= 0.25 * cap_ && cap_ > 1)
        {
            // Decreases cap if necessary
            int newCap = cap_ / 2;

            // Classiv array  resizing
            T *temp = new T[newCap];

            for (int i = 0; i < size_; i++)
                {
                    temp[i] = data_[i];
                }

            delete[] data_;
            data_ = temp;

            cap_ = newCap;
        }

    return numRemoved;
}

// Overload operator += for Bag
template <typename T>
void Bag<T>::operator+=(const Bag<T> &rhs)
{
    int newCap = 0;
    // New size of the array after adding in rhs
    int newSize = size_ + rhs.size_;

    // Creates new dynamic array if size exceeds cap
    if (newSize > cap_)
        {
            // Classic resizing array code
            int newCap = cap_ * 2;
            T *newArr = new T[newCap];

            for (int i = 0; i < size_; i++)
                {
                    newArr[i] = data_[i];
                }

            delete[] data_;
            data_ = newArr;

            // Updating capacity.
            cap_ = newCap;
        }

    // Adds rhs elements to the lhs array at the end of lhs array
    for (int i = 0; i < rhs.size_; i++)
        {
            data_[i + size_] = rhs.data_[i];
        }
    size_ = newSize;
}
#endif
