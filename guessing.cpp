// guessing.cpp: Jarvis Prestidge
// Description: A guessing game where the player guesses the secret number

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

	int random, guess;

	// Seed the peudo-random number generator
	srand(time(NULL));

	// Generate random number in range 0-100
	random = rand() % 100 + 1;

	cout << "Try and guess the number between 0 and 100." << endl;
	cout << "Enter your guess:" << endl;

	do {
		if (!(cin >> guess) || (guess > 100) || (guess < 0)) {
			// Error checking for non-numerals and out of range values
			cout << "Please enter a number between 0 and 100." << endl;
			// Flush the stream of the incorrect character/s
			cin.clear();
			cin.ignore(1000, '\n');
		} else if (guess > random) {
			// Guess is too high
			cout << "Too high! Try again." << endl;
		} else {
			// Guess is too low
			cout << "Too low! Try again." << endl;
		}

	} while (random != guess);

	// Successful guess!
	cout << "You got it!" << endl;
	return 0;
}