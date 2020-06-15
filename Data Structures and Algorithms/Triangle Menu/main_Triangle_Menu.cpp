/*HW2_triangle_menu.cpp

Name: Ante Luèev
Submitted on 9/12/2017; Due on 9/19/2017;

In this program I create the triangle class with menu in it.
*/

#include "triangle_Menu.h"

int Menu();

int main() {
	Triangle triangleObj;
	int x1, y1, x2, y2, choice1;
	string name;

	choice1 = Menu();

	while (choice1 >= 1 && choice1 <= 5) {

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
		}

		if (choice1 == 2) {
			cout << "Perimeter of triangle: " << triangleObj.getPerimeter() << endl;
		}

		if (choice1 == 3) {
			cout << "Area of triangle: " << triangleObj.getArea() << endl;
		}
		
		if (choice1 == 4) {
			cout << "\nTriangle info " << endl;
			triangleObj.info();
		}

		if (choice1 == 5) {
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
	cout << "4. Print the triangle information." << endl;
	cout << "5. Exit the menu." << endl;

	cout << "\nEnter your choice: ";
	cin >> choice;

	return choice;
}
