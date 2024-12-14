#include <iostream>
using namespace std;

int helper(int& m)
{
	int *p = new int[3];
	for (int i = 0; i < 3; i++)
	{
		*(p+i) = m - i;
	}
	m = p[2];
	cout << "m + 1: " << m + 1 << endl;
	return m + 1;
}

int main()
{
	int n = 4;
	int *p = &n;
	*p = 2 * n;
	cout << "*p " << *p << endl;
	int v = helper(n);
	cout << "v: " << v << endl;
	cout << "*p " << *p << endl;
	cout << (v + *p) << endl;
}