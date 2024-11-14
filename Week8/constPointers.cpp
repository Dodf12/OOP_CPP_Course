// Goal: Learn how const affects pointers.
// Sara Krehbiel, 11/11/24
#include <iostream>
using namespace std;

bool list_search(const node* h, const node* t, int val)
{
	node* curr = h;
	while (curr!=nullptr)
	{
		if (curr->data() == val)
		{
			return true;
		}
		curr = curr->link;
	}
	return false;
}
int main() {
	int a = 5, b = 6;
	int *pa = &a; // can reassign pa and can change the value it points to
	const int *pa = &a; // can reassign pa, can't change the value it points to
	int *const pa = &a; // can't reassign pa, can change the value it points to
	const int *const pa = &a; // can't change value or location pa points to
	cout << "a: " << a << ", b: " << b << ", *pa: " << *pa << endl;
	*pa = b+3; // const int * pa outlaws this one
	pa = &b; // int * const pa outlaws this one
	cout << "a: " << a << ", b: " << b << ", *pa: " << *pa << endl;
	return 0;
}
