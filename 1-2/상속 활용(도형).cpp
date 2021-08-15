#include <iostream>
using namespace std;

class Shape{
	double x;
	double y;
public:
	Shape(double x,double y){
		this->x = x;
		this->y = y;
	}
	void setX(double x){
		this->x = x;
	}
	void setY(double y){
		this->y = y;
	}
	double getX(){
		return x;
	}
	double getY(){
		return y;
	}
	void print(){
		cout << "Shape x,y: " << x << " " << y << endl;
	}
};

class Square : public Shape{
	double width;
	double height;
	public:
	Square(double x, double y, double width, double height) : Shape (x,y){
		this->width = width;
		this->height = height;
	}
	double getArea(){
		return width * height;
	}
	void print(){
		cout << "Square : " << width << " " << height << " " << getArea() << endl;
	}
};

class Circle : public Shape{
	double radius;
	public:
	//생성자
	Circle(double x, double y, double radius) : Shape(x,y){
		this->radius = radius;
	}
	double getArea(){
		return 3.14 * radius * radius;
	}
	void print(){
		cout << "Circle : " << radius << " " << getArea() << endl;
	}
};


int main(){
	int n;
	double x,y,z,k;
	
	cin >> n;
	
	if (n == 0){
		cin >> x >> y >> z >> k;
		Square s(x,y,z,k);
		s.print();
	}
	else{
		cin >> x >> y >> z;
		Circle c(x,y,z);
		c.print();
	}
	
	return 0;
}
