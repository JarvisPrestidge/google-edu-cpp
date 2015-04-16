// artillery.cpp: Jarvis Prestidge
// Description: Game that simulates firing a cannon at a distant enemy whilst 
// prompting the user for the angles of which to fire. (10 shots)

#include <iostream>
#include <cmath>
#include <random>
#include <cstdlib>

// Define constants
#define WELCOME 		"Welcome to Artillery."
#define INTRO_ONE 	"You are in the middle of a war and being charged by thousands of enemies."
#define INTRO_TWO 	"You have one cannon, which you can shoot at any angle."
#define INTRO_THREE "You only have 10 cannonballs for this target..."
#define INTRO_FOUR 	"Let's begin..."

#define VELOCITY 	200.0
#define GRAVITY		32.2
#define PI 	 			3.1415

using namespace std;

// Declare globals
int killed;

void StartUp() {
	// Print defined intro strings to the console
	cout << WELCOME << endl;
	cout << INTRO_ONE << endl;
	cout << INTRO_TWO << endl;
	cout << INTRO_THREE << endl;
	cout << INTRO_FOUR << endl;
	cout << endl;

	return;
}

int RandomDistance() {
	// Use the mersenne_twister_engine with the mt19937 configuration
	mt19937 rng;
	// Seed the engine with a random number from random_device
	rng.seed(rand());
	// Create a uniform distribution range for which to pipe rng into
	uniform_int_distribution<mt19937::result_type> dist(0, 1000);
	// Construct the random number within the distribution
	return dist(rng);
}

int Fire() {
	// Generate a truely random number for the enemy distance
	int enemy = RandomDistance();
	cout << "The enemy is " << enemy << " feet away!" << endl;

	int shots = 0;
	double angle;
	bool hit = false;

	do {
		// Prompt the user for the angle
		while (1) {
			cout << "What is the angle? ";
			if (!(cin >> angle) || (angle > 360) || (angle < 0)) {
				// Error checking for non-numberals and out of bounds
				cout << "Please enter a number 0 and 360 inclusive!" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				continue;
			}
			break;
		}

		// Convert degrees to radians
		angle = (angle * PI) / 180.0;

		// Calculate the distance the cannon ball travels
		double timeInAir = (2.0 * VELOCITY * sin(angle)) / GRAVITY;
		double distance = round((VELOCITY * cos(angle)) * timeInAir);

		if (abs(distance - enemy) <= 10) {
			hit = true;
			break;
		}

		if (distance > enemy) {
			cout << "You over shot by " << (distance - enemy) << endl;
		} else {
			cout << "You under shot by " << (enemy - distance) << endl;
		}

		shots += 1;
		if (shots >= 10) {
			cout << "You ran out of ammo!" << endl;
			return 0;
		}

	} while (!hit);

	// Successful hit
	cout << "You hit him!!!" << endl;
	cout << "It took you " << shots << " shots." << endl;

	return 1;
}

int main() {
	
	// Display the introductory script
	StartUp(); 
	
	// Score counter
	killed = 0;
	
	char again;

	// Game loop
	do {
		
		// Round loop
	  killed += Fire();

	  if (killed == 1) {
	  	cout << "You have killed " << killed << " enemy." << endl;
 		} else {
 			cout << "You have killed " << killed << " enemies" << endl;
 		}
	 
	  while (1) {
	  	cout << endl;
	  	cout << "I see another one, care to shoot again? (y/n): ";

	  	if (!(cin >> again) || (again != 'n' && again != 'y')) {
	  		// Error checking for numberals & non 'y' or 'n' characters
	  		cout << "Please enter 'y' or 'n' only." << endl;
	  		cin.clear();
	  		cin.ignore(1000, '\n');
	  		continue;
	  	}
	  	break;
	  }
	  cout << again << endl;n
	  cout << endl;
	} while (again != 'n');
	
	// End game summary
	cout << "You killed " << killed << " of the enemy." << endl;

	return 0;

} // End of main()