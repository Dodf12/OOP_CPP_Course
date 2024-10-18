#include <iostream>
using namespace std;

class Fraction
{
	private:
		int n;
		int d;

	public:
			Fraction() : n(0), d(1) {}
			Fraction(int n, int d) : n(n), d(d) { }

			string toStr() const;

			int getN() const { return n;}
			int getD() const { return d;}
};

Fraction operator -(const Fraction& lhs, const Fraction& rhs)
{
	Fraction sum(lhs.n*rhs.d-lhs.d*rhs.n, lhs.d*rhs.d);
	return sum;
}

Fraction Fraction::operator +(const Fraction& rhs) const
{
	Fraction sum(n*rhs.d+d*rhs.n,d*rhs.d);
}

int Fraction::operator [](int index) const
{
	if (index ==0) return n;
	if (index==1) return d;
}

ostream& operator <<(ostream% o, Fraction f)
{
	o << f.getN() << "/" << f.getD();
	return o;
};

int main()
{
	Fraction f1(2,3);
	Fraction f2(1,4);
	Fraction f3 = f1 + f2;
	Fraction f4 = f1-f2;
	cout << f1;
	// cout << fl << "+" << f2 << "=" << f3 << endl
	// cout << fl << "+" << f2 << "=" << f3 << endl;
	return 0;
}