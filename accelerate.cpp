// accelerate.cpp: Jarvis Prestidge
// Description: Program to demonstrate the passing of parameters as values
// and as a reference.

#include <iostream>

using namespace std;

void Accelerate(int &speed, int amount) {
  speed += amount;
}

int main() {

  int speed = 100;

  // Print the intial speed and prompt user for amount to accelerate
  cout << "Intial vehicle speed is " << speed << " mph." << endl;
  cout << "Enter the amount you wish to speed up by: " << endl;

  int amount;

  while (1) {
    if (!(cin >> amount)) {
      // Error checking for non-numerals
      cout << "Please only enter numbers!" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
      continue;
    }
    break;
  }

  Accelerate(speed, amount);

  cout << "The new accelerated speed is " << speed << " mph!" << endl;

  return 0;

}