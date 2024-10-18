#include <iostream>

using namespace std;


class Fraction
{
	public:
		Fraction() : n(0), d(1) { }
		Fraction(int n, int d) : n(n), d(d) { }

		int getN() const {return n;}
		int getD() const {return d;}
	private: 
		int n;
		int d;

};

//overload << as a non-member function
ostream& operator<<(ostream& out, const Fraction& rhs)
{
	out << rhs.getN() << "/" << rhs.getD();
	return out;
}


int main()
{
	Fraction f(3,4);
	cout << "f = " << f << endl; //output "f=3/4"
}