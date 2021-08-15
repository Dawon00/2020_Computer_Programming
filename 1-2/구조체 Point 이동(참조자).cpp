#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct {
	int x, y;
} Point;

void move1(Point p, int dx, int dy) // call by value
{
	p.x += dx;
	p.y += dy;
}

void move2(Point *p, int dx, int dy) // C call by reference (call by pointer) 
{
	(*p).x += dx;
	(*p).y += dy;
}

void move3(Point& p, int dx, int dy) // C++  call by reference
{
	p.x += dx;
	p.y += dy;
}

int main()
{
	// call by value, call by reference
	Point p1;
	int dx, dy;
	cin >> p1.x >> p1.y;
	cin >> dx >> dy;
	move1(p1, dx, dy);
	cout << p1.x << " " << p1.y << endl;
	move2(&p1, dx, dy);
	cout << p1.x << " " << p1.y << endl;
	move3(p1, dx, dy);
	cout << p1.x << " " << p1.y << endl;


	return 0;
}
