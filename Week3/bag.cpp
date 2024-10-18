#include "bag.h"
//Need to have pre conditions and post conditions

Bag::Bag(int a[], size_t n) 
{
	for(size_t i =0; i<n; i++)
	{
		insert(a[i]);
	}
}



size_t Bag::count(int val) const 
{
	size_t c = 0;
	for (size_t i=0; i<size_; i++)
	{
		if (data_[i] == val) c++;
	}
	return c;

}


bool Bag::erase_one(int userNum) {
    bool found = false;

    for (size_t i = 0; i < size_; ++i) {
        if (!found && data_[i] == userNum) {
            found = true;
            size_--;
        }
        if (found) {
            data_[i] = data_[i + 1];
        }
    }

    return found;
}

void Bag::operator +=(const Bag& rhs)
{
	for (int i = 0; i < CAPACITY; i++)
	{
		data_[i]+= rhs.data_[i];
	}
}

Bag operator + (const Bag& rhs, const Bag& lhs)
{
	Bag sum = lhs;
	sum += rhs;
	return sum;
}


ostream& operator <<(ostream& o, const Bag& b) 

{

	for (size_t i=0; i< b.size();i++)
	{
		o << b[i] << " ";
	}

	return o;
}