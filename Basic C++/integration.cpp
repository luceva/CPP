#include <iostream>
#include <math.h>

/*Allow the user to enter 8 numbers: 7 floating point values: C 0 , C 1 , C 2 , C 3 ,
E, R min , R max in that order, followed by a positive integer S . These correspond
to the following equation:
f(x) = C 0 + C 1 x + C 2 x 2 + C 3 x E
With E an arbitrary exponent, R min and R max the range to analyze over (inclusive).
If R min is greater or equal to R max , repeat the question until a pair of valid numbers
are given.
S corresponds to the number of samples to use. If less than 2 is given, repeat the
question until a valid number is given.
Using the values they enter, you are to find and print the following statistics:
1. Maximum f(x) over the given range.
2. Minimum f(x) over the given range.
3. Number of times f(x) = 0 over the given range. (Crosses the x axis,
goes from neg to pos, or pos to neg)
4. Area under the curve over the given range. Below the xaxis
is negative
area, so this should closely match the integral over the range given a high
enough S value (> 100).
To calculate all of these statistics, estimate the actual answer by running through
the given range with S data points. You may ONLY use the number of points
provided. Yes, your answers will not be accurate for small S! Use the trapezoid
rule for the area calculation.
Draw some pictures and verify your code produces correct results.
See the end of this document for many example runnings of the program.

Welcome To Your Personal Integrator!
Enter 5 values to fill in the equation:
C0 + C1 * X + C2 * X^2 + C3 * X^(E)
C0: 5.6
C1: 8.7
C2: 0
C3: 0
E: 0
Now enter range min and max: 25
25
Now enter the number of samples to use (>=2): 2
Maximum f(x): 223.1
Minimum f(x): 211.9
f(x) = 0 count: 1
Area of f(x): 280
*/

using namespace std;

int main() {

	float c0 = 0.0;
	float c1 = 0.0;
	float c2 = 0.0;
	float c3 = 0.0;
	float e = 0.0;
	float minR = 0.0;
	float maxR = 0.0;
	int s;

	cout << "Welcome To Your Personal Integrator!\n";
	cout << "Enter 5 values to fill in the equation:\n";
	cout << "C0 + C1 * X + C2 * X^2 + C3 * X^(E)\n";
	cout << "C0:";
	cin >> c0;
	cout << "C1:";
	cin >> c1;
	cout << "C2:";
	cin >> c2;
	cout << "C3:";
	cin >> c3;
	cout << "E:";
	cin >> e;

	cout << "Now enter range min and max: ";
	cin >> minR >> maxR;
	while (minR >= maxR)
	{
		cout << "Min range can't be greater or equal to max range!";
		cin >> minR >> maxR;
	}

	cout << "Now enter the number of samples to use (>=2): ";
	cin >> s;
	while (s < 2)
	{
		cout << "Samples must be greater or equal 2! ";
		cin >> s;
	}

	float maxFx = 0.0;
	float minFx = 0.0;
	float numOver = 0;
	float area = 0;

	minFx = c0 + c1*minR + c2*pow(minR, 2) + c3*pow(minR, e);
	maxFx = minFx;

	double interval = (maxR - minR) / (s - 1);
	double auxFx = minFx;

	for (int i = 0; i < s - 1; i++) {

		minR = minR + interval;

		double fx = c0 + c1 * minR + c2*pow(minR, 2) + c3 * pow(minR, e);

		if (maxFx < fx)
		{
			maxFx = fx;
		}
		if (minFx > fx)
		{
			minFx = fx;
		}
		if ((auxFx < 0 && fx > 0) || (auxFx > 0 && fx < 0))
		{
			numOver++;
		}

		area += (fx + auxFx) * interval / 2;
		auxFx = fx;
	}

	cout << "Maximum f(x): " << maxFx << endl;
	cout << "Minimum f(x): " << minFx << endl;
	cout << "f(x) = 0 count: " << numOver << endl;
	cout << "Area of f(x): " << area << endl;

	return 0;
}
