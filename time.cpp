// time.cpp: Jarvis Prestidge
// Description: Formats time in seconds to time in hours, minutes & seconds.

#include <iostream>

using namespace std;

void CalculateTime(int time) {
	// Converting seconds to hours, minutes & seconds
	int hours 	= time / (60 * 60);
	int minutes = (time / 60) % 60;
	int seconds	= time % 60;

	// Printing the output to the user
	cout << "Hours: " << hours << endl;
	cout << "Minutes: " << minutes << endl;
	cout << "Seconds: " << seconds << endl;

	return;
}

int main() {

	int time;

	while (1) {
		// Prompt the user for input in seconds
		cout << "Number of seconds: ";

		if (!(cin >> time) || (time < 0))
		{
			cout << "Please enter a numeral!" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		break;
	}

	// Call CalculateTime() passing the seconds value as a param
	CalculateTime(time);

	return 0;
}