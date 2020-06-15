// date.cpp

#include "date.h"

Date::Date() {
	month = 1;
	day = 1;
	year = 1900;
}

void Date::setMonth(int month1) {
	month = month1;
}
int Date::getMonth() {
	return month;
}
void Date::setDay(int day1) {
	day = day1;
}
int Date::getDay() {
	return day;
}
void Date::setYear(int year1) {
	year = year1;
}
int Date::getYear() {
	return year;
}
void Date::printDate() {
	if (month == 1)cout << "January ";
	if (month == 2)cout << "February ";
	if (month == 3)cout << "March ";
	if (month == 4)cout << "April ";
	if (month == 5)cout << "May ";
	if (month == 6)cout << "June ";
	if (month == 7)cout << "July ";
	if (month == 8)cout << "August ";
	if (month == 9)cout << "September ";
	if (month == 10)cout << "October ";
	if (month == 11)cout << "November ";
	if (month == 12)cout << "December ";
	cout << day << ", " << year << endl;
}