// Small program to learn how to declare and define a template class
// SVal is a templatized class that stores a secret value of templatized type.
// It has 0-arg and 1-arg constructors that respectively initialize the secret s
// as the provided value or the default value for the specified type. 
// A boolean accessor isSecret allows a client to guess the secret value.
// SVal must be constructed only with types with 0-arg constructors and ==.
// Sara Krehbiel, 10/30/24 

#include <iostream>
using namespace std;

// a starter class implemented for ints
template <typename T>
class SVal {
public:
  SVal(int s) : s(s) {} 
  SVal() : s(0) {} 
  bool isSecret(int guess) const; 
private:
  int s; 
};

//NEED ANGLE BRACKETS AROUND THE FUNCTION IF DECLAREDOUTSIDE THE CLASS
template <typename T> 
bool SVal<T>::isSecret(int guess) const { 
  return (s==guess); //T must have == overloaded
};

// driver program
int main() {
  SVal<int> intSecret(7); //Need the <int> in order to pass the type to the angle bracket
  cout << "Guess the integer value: ";
  int intGuess;
  cin >> intGuess;
  cout << (intSecret.isSecret(intGuess)?"Yes!\n":"No\n");

  // TODO: construct an object doubleSecret with value 1.5, then templatize!
  SVal<double> doubleSecret(1.5);
  cout << "GUess the double value: ";
  double doubleGuess;
  cin >> doubleGuess;
  cout << (doubleSecret.isSecret(doubleGuess)?"yes\n":"No\n");
  return 0;

}


