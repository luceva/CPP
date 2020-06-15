// date.h
#ifndef date_h //prevent multiple inclusions of a class
#define date_h
#include <iostream>
#include <string>

using namespace std;

class Date {
private:
	int month;
	int day;
	int year;

public:
	Date(); //deafault constructor
	void setMonth(int month1);
	int getMonth();
	void setDay(int day1);
	int getDay();
	void setYear(int year1);
	int getYear();
	void printDate();
};

#endif