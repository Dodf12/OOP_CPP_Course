#include <iostream>
using namespace std;


class petList
{
	private:
		string parent; 
		double decimal;

	public:
		string breed;
		int number;

		petList() {};

		petList(double dec) {decimal = dec;}

		 petList(string breedName, int idNumber)
		 {
		 	breed = breedName;
		 	number = idNumber;
		 };

		 petList(string breedName, int idNumber, double dc)
		 {
		 	breed = breedName;
		 	number = idNumber;
		 	decimal = dc;
		 };

		 string getParent() const {return parent;}

		double getDecimal() const {return decimal;}


		// string getBreed()
		// {
		// 	return breed;
		// };

		// int getBadgeNumber()
		// {
		// 	return number;
		// }

		 /*
		if you do object a += object b, compiler knows to get
		objeact a's attributes when you just type plain atributes.
		It does not know
		
		 */
		 void operator+=(const petList &b)
		 {
		 	breed = breed + b.breed;
		 	number = number + b.number;
		 };

		 /*
			Figger out constants
		 */


};

//Operator overloading with both parameters
petList operator+(const petList &a, const petList &b)
{
	petList sum;

	sum.breed = a.breed + b.breed;

	sum.number = a.number + b.number;

	return sum;
};

petList operator*(const petList &a, const petList &b)
{
	petList sum_decimal;
	sum_decimal = petList(a.getDecimal() + b.getDecimal());
	return sum_decimal;
	
};


//OPERATOR OVERLOADING WITH ONE PARAMETER




int main()
{

	petList hardy = petList("Boxer", 520, 1.2);
	petList barney = petList("Labrador", 433, 2.4);

	//petList squish = hardy + barney;

	/*No need to pass second parameter since compiler will automatically
	*/
	hardy += barney;
	cout << hardy.breed << endl << hardy.number << endl;

	const petList &newObj = hardy * barney;
	cout << &newObj << endl;
	cout << newObj.getDecimal();
};