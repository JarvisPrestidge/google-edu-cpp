// helloworld.cpp: Jarvis Prestidge
// A program that prints hello world

#include <iostream>
#include <iomanip>

using namespace std;

int rows = 6;
int columns = 4;

int main() 
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			cout << setw(17) << left << "Hello World!";
		}
		
		cout << endl;
	}
	
	return 0;
}