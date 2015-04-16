// firstday.cpp: Jarvis Prestidge	
// Description: Deciding the best choice of compensation for a new job.

#include <iostream>

// Defining constants in the preprocessor
#define kPricePerUnit 225
#define kStraightSalary 600
#define kPerHour 7.00
#define kCommission 0.10
#define kCommission2 0.20
#define kCommissionOnSale 20
#define kHoursPerWeek 40


using namespace std;

int GetInput() {

	int units;

	// Prompt user for the number of weekly sales
	cout << "Enter the expected number of weekly shoe sales:" << endl;
	
	while (true) {

		// Error checkng for non-numerals and below 0 values
		if (!(cin >> units) || units < 0) {
			cout << "Numbers above 0 only please." << endl;
			// Flush the stream of the incorrect character/s
			cin.clear();
			cin.ignore(1000, '\n');
		} else {
			return units;
		}
	}
}

int CalcMethod1() {
	// Straight salary of $600 per week
	cout << "Method 1 provides a wage of $" << kStraightSalary << " per week." << endl;
}

CalcMethod2(int sales) {
	// A salary of $7.00 per hour plus a 10% commission on sales
	int withoutCom = kHoursPerWeek * kPerHour;
	int commission = (sales * kPricePerUnit) * kCommission;
	int wage = withoutCom + commission;

	cout << "Method 2 provides a wage of $" << wage << " per week." << endl;
}

CalcMethod3(int sales) {
	// No salary, but 20% commissions and $20 for each pair of shoes sold
	int commission = (sales * kPricePerUnit) * kCommission2;
	int bonus = sales * 20;
	int wage = commission + bonus;

	cout << "Method 3 provides a wage of $" << wage << " per week." << endl;
} 

int main() {

	int WeeklySales;

	// Subroutines for determining highest salary/compensation
	WeeklySales = GetInput();
  	CalcMethod1();
  	CalcMethod2(WeeklySales);
  	CalcMethod3(WeeklySales); 
  	return 0;
}
