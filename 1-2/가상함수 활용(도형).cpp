#include <iostream>
using namespace std;

class Shape {
	int x, y;
public:
	Shape(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}
	//1.
	virtual double area() {
		return 1.0;
	}
};

class Rectangle : public Shape {
	double width, height;
public:
	Rectangle(double x = 0, double y = 0, double width = 0, double height = 0) : Shape(x, y) {
		this->width = width;
		this->height = height;
	}
	void setWidth(double w) {
		width = w;
	}
	void setHeight(double h) {
		height = h;
	}
	double area() {
		return width * height;
	}
};

class Triangle : public Shape {
private:
	double base, height;
public:
	Triangle(double x = 0, double y = 0, double base = 0, double height = 0) : Shape(x, y) {
		this->base = base;
		this->height = height;
	}
	void setBase(double b) {
		base = b;
	}
	void setHeight(double h) {
		height = h;
	}
	double area() {
		return base * height / 2.0;
	}
};

class Circle : public Shape {
private:
	double radius;
public:
	Circle(double x = 0, double y = 0, double radius = 0) : Shape(x, y) {
		this->radius = radius;
	}
	void setRadius(double r) {
		radius = r;
	}
	double area() {
		return 3.14 * radius * radius;
	}
};

int main()
{
	int n;
	Shape** shapeArray;//이중포인터
	double x, y, width, height, base, radius;

	cin >> n;
	shapeArray = new Shape * [n]; // shapeArray 먼저 동적으로 만들어야함
	//Shape 포인터를 저장할 공간을 만들고 거기 포인터를 shapeArray에 저장
	for (int i = 0; i < n; i++) {
		shapeArray[i] = new Shape[i];
	}


	for (int i = 0; i < n; i++) {

		int type;
		cin >> type;

		if (type == 1) { //직사각형 new 직사각형 
			cin >> x >> y >> width >> height;
			//new Reactangle 생성해서 shapeArray[i]에 저장
			shapeArray[i] = new Rectangle(x, y, width, height);
			

		}
		else if (type == 2) { //삼각형
			cin >> x >> y >> base >> height;
			shapeArray[i] = new Triangle(x, y, base, height);
			
		}
		else if (type == 3) { //원
			cin >> x >> y >> radius;
			shapeArray[i] = new Circle(x, y, radius);
			
		}
	}

	for (int i = 0; i < n; i++) {
		cout << shapeArray[i]->area() << endl;
	}

	return 0;
}
​
