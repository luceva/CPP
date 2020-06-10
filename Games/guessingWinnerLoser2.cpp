/* Name: Ante Lucev
Date: 10/7/16
Desc: HW 5

1. You MUST write and use at least 5 functions.  Of those 5, 3 must use a return value in some way.
2. You MUST use at least 2 while loops.
3. You MUST use at least 3 for loops.
Requirements from HW2 (still needed)

1. You MUST use at least 5 variables (any type).
2. You MUST use at least 5 conditionals. An if counts as one, as does an if else, or else.
3. You MUST use at least 2 random numbers.  rand()
4. You MUST use at least 5 cin or getline statements.
5. You MUST use at least 10 cout statements.
6. All paths through your program must be possible; as in there is some way to reach all parts of the conditionals.
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;

const int MIN_VALUE = 1;
const int MAX_VALUE = 8;
const int MIN_AGE = 18;

int getNewLoserNum(){
	int newLoserNum;
	cout << "Try again because winner and loser can't be the same! " << endl;
	cin >> newLoserNum;
	while (newLoserNum < MIN_VALUE || newLoserNum > MAX_VALUE){
		cout << "You need to pick number from 1 - 8, try again?" << endl;
		cin >> newLoserNum;
	}
	return newLoserNum;
}

void notSameRand(int& winner, int& loser){
	if (winner == loser){
		if (loser == MAX_VALUE){
			loser--;
		}else{
			loser++;
		}
	}
}

bool IsAdult(int age, int minAge){
	if (age >= minAge){
		return true;
	}else{
		cout << "You're too young for this video game" << endl;
	}
	return false;
}

void printReport(int winner, int numWinner, int loser, int numLoser){
	int numRightAns = 0;

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
}

int randomSwimmingPoolResult(){
	unsigned seed = time(0);
	srand(seed);
	return (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
}

int main() {

	string fullName;
	int answerAge;
	int winner;
	int loser;
	int numWinner;
	int numLoser;
	
	cout << "Welcome to the swimming pool!" << endl;;

	for (int num = MIN_VALUE; num <= MAX_VALUE; num++)
		cout << num << "===================" << endl;

	cout << endl;
	cout << "What is your name?" << endl;
	getline(cin, fullName);
	cout << "Hi " << fullName << ", how old are you? " << endl;
	cin >> answerAge;

	if (IsAdult(answerAge, MIN_AGE)){
		cout << "Oh nice " << fullName << ", here is one video game for you.  " << endl;
		cout << "Try to guess who will win the race, choose one of those option? ";

		for (int x = MIN_VALUE; x <= MAX_VALUE; x++){
			cout << x << " ";
		}
		cout << endl;
		cin >> numWinner;

		while (numWinner < MIN_VALUE || numWinner > MAX_VALUE){
			cout << "You need to pick number from " << MIN_VALUE << " - " << MAX_VALUE << ", try again?" << endl;
			cin >> numWinner;
		}

		cout << "Try to guess who will be the last at the race, choose one of those option? ";
		for (int x = MIN_VALUE; x <= MAX_VALUE; x++){
			if (x != numWinner)
				cout << x << " ";
		}

		cout << endl;
		cin >> numLoser;
		
		while (numLoser < MIN_VALUE || numLoser > MAX_VALUE){
			cout << "You need to pick number from " << MIN_VALUE << " - " << MAX_VALUE << ", try again?" << endl;
			cin >> numLoser;
		}

		while (numWinner == numLoser){
			numLoser = getNewLoserNum();
		}

		winner = randomSwimmingPoolResult();
		loser = randomSwimmingPoolResult();

		notSameRand(winner, loser);
		printReport(winner, numWinner, loser, numLoser);

	}

	return 0;
}
