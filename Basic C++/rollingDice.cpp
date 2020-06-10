/* 
Name: Ante Lucev
Date: 9/23/16
Description: Program that rolles dice with given range.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <stdlib.h>

using namespace std;


int main() {

	bool hit = true;
	int maxValue = 0;
	const int MIN_VALUE = 1;
	int randNum = 0;
	string answer;

	cout << "How many sided die would you like?\n";
	cin >> maxValue;

	unsigned seed = time(0);
	srand(seed);

	while (hit) {
		randNum = (rand() % (maxValue - MIN_VALUE + 1)) + MIN_VALUE;
		cout << "You rolled a " << randNum << endl;
		cout << "Another roll y/n?";
		cin >> answer;
		if (answer == "y" || answer == "1" || answer == "yes" || answer == "Yes" || answer == "YES") {
			hit = true;
		}else {
			hit = false;
		}
	}

	return 0;
}
