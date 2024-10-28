#include <iostream>

using namespace std;

int main()
{
	int n  = 53;
	int *p1, *p2;

	p1 = &n;
	p2 = new int(42);

	*p1 = 88;

	cout << n << " " << *p1 << " " << *p2 << endl;
	p1 = p2;

	p2 = new int(90);
	
	delete p1;

	p1 = p2;

	cout << n << " " << *p1 <<" " << *p2 << endl;

	return 0;
}