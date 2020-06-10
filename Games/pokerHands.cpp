/* Name: Ante Lucev
Date: 11/13/16
Desc: In this program, we’ll be analyzing how often certain 
    situations occur in a VERY simple game.
    
    Ask the user for how many rounds to simulate.
	Initialize counters for statistics.
	Loop the following ‘rounds’ times.
	Create a random deck of cards.
	Deal 5 cards to one player
	Deal 5 cards to another player
	Calculate each hands ‘strength’
	Update counters based on hands
	Determine if there was a tie, update stats.
	Repeat
	Print out a percentage (out of 100%) for how often each of the 5 hands was seen, plus how often a tie occurs

*/


#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;


string suit[] = { "Diamonds", "Clubs", "Spades", "Hearts" };
string value[] = { "2", "3", "4", "5", "6", "7", "8", "9",
				   "10", "Jack", "Queen", "King", "Ace" };


string getSuit(int card) {
	return suit[card / 13];
}

string getValue(int card) {
	return value[card % 13];
}

int getValuePosition(int card) {
	return (card % 13);
}


void sortCard(int array[], int length) {
	int temp;
	for (int i2 = 0; i2 < length; i2++)	{
		for (int j = 0; j < length-1; j++) {   
			if (getValuePosition(array[j]) > getValuePosition(array[j + 1])) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void print(int array[], int length) {
	for (int i = 0; i < length; i++) {
		cout << getValue(array[i]) << " of " << getSuit(array[i]) << endl;
	}
}

void shuffle(int array[], int length) {
	for (int i = 0; i < length; i++) {
		int swap = rand() % length;
		int temp = array[i];
		array[i] = array[swap];
		array[swap] = temp;
	}
}

bool flush(int array[], int length){
	string suit = getSuit(array[0]);
	for (int i = 0; i < length; i++) {
		if (getSuit(array[i]) != suit) {
			return false;
		}
		
	}
	return true;
}


bool straight(int array[], int length){
	int j = getValuePosition(array[0]);
	for (int i = 0; i < length - 1; i++) {
		if (getValue(array[i]) != value[j]) {
			return false;
		}
		j++;
	}
	return true;
}

bool straightFlush(int array[], int length) {
	if (!flush(array, length)) {
		return false;
	}
	if (!straight(array, length)) {
		return false;
	}
	return true;
}

bool royalFlush(int array[], int length) {
	if (!flush(array, length)) {
		return false;
	}
	for (int i = 0, j=8; i < length - 1; i++, j++) {
		if (getValue(array[i]) != value[j]) {
			return false;
		}
	}
	return true;
}

int main() {
	srand(time(0));
	int deck[52];
	double rounds = 0;
	int flushStat = 0;
	int straightStat = 0;
	int straightFlushStat = 0;
	int royalFlushStat = 0;
	int highCardStat = 0;
	int tieStat = 0;

	cout << "Welcome to the poker game!" << endl;
	cout << "How many rounds should I simulate?" << endl;
	cin >> rounds;

	for (int i = 0; i < rounds; i++) {

		for (int i = 0; i < 52; i++) {
			deck[i] = i;
		}

		shuffle(deck, 52);

		int hand1[5];
		int hand2[5];

		for (int i = 0; i < 5; i++) {
			hand1[i] = deck[i];
		}

		for (int i = 0; i < 5; i++) {
			hand2[i] = deck[i + 5];
		}

		sortCard(hand1, 5);
		sortCard(hand2, 5);

		if (royalFlush(hand1, 5) || royalFlush(hand2, 5)) {
			royalFlushStat++;
			if (royalFlush(hand1, 5) && royalFlush(hand2, 5)) {
				royalFlushStat++;
			}
		}else if (straightFlush(hand1, 5) || straightFlush(hand2, 5)) {
			straightFlushStat++;
			if (straightFlush(hand1, 5) && straightFlush(hand2, 5))
			{
				straightFlushStat++;
			}
		}else if (flush(hand1, 5) || flush(hand2, 5)) {
			flushStat++;
			if (flush(hand1, 5) && flush(hand2, 5)) {
				flushStat++;
			}
		}else if (straight(hand1, 5) || straight(hand2, 5)) {
			straightStat++;
			if (straight(hand1, 5) && straight(hand2, 5)) {
				straightStat++;
			}
		}else{
			highCardStat++;
		}

		if (royalFlush(hand2, 5) && royalFlush(hand1, 5)) {
			tieStat++;
		}else if (straightFlush(hand2, 5) && straightFlush(hand1, 5)) {
			tieStat++;
		}else if (flush(hand2, 5) && flush(hand1, 5)) {
			tieStat++;
		}else if (straight(hand2, 5) && straight(hand1, 5)){
			tieStat++;
		}else if (getValue(hand2[4]) == getValue(hand1[4])){
			tieStat++;
		}
	}

	cout << "Simulated Values (out of 100%):" << endl;
	cout << "Flush by Player: " << (flushStat / rounds * 2) << endl;
	cout << "Straight by Player: " << (straightStat / rounds * 2) << endl;
	cout << "Str Flush by Player: " << (straightFlushStat / rounds * 2) << endl;
	cout << "Roy Flush by Player: " << (royalFlushStat / rounds * 2) << endl;
	cout << "Avg High by Player: " << (highCardStat / rounds * 2) << endl << endl;
	
	cout << "Flush: " << (flushStat / rounds) << endl;
	cout << "Straight: " << (straightStat / rounds) << endl;
	cout << "Str Flush: " << (straightFlushStat / rounds) << endl;
	cout << "Roy Flush: " << (royalFlushStat / rounds) << endl;
	cout << "Avg High: " << (highCardStat / rounds) << endl;
	cout << "Tie: " << (tieStat / rounds) << endl;

	return 0;
}
