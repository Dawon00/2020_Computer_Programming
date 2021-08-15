#include <stdio.h>
#include <math.h>  // sqrt
#include <stdlib.h> //malloc
//#define SIZE 100 

typedef struct point {
	float x;
	float y;
} Point;
//movePoint나 movePolygon 둘중 하나만 써야
void movePoint(Point* p, float dx, float dy)
{
	(*p).x += dx; // p->x += dx;
	(*p).y += dy; // p->y += dy;
}


float dist(Point p, Point q)//거리 구하는 함수
{
	return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
	// pow	
}


float perimeter(Point polygon[], int n) //둘레구하는 함수
{
	float length = 0;
	for (int i = 0; i < n-1; i++) {
		length += dist(polygon[i], polygon[i + 1]);
	}
	length += dist(polygon[n-1], polygon[0]);

	return length;
}



int main()
{
	int n;
	//Point polygon[SIZE];
	float dx, dy;
	Point* polygon;

	polygon = (Point*)malloc(sizeof(Point));

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%f%f", &polygon[i].x, &polygon[i].y);


	scanf("%f%f", &dx, &dy);//이동할 만큼 입력받기

	for (int i = 0; i < n; i++)
		movePoint(&polygon[i], dx, dy); //점들 다 평행이동시키기


	for (int i = 0; i < n; i++)
		printf("(%.2f,%.2f)", polygon[i].x, polygon[i].y);

	printf("\n");

	printf("%.2f", perimeter(polygon, n));

	return 0;

}
​
