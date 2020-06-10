/*
Name: Ante Luèev
Description: Create plot.cpp so it asks the user for the parameters of a simple function (below),
			and then plots a text plot of the function from x=-15 to 15 and y = -10 to 10.
			To make this easier, use y for the horizontal axis and x for the vertical.
			x=-15 should be up top and x=15 should be on bottom.
			y=-10 on the left and y=10 on the right.
			Use a period to mark the line.
			Prompt the user for 3 floating point values, C0, C1, C2
			f(x) = C0 + C1x + C2x2
			
			Assume the window is 80 characters wide and 80 characters high.
			It would be good to have  x=0 and y=0 lines.
			See below for example output.  Entered values are in bold.
*/

#include <iostream>

using namespace std;

int main() {

	float c0 = 0.0;
	float c1 = 0.0;
	float c2 = 0.0;
	cout << "Enter 3 numbers to fill in the function:\n";
	cout << "C0 + C1 * x + C2 * x^2\n";
	cin >> c0 >> c1 >> c2;

	float intervalX = (15.0 - -15.0) / 80.0;
	float intervalY = (10.0 - -10.0) / 80.0;
	float xMax = -15, xMin = 15, yMin = -10, yMax = 10; 

	float positionY, positionX;

	positionY = yMin;  
	positionX = xMax;   

	float resultY;


	while (positionX <= xMin)
	{
		positionY = yMin;
		resultY = c0 + c1 * positionX + c2 * positionX * positionX;

		while (positionY <= yMax)
		{
			//if (((int)positionY) == ((int)resultY)) //round
			if ((positionY - intervalY) < resultY && resultY < positionY)
			{
				cout << ".";
			}
			else if (positionY == yMin || positionY == yMax)
			{
				cout << "|";
			}
			else if (positionY == 0 && positionX != 0)
			{
				cout << "|";
			}
			else if (positionX == 0 && positionY != 0)
			{
				cout << "-";
			}
			else if (positionY == 0 && positionX == 0)
			{
				cout << "+";
			}
			else
			{
				cout << " ";
			}
			positionY = positionY + intervalY;
		}
		cout << "\n";
		positionX = positionX + intervalX;
	}
	cout << "\n";


	system("pause");
	return 0;
}
