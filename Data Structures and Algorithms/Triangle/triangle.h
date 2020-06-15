// triangle.h
#ifndef triangle_h //prevent multiple inclusions of a class
#define triangle_h
#include <iostream>
#include <string>
#include <math.h>  //sqrt, pow

using namespace std;

class Triangle {
private:
	int x1, y1, x2, y2;
	string name;
public:
	Triangle(); //deafault constructor
	void setTriangleName(string name1);
	string getTriangleName();	
	void setX1(int x_1);
	void setX2(int x_2);
	void setY1(int y_1);
	void setY2(int y_2);
	int getX1();
	int getX2();
	int getY1();
	int getY2();
	double getArea();
	double getPerimeter();
	void info();
};

#endif
