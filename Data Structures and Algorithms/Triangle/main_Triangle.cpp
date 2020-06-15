/*Hw1_triangle.cpp

Name: Ante Luèev 
Submitted on 9/12/2017; Due on 9/12/2017;

In this program I create the triangle class
*/ 

#include "triangle.h"

int main() {
	Triangle triangleObj;
	int x1, y1, x2, y2;
	string name;

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
	
	cout << "\nTriangle info " << endl;
	triangleObj.info();

	system("pause");
	return 0;

}

