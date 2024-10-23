// Use this program as a self-quiz. Draw memory diagrams and predict its output.
// Then run the program and either become more confident that you know what's 
// going on, or identify where you need more pointer practice!
//
// Sara Krehbiel, 10/21/24

#include <iostream>

using namespace std;

void sumAndIncrementArray(double& sum, double a[], int size);
double* tripleArray(double* arr, int size);
double triple(double d);
double* doubleDoubleOnHeap(double d);

int main() {
  // Some basic uses of * and &:
  int a = 3; // declare and initialize an int
  int *q; // declare an int pointer
  q = &a; // assign an int pointer the address of an int
  cout << *q << endl; // dereference a pointer to access the val it points to
  *q = 5; // dereference a pointer on the lhs of an assignment statement
          // to change the value it points to
  cout << *q << endl; 

  // You'd already been using pointers with arrays and pass-by-reference...

  double total = 0, arr[3] = {1.5,2.5,3.5};

  // DIAGRAM 1

  sumAndIncrementArray(total, arr, 3);
  cout << "total=" << total << endl;

  // DIAGRAM 4

  // and now you can use pointers to return arrays!

  // double anotherArray[] = doubleArray(arr,size); // not allowed!
  double *p = tripleArray(arr,3);

  for (int i =0; i < 3; i++) 
  { 
    cout << "Returned Array Value: " << *(p+i) << endl; 
    cout << "Original array value: " << arr[i] << endl;
    cout << "Total: " << total << endl;
    cout << "a: " << a << endl;
    cout << "*q: " << *q << endl;
  }

  // // DIAGRAM 7

  cout << "p contents: "; 
  for (int i=0; i<3; i++) cout << *(p+i) << " ";
  delete [] p; // release heap memory when you're done with it and assign
  p = nullptr; // pointers to nullptr, though it's not needed for compilation

  // You can also declare non-arrays on the heap.

  double value = 5;
  double thrice = triple(value);

  // DIAGRAM 9

  p = doubleDoubleOnHeap(thrice); // orphans memory if you didn't delete [] p

  // DIAGRAM 11

  cout << "p contents: "; 
  for (int i=0; i<3; i++) cout << *(p+i) << " ";
  delete p; // not practically needed, but good practice to release heap memory
  p = nullptr; // right before program ends

  // DIAGRAM 12
  
  return 0;
}

//recall how to use pass-by-reference and arrays in functions
void sumAndIncrementArray(double& sum, double a[], int size) {
  double temp = 0;

  // DIAGRAM 2

  for (int i=0; i<size; i++) { 
    temp += a[i]++; 
  }
  sum = temp;

  // DIAGRAM 3
}

// create and populate a new array on the heap and return a pointer to it
double* tripleArray(double* arr, int size) {
  double *p = new double[size];

  // DIAGRAM 5

  for (int i=0; i<size; i++) {
    p[i]=3*arr[i];
  }

  // DIAGRAM 6 

  return p;
}

// a basic function without any references or pointers
double triple(double d) {
  double temp = 3*d;

  // DIAGRAM 8 

  return temp;
}

// a function that allocates memory and returns a pointer
double* doubleDoubleOnHeap(double d) {
  double *ptr = new double;
  *ptr = d*2;

  // DIAGRAM 10

  return ptr;
}