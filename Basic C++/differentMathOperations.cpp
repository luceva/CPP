/* 
Name: Ante Lucev
Date: 9/20/16
Description: Given low and high value do substraction, sum of all numbers in between, sum of all squares
			 in between, number of evens, number of numbers ending with 0 all including endpoints.
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>

using namespace std;

int main() {
    
	int n1;
	int n2;
	int sumAll = 0, sumSquares = 0, even = 0, endZero = 0;

	cout << "Enter a low and high value " << endl;
	cin >> n1;
	cin >> n2;

	if (n1 >= n2){
		cout << "Low number can't be greater that high number." << endl;
	}else{
        cout << "Difference is: " << n2 - n1 << endl;

		while (n1 <= n2){
			sumAll = sumAll + (n1);
			sumSquares = sumSquares + (pow(n1, 2));
	
			if (n1 % 2 == 0){
				even++;
			}
			if (n1 % 10 == 0){
				endZero++;
			}
			n1++;
		}
		cout << "Sum: " << sumAll << endl;
		cout << "Sum of squares: " << sumSquares << endl;
		cout << "Evens: " << even << endl;
		cout << "End in zero: " << endZero << endl;
	}
	
	return 0;
}
