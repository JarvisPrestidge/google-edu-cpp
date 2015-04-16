// bookstore.cpp: Jarvis Prestidge
// Description: Program to help a college bookstore estimate business.

#include <iostream>

using namespace std;

// Define constant strings
const string BOOKCODE   = "Book code: ";
const string COPYPRICE  = "Single copy price: ";
const string NUMBER     = "Number on hand: ";
const string ENROLLMENT = "Prospective enrollment: ";
const string REQ_OPT    = "1 for required or 0 for optional: ";
const string NEW_USED   = "1 for new or 0 for used: ";
const string ANOTHER    = "Enter 1 to add another book or 0 to stop: ";
const string BARRIER    = "******************************************************";

// Declare globals
double totalCost;
double profit;

int GetInput(string str) {
  // Recieve input whilst error checking for incorrect values
  int input;

  while (true) {
    cout << str;
    if (!(cin >> input)) {
      // Error checking for non-numerals
      cout << "Please only enter either 1 or 0 depending on your choice.";
      cin.clear();
      cin.ignore(1000, '\n');
      continue;
    }
    break;
  }
  return input;
}

int OrderEstimate(int enroll, int number, int lhs, int rhs) {
  // Return an order estimate based on the required/optional
  // and new/used params
  if (lhs == 1 && rhs == 1) {
    return ((((enroll * 0.9) - number) <= 0) ? 0 : ((enroll * 0.9) - number));
  } else if (lhs == 1 && rhs ==0) {
    return ((((enroll * 0.64) - number) <= 0) ? 0 : ((enroll * 0.9) - number));
  } else if (lhs == 0 && rhs == 1) {
    return ((((enroll * 0.4) - number) <= 0) ? 0 : ((enroll * 0.9) - number));
  } else if (lhs == 0 && rhs == 0) {
    return ((((enroll * 0.2) - number) <= 0) ? 0 : ((enroll * 0.9) - number));
  }
}

int CostEstimate(int order, int price) {
  // Return a cost of books based on estimate
  return order * price;
}

void AddBook() {
  // Retrieve user input through the amazing GetInput()
  cout << "Please enter the following..." << endl;
  cout << endl;

  int bookCode  = GetInput(BOOKCODE);
  int copyPrice = GetInput(COPYPRICE);
  int number    = GetInput(NUMBER);
  int enroll    = GetInput(ENROLLMENT);
  int reqOpt    = GetInput(REQ_OPT);
  int newUsed   = GetInput(NEW_USED);

  cout << endl;
  cout << BARRIER << endl;
  cout << endl;
  
  // Print the books info
  cout << "Book: " << bookCode << endl;
  cout << "Price: " << copyPrice << endl;
  cout << "Inventory: " << number << endl;
  cout << "Enrollment: " << enroll << endl;
  cout << endl;
  cout << "This book is " << (reqOpt == 1 ? "required" : "optional")
       << " and " << (newUsed == 1 ? "new." : "used.") << endl;
  cout << endl;
  cout << BARRIER << endl;
  cout << endl;

  // Caluculating the necessary order and cost
  int order = OrderEstimate(enroll, number, reqOpt, newUsed);
  int cost  = CostEstimate(order, copyPrice);

  cout << "Need to order: " << order << endl;
  cout << "Total cost: " << cost << endl;
  cout << endl;
  cout << BARRIER << endl;
  cout << endl;

  // Update totalCost
  totalCost += cost;
}

void StartUp() {
  // Welcome text
  cout << "Welcome to the Book Store app!" << endl;
  cout << endl;
  cout << "The program is designed determine the costs and turnover " << endl;
  cout << "of the book store using the knowledge that sales depend " << endl;
  cout << "greatly on whether a book is required for a course or just " << endl;
  cout << "optional, and whether it has been used before." << endl;

  cout << endl;
}

int main () {
  // Should read like an outline for the solution!

  StartUp();

  int again = 1;

  while (again != 0) {
    // Function to book a single book 
    AddBook();

    again = GetInput(ANOTHER);
    cout << endl;
  }

  cout << BARRIER << endl;
  cout << endl;

  cout << "Total price for all orders: $" << totalCost << endl;
  cout << "Profit: $" << (totalCost * 0.2) << endl;

  return 0;
}