// triangle.cpp

#include "triangle.h"

Triangle::Triangle() {
	x1, y1 = 1; // default triangle is 1, 2, 1, 2
	x2, y2 = 2;  
}

void Triangle::setX1(int x_1) {
	x1 = x_1;
}

void Triangle::setX2(int x_2) {
	x2 = x_2;
}

void Triangle::setY1(int y_1) {
	y1 = y_1;
}

void Triangle::setY2(int y_2) {
	y2 = y_2;
}

int Triangle::getX1() {
	return x1;
}

int Triangle::getX2() {
	return x2;
}

int Triangle::getY1() {
	return y1;
}

int Triangle::getY2() {
	return y2;
}

void Triangle::setTriangleName(string name1) {
	name = name1;
}
string Triangle::getTriangleName() {
	return name;
}


double Triangle::getArea() {
	double a, b, ab, area;

	x1 = getX1();
	x2 = getX2();
	y1 = getY1();
	y2 = getY2();

	a = x2 - x1; //need to subtract x2 and x1 to get one side of triangle 
	b = y2 - y1; //need to subtract y2 and y1 to get second side of triangle 
	ab = a * b; //multipy to sides up
	area = ab / 2; //divide two sides by 2 to get area of triangle

	return area;
}

double Triangle::getPerimeter() {
	double a, b, a2, b2, a2b2, c, per;

	x1 = getX1();
	x2 = getX2();
	y1 = getY1();
	y2 = getY2();

	a = x2 - x1; //need to subtract x2 and x1 to get one side of triangle 
	b = y2 - y1; //need to subtract y2 and y1 to get second side of triangle 

	a2 = pow(a, 2); //square one side
	b2 = pow(b, 2); //square second side

	a2b2 = a2 + b2; //add to squares up

	c = sqrt(a2b2); //take a square root of two added sides to get third side 

	per = a + b + c; //add all sides together to get perimeter

	return per;
}

void Triangle::info() {
	cout << "Name of triangle: " << getTriangleName() << endl;
	cout << "Cordinates of triangle: (" << getX1() << "," << getY1() << ")" << ",(" << getX2() << "," << getY2() << ")" << endl;
	cout << "Area of triangle: " << getArea() << endl;
	cout << "Perimeter of triangle: " << getPerimeter() << endl;

}
