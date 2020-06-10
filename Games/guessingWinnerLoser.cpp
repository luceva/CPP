/* 
Name: Ante Lucev
Date: 9/14/16
Description: Program that makes you guess who won and who was last in the swimming race.
			 You can enter the game only if you are above 18.
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main() {

	string fullName;
	int answerAge;
	const int MIN_VALUE = 1; // Minimum value
	const int MAX_VALUE = 8; // Maximum value
	const int MIN_AGE = 18; // Minimum value

	int winner, loser;
	int numWinner, numLoser;
	int numRightAns = 0;

	cout << "Welcome to the swimming pool!\n\n";

	cout << "What is your name?" << endl;
	getline(cin, fullName);
	cout << "Hi " << fullName << ", how old are you? " << endl;
	cin >> answerAge;

	if (answerAge >= MIN_AGE) {
		cout << "Oh nice " << fullName << ", here is one video game for you.  " << endl;

		cout << "Try to guess who will win the race 1 - 8? " << endl;
		cin >> numWinner;

		cout << "Try to guess who will be the last at the race 1 - 8? " << endl;
		cin >> numLoser;

		if (numWinner == numLoser) {
			cout << "Try again because winner and loser can't be the same! " << endl;
			cin >> numLoser;
		}

		unsigned seed = time(0);
		srand(seed);

		winner = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
		loser = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

		//if winner and loser are the same change the number of loser
		if (winner == loser) {
			//if loser is the last 8 put 7
			if (loser == MAX_VALUE) {
				loser--;
			}else {
				//in all other case add one to that nummber
				loser++;
			}
		}

		if (winner == numWinner) {
			cout << "You are right about winner" << endl;
			cout << "Winner is " << numWinner << endl;
			numRightAns++;
		}else {
			cout << numWinner << " is not winner. Winner is " << winner << endl;
		}

		if (loser == numLoser) {
			cout << "You are right about loser " << endl;
			cout << "Loser is " << numLoser << endl;
			numRightAns++;
		}else {
			cout << numLoser << " is not loser. Loser is " << loser << endl;
		}

		cout << "You gave " << numRightAns << " of 2 correct answers!" << endl;
	}else {
		cout << "You're too young for this video game" << endl;
	}

	system("pause");
	return 0;
}
