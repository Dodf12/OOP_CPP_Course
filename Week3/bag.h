#ifndef BAG_H
#define BAG_H

#include <cstdlib>
using std::size_t;
#include <iostream>
using std::ostream;

class Bag
{
	public:
		static const size_t CAPACITY = 1000;

		Bag() : size_(0) { }

		Bag(int a[], size_t) ;
		
		//accessors
		size_t size() const { return size_;}
		size_t operator [](size_t index) const { return data_[index]; }
		size_t count(int val) const; //size_t is returned because count ispositive
		bool erase_one(int val);
		void operator +=(const Bag& rhs);



		 //mmutator
		 void insert(int val) 
		 {
		 	if (size_<CAPACITY) 
	 		{ 
	 			data_[size_] = val;
		 		data_[size_] = val;
		 		size_++; 
		 	}
		 }
	 private:
	 	int data_[CAPACITY];
 		size_t size_;
};

ostream& operator <<(ostream& o, const Bag& b);
Bag operator +(const Bag& lhs, const Bag& rhs);






#endif