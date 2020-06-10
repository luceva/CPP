/* 
Name: Ante Lucev
Date: 9/13/2016
Description: Program that converts temperature from F to C. 
			 If temp between 32 and 85 F output That's just right!
			 If below 32 output That is freeeeezing!
			 If above 85 output Wow that's hot!
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	float tFahrenheight = 0.0;
	float tCelsiu = 0.0;

	cout << "Welcome to Temp converter. What is the temp in degrees F? " << endl;
	cin >> tFahrenheight;

	tCelsiu =
		(tFahrenheight - 32)
		* 5
		/ 9;

	cout << "That is " << tCelsiu << endl;

	if (32 <= tFahrenheight && tFahrenheight <= 85) {
		cout << "That's just right! " << endl;
	}
    else if (tFahrenheight < 32) {
		cout << "That is freeeeezing! " << endl;
	}
	else if (tFahrenheight > 85){
			cout << "Wow that's hot! " << endl;
	}
	
	system("pause");

	return 0;
}
