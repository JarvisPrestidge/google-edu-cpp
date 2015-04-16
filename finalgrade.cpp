// finalgrade.cpp: Jarvis Prestige
// Description: Program to calculate your final grade for a course of some kind.

#include <iostream>

// Define constants
#define FIRST_ASSIGNMENT "Enter the score for the first assignment: " 
#define SECOND_ASSIGNMENT "Enter the score for the second assignment: " 
#define THIRD_ASSIGNMENT "Enter the score for the thrid assignment: " 
#define FOURTH_ASSIGNMENT "Enter the score for the fourth assignment: "
#define MIDTERM "Enter the score for the midterm: "
#define FINAL "Enter the score for the final: " 
#define SECTION "Enter the score for the section grade: " 

using namespace std;

// Declare globals
double first, second, third, fourth, midterm, fin, section;
double score;

double Calculate() {
	// Calculate the final score
	double temp1 = ((first + second + third + fourth) / 4) * 0.4;
	double temp2 = midterm * 0.15;
	double temp3 = fin * 0.35;
	double temp4 = section * 0.1;

	double temp5 = temp1 + temp2 + temp3 + temp4;
	return temp5;

}

double GetInput(string str) {

	double temp;

	while (1) {
		
		// Print the passed param str and save user input
		cout << str;

		if (!(cin >> temp) || (temp < 0) || (temp > 100)) {
			// Error checking for non-numerals
			cout << "Please enter a number between 0 and 100 inclusive!" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		break;
	}
	return temp;
}

int main() {

	// Pass the various strings to user to store input
	first 	= GetInput(FIRST_ASSIGNMENT);
	second 	= GetInput(SECOND_ASSIGNMENT);
	third 	= GetInput(THIRD_ASSIGNMENT);
	fourth 	= GetInput(FOURTH_ASSIGNMENT);
	midterm = GetInput(MIDTERM);
	fin 	= GetInput(FINAL);
	section = GetInput(SECTION);

	// Calculate the score
	score = Calculate();

	// Print the score
	cout << "The final grade is: " << score;

	return 0;
}