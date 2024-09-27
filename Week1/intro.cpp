#include <iostream>
#include <string>
#include <typeinfo>

int main()
{
  // use numbers without variables

  std::cout << (5 + 3) << std::endl;

  /*
  DECLARING VARIABLES!!!
  */

  double a = 5;
  int b = 3;

  auto c = a + b;

  std::cout << (a + b) << std::endl; // gives an int
  std::cout << (a / b) << std::endl; // gives a float

  std::cout << c;

  // Acceptign output from user

  int courseNumber;
  std::cout << "Please enter the course number below";
  std::cin >> courseNumber;
  std::cout << "Welcome to CSCI " << courseNumber << "!" << std::endl;

  // Array stuff

  int threeInts[3] = {4, 6, 7};
  std::cout << threeInts[0] << std::endl;
  std::cout << threeInts[1] << std::endl;
  std::cout << threeInts[2] << std::endl;

  // Boolean
  bool eligible = false;
  std::cout << eligible << std::endl;

  eligible = true;
  std::cout << eligible << std::endl;

  std::cout << "You are " << (eligible ? "" : "not") << "eligible";

  bool fax = true;

  std::cout << "It is " << (fax ? "" : "not") << "fax" << std::endl;

  fax = false;

  std::cout << "It is " << (fax ? "" : "not") << "fax" << std::endl;

  // 3 LOOPS

  std::cout << "Hip hip hooray!\n";

  for (int i = 0; i < 3; i++)
  {
    std::cout << "Hip Hip hooray";
  }
}