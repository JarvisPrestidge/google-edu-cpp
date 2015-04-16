// cricket.cpp: Jarvis Prestidge
// Description: Calculate the temperature from the frequency of cricket chirps.

#include <iostream>

using namespace std;

int main() {

	int chirps;
	double temperature;

	// Prompt user for the number of cricket chrips per minute
	cout << "Number of cricket chirps: ";

	while (1) {
		
		if (!(cin >> chirps)) {

			// Error checking for non-numerals
			cout << "Please only enter a number!";

			// Flush the stream
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		break;
	}

	temperature = (chirps + 40) / 4;

	// Print temperature to the user
	cout << "The temperature is: " << temperature << " degrees.";

	return 0;
}