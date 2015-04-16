// file.cpp: Jarvis Prestidge
// Description: An illustration of file processing

#include <fstream>
#include <iostream>

using namespace std;

int main() {
  char file_name[20], first_name[30], last_name[30];
  char done;
  int age;


  // Collect the data.
  cout << endl << "Enter the name of the file: "; 
  cin >> file_name;

  // Create an ofstream called People, open the stream for output.
  ofstream People(file_name, ios::out);

  while (1) {

    cout << "Enter First Name: "; 
    cin >> first_name;
    cout << "Enter Last Name: "; 
    cin >> last_name;
    cout << "Enter Age: "; 
    cin >> age; 

    // Write the output to the stream.
    People << first_name << endl << last_name << endl << age << endl;

    // Find out if user want to continue adding names
    cout << "Contine? (y/n)" << endl;
    cin >> done;
    if (done == 'n') {
      break;
    }
  }

  // Close the stream
  People.close();

  // Create an ifstream to read the file
  ifstream People_in(file_name);

  while (1) {

    People_in >> first_name >> last_name >> age;

    if (People_in.eof()) {
      break;
    }

    cout << endl << "First name: " << first_name;
    cout << endl << "Last name: " << last_name;
    cout << endl << "Age: " << age; 
    cout << endl;

  }

  // Close the stream
  People_in.close();

  return 0;
} 