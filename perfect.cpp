// perfect.cpp: Jarvis Prestidge
// Description: Find the next perfect square above 1225 that is the sum
// of a series 1...n.

#include <cmath>
#include <iostream>
#include <map>

using namespace std;

void StartUp() {
  // Welcome text
  cout << "This program prints the values of perfect squares, " << endl;
  cout << "that also meet the criteron of valuing the summation " << endl;
  cout << "of natural numbers 1..n inclusive." << endl;

  cout << endl;
}

bool SumChecker(long square) {

  long sum = 1;
  int counter = 1;

  // Check whether the number passed is the summation of whole numbers
  while (true)
  {
    // Incrementing and summing integers from 1...n
    sum += ++counter;
    // Checking for equality between summation and square
    if (sum == square) {
      return true;
    } else if (sum > square) {
      // If sum supercedes the square return false
      return false;
    }
  }
}

long IterativeSum(int &num) {
  // Iteratively calculate the next perfect square

  while (true) {
    // Square the num
    long square = num * num;
    // Check if "square" is the summation of whole integers 1..n
    if (SumChecker(square)) {
      return square;
    }
    num ++;
  }
}

int main() {

  StartUp();

  map<int, string> myMap;
  myMap[1] = "first";
  myMap[2] = "second";
  myMap[3] = "thrid";
  myMap[4] = "fourth";
  myMap[5] = "fifth";
  myMap[6] = "sixth";
  myMap[7] = "seventh";
  myMap[8] = "eigth";
  myMap[9] = "nineth";
  myMap[10] = "tenth";

  int num, i = 1;
  char again;

  while (true) {

    // Call the calculation
    long perfectNum = IterativeSum(num);

    // Increment num by 1 so IterativeSum doesn't compute
    // the same result
    num ++;

    cout << "The " << myMap[i] << " perfect square is " 
         << perfectNum << "." << endl;

    cout << endl;      

    while (true) {
      cout << "Would you like to compute another? (y/n)" << endl;
      if (!(cin >> again) || (again != 'n' && again != 'y')) {
        // Error checking for numerals 
        cout << "Please only enter either an 'n' or a 'y'." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        continue;
      }
      break;
    } // End of error checking loop

    if (again == 'n') {
      return 0;
    }
  
  } // End of program loop

} // End of main()