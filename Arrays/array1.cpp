/*
Name: <Ante Lucev>
Date: <10/31/16>
Description: <init - Accepts an int array, its length, and an integer value to copy to all elements of the array.  
                     Does not return anything, but will change the array.
              init - Same as above, but accept a string array, length, and string value to copy to all elements. 
			  count - Accepts an int array, its length, and an integer value to search for.  
			          Return the number of times that value was found in the array. 
					  Return 0 of the length is 0 or less.
              count - Same as above, but accepts a string array, length, and the string to search for.
              range - Accepts an int array, its length, and returns the max-min.  
			          Return 0 if the length is 0 or less.
              histogram - Accepts an int array and its length.  
			              The values in the array will be from 0-20 inclusive.  
						  Print out a vertical histogram.  The first printed line should have 
						  one ‘*’ character per times 0 was found in the array, the second, 
						  the number of times 1 was found, etc, all the way to 20.  
						  Remember functions can call other functions!  This will not return anything.
              containsDups - Accepts an int array and its length.  Return a boolean, 
			                 true if the array contains the same integer at least twice, 
							 false if all values in the array are unique.
              isSorted - Accepts an int array and its length.  
			             Returns a boolean, true if the array is sorted from smallest to largest, 
						 false if it is not sorted.  Adjacent duplicate elements are allowed.  
						 A list of 1 or fewer elements is sorted.>

*/
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>

using namespace std;

void init(int array[], int length, int value) {
	for (int i = 0; i < length; i++)
	{
		array[i] = value;
	}
}

void init(string array[], int length, string value) {
	for (int i = 0; i < length; i++)
	{
		array[i] = value;
	}
}
	
int count(int array[], int length, int value) {
	int c = 0;
	if (length <= 0)
	{
		return 0;
	}
	else
	{
		for(int i = 0; i < length; i++)
		{
			if(array[i] == value)
			{
				c++;
			}
		}
		return c;
	}
}

int count(string array[], int length, string value) {
	int c = 0;
	if (length <= 0)
	{
		return 0;
	}
	else
	{
		for(int i = 0; i < length; i++)
		{
			if(array[i] == value)
			{
				c++;
			}
		}
		return c;
	}
}

int range(int array[], int length) {
	if(length <= 0)
	{
		return 0;
	}
	
	int sum;
	int curMax = array[0];
	int curMin = array[0];
	for(int i = 0; i < length; i++)
	{
	    if(array[i] > curMax)
		{
			curMax = array[i];
		}
		else if(array[i] < curMin)
		{
			curMin = array[i];
		}
        sum = curMax - curMin;
    }
	return sum;
}

void histogram(int array[], int length) {
	
	int count = 0;
	for(int j = 0; j <= 20;j++)
	{
		count = 0;
		for (int i = 0; i < length; i++)
		{
			if (array[i] == j)
			{
				count++;
			}
		}
		cout << j << ": ";

		for (int c = 1; c <= count; c++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

bool containsDups(int array[], int length) {
	for(int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if ((array[i] == array[j]) && j != i)
			{
				return true;
			}
		}
	}
	return false;
}

bool isSorted(int array[], int length) {
	for(int i = 1; i < length; i++)
	{
		if(array[i-1] > array[i])
	    {
		    return false;
	    }
	}
	return true;
}


int main() {
	cout << "Init w/ ints" << endl;
	int a1[] = { 1,2,3,4,5 };
	init(a1, 5, 99);
	cout << "99 = " << a1[3] << endl;
	cout << "99 = " << a1[1] << endl;

	cout << endl << "Init w/ strings" << endl;
	string a2[] = { "", "Bla", "What?", "You don't say!" };
	init(a2, 4, "Empty");
	cout << "Empty = " << a2[0] << endl;
	cout << "Empty = " << a2[3] << endl;

	cout << endl << "Count w/ ints" << endl;
	int a3[] = { 1,2,3,4,5,6,7,1,2 };
	cout << "1 = " << count(a3, 9, 5) << endl;
	cout << "2 = " << count(a3, 9, 1) << endl;
	int a4[100];
	for (int i = 0; i < 100; i++) {
		a4[i] = (i + i % 7) % 11;
	}
	cout << "8 = " << count(a4, 100, 5) << endl;
	cout << "9 = " << count(a4, 100, 1) << endl;

	cout << endl << "Count w/ strings" << endl;
	string a5[] = { "blab", "ha", "ha" };
	cout << "1 = " << count(a5, 3, "blab") << endl;
	cout << "2 = " << count(a5, 3, "ha") << endl;

	cout << endl << "Range" << endl;
	int a6[] = { 1,2,1,10,-5,34 };
	cout << "39 = " << range(a6, 6) << endl;
	cout << "9  = " << range(a6, 4) << endl;

	cout << endl << "Contains Dups" << endl;
	cout << "1 = " << containsDups(a6, 6) << endl;
	cout << "0 = " << containsDups(a6, 2) << endl;
	cout << "1 = " << containsDups(a4, 100) << endl;

	cout << endl << "Is Sorted" << endl;
	int a7[] = { 1,2,2,3,5,10,100 };
	int a8[] = { 1,2,3,4,4,5,4 };
	cout << "0 = " << isSorted(a6, 6) << endl;
	cout << "1 = " << isSorted(a1, 5) << endl;
	cout << "1 = " << isSorted(a7, 7) << endl;
	cout << "0 = " << isSorted(a8, 7) << endl;

	cout << endl << "Histograms" << endl;
	histogram(a8, 7);
	cout << endl;
	int a9[500] = {};
	for (int i = 0; i < 500; i++) {
		a9[i] = (rand() % 11) + (rand() % 11);
	}
	histogram(a9, 500);
	cout << endl;
	int a10[100] = {};
	for (int i = 0; i < 100; i++) {
		a10[i] = (i + i % 7) % 15;
	}
	histogram(a10, 100);
	
	system("pause");
	return 0;
}
