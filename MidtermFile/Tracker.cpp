#include <iostream>

using namespace std;

template <typename T>
class SVal
{
	public:
		SVal(const T& s) : s(s) {}
		Sval() : s(0) {}
		bool isSecret(const T& guess) const;
	private:
		T s;
}



int main()
{
	int n = 2;
	int m = 3;
	
	int *a = &n;
	int *b = &m; 

	*a = *b;
	cout << *a << " a" << *b << endl;

	// a = b;
	// cout << a << "b: " << b << endl;


}