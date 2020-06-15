/*HW3_triangle_menu_date.cpp

Name: Ante Luèev
Submitted on 9/26/2017; Due on 9/26/2017;

In this program I create the triangle class with menu in it, and with date class.
*/

#include "triangle_Menu_Date.h"

int Menu();

int main() {
	Triangle triangleObj;
	int x1, y1, x2, y2, month1, day1, year1, choice1;
	string name;

	Date triangleDate;

	choice1 = Menu();

	while (choice1 >= 1 && choice1 <= 6) {

		if (choice1 == 1) {
			cout << "Enter values x1, x2, y1, y2; x1<x2 and y1<2: " << endl;
			cin >> x1;
			cin >> x2;
			cin >> y1;
			cin >> y2;

			while (x1 >= x2 || y1 >= y2) {
				cout << endl << "This is not a valid. Try again!" << endl;
				cout << "Enter values x1, x2, y1, y2; x1<x2 and y1<2: " << endl;
				cin >> x1;
				cin >> x2;
				cin >> y1;
				cin >> y2;
			}


			cout << endl << "Triangle accepted!" << endl;
			triangleObj.setX1(x1);
			triangleObj.setX2(x2);
			triangleObj.setY1(y1);
			triangleObj.setY2(y2);

			cout << "Triangle name: ";
			cin >> name;

			triangleObj.setTriangleName(name);

			cout << "Month of creation: ";
			cin >> month1;
			cout << "Day of creation: ";
			cin >> day1;
			cout << "Year of creation: ";
			cin >> year1;

			triangleDate.setMonth(month1);
			triangleDate.setDay(day1);
			triangleDate.setYear(year1);
		}

		if (choice1 == 2) {
			cout << "Perimeter of triangle: " << triangleObj.getPerimeter() << endl;
		}

		if (choice1 == 3) {
			cout << "Area of triangle: " << triangleObj.getArea() << endl;
		}

		if (choice1 == 4) {
			triangleDate.printDate();
		}

		if (choice1 == 5) {
			cout << "\nTriangle info " << endl;
			triangleObj.info();
			cout << "Date of creation: ";
			triangleDate.printDate();
		}

		if (choice1 == 6) {
			exit(1);
		}

		choice1 = Menu();
	}
}

int Menu() {
	int choice;
	cout << "\n1. Enter data into triangle." << endl;
	cout << "2. Get perimeter of triangle." << endl;
	cout << "3. Get area of triangle." << endl;
	cout << "4. Get date of creation." << endl;
	cout << "5. Print the triangle information." << endl;
	cout << "6. Exit the menu." << endl;

	cout << "\nEnter your choice: ";
	cin >> choice;

	return choice;
}