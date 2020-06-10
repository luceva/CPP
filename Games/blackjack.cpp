/* Name: Ante Lucev
Date: 11/27/16
Desc: Write a program that plays a single hand
	  of blackjack between a human player
	  (the user of your program) and the dealer.


Initialize a deck of cards
Deal 2 cards to the player
Deal 2 cards to the dealer (only the first
card is shown until the player is done playing)
Player plays their hand
	Display the player’s current hand
	Player selects hit (get a new card) or stay
	(let the dealer play their hand)
	repeat until they player either decides to stay or busts (over 21)
Dealer plays their hand
	Automatic stay if the total is 17 or higher
	Automatic hit if the total is 16 or less
Determine the winner
	display the winner
	display both final hands
*/


#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;


vector<int> getDeck() {
	vector<int> ret;
	for (int i = 0; i < 52; i++) {
		ret.push_back(i);
	}
	return ret;
}

string suits[4] = { "Clubs", "Diamonds", "Spades", "Hearts" };
string value[13] = { "2", "3", "4", "5", "6", "7", "8", "9", "10",
"Jack", "Queen", "King", "Ace" };


int getSuit(int card) {
	return card / 13;
}

int getValue(int card) {
	return card % 13;
}

void randomize(vector<int>& cards) {
	for (int i = cards.size() - 1; i >= 1; i--) {
		float temp = cards[i];
		int new_loc = rand() % (i + 1);
		cards[i] = cards[new_loc];
		cards[new_loc] = temp;
	}
}

void printAllCard(const vector<int>& hand) {
	for (int i = 0; i < hand.size(); i++) {
		cout << value[getValue(hand[i])] << " of " << suits[getSuit(hand[i])];
		cout << endl;
	}
}

void printFirst(const vector<int>& hand) {
	cout << value[getValue(hand[0])] << " of " << suits[getSuit(hand[0])];
	cout << endl << endl;

	cout << "Other card hidden" << endl;
}

int countCard(vector<int> hand) {
	int count = 0;
	for (int i = 0; i < hand.size(); i++) {
		int v = getValue(hand[i]);

		if (v == 12) {
			count = count + 11;
		}
		else if (v > 8 && v < 12) {
			count = count + 10;
		}
		else {
			count = count + (v + 2);
		}
	}
	return count;
}

int main() {
	srand(time(0));
	string answer = "unknown";
	int i = 0;
	int j = 0;
	bool palyerLess21 = true;

	vector<int> deck = getDeck();

	randomize(deck);

	vector<int> player;
	vector<int> dealer;

	for (j = 0; j < 2; j++) {
		player.push_back(deck[i]);
		i++;
		dealer.push_back(deck[i]);
		i++;
	}


	cout << "The dealer has:\n";
	printFirst(dealer);
	cout << "Player 1 has:\n";
	printAllCard(player);

	while (answer != "F" && palyerLess21)
	{
		cout << "(H)it or (F)old?\n";
		cin >> answer;

		while (answer != "H" && answer != "F") {
			cout << "You need to put only H or F" << endl;
			cout << "(H)it or (F)old?\n";
			cin >> answer;
		}

		if (answer == "H") {
			player.push_back(deck[i]);
			i++;

			if (countCard(dealer) < 17) {
				dealer.push_back(deck[i]);
				i++;
			}

			if (countCard(player) > 21) {
				palyerLess21 = false;
			}
			cout << "*******************************" << endl;
			cout << "Player 1 has:" << endl;
			printAllCard(player);
			cout << "\nThe dealer has:" << endl;
			printFirst(dealer);
			cout << "\n*******************************" << endl;

		}
		
	}


	cout << "*******************************" << endl;
	cout << "Player 1 has:" << endl;
	printAllCard(player);

	if (!palyerLess21)
	{
		cout << "\nThe dealer has:" << endl;
		printFirst(dealer);
		cout << "\n*******************************" << endl;
		cout << "You:" << countCard(player) << endl;
		cout << "Dealer:" << countCard(dealer) << endl;
		cout << "You was over 21. Dealer wins." << endl;
	}
	else
	{
		cout << "\nThe dealer has:" << endl;
		printAllCard(dealer);
		cout << "\n*******************************" << endl;
		cout << "You:" << countCard(player) << endl;
		cout << "Dealer:" << countCard(dealer) << endl;

		int diffPlayer = 21 - countCard(player);
		int diffDealer = 21 - countCard(dealer);

		if (diffPlayer == diffDealer)
		{
			cout << "\nYou tied." << endl;
		}
		else if (diffDealer < 0) {
			cout << "\nDealer was over 21.  You win!" << endl;
		}
		else if (diffPlayer < diffDealer) {
			cout << "\nYou were closer to 21 than dealer.  You win!" << endl;
		}
		else {
			cout << "\nDealer was closer to 21 than you.  Dealer wins." << endl;
		}
	}

	return 0;
}
