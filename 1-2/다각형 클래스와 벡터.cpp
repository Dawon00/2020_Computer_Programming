#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

//2차원 점을 위한 class Point
class Point {
	//x, y좌표
	int x;
	int y;

public:
	//Point 의 생성자(좌표를 설정한다)
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	
	//x와 y의 접근자 선언
	int getpointx() {
		return x;
	}
	int getpointy() {
		return y;
	}
};

//다각형을 위한 class Polygon
class Polygon {
	//점들을 저장하는 vector 객체, 필요한 변수를 추가할 수 있음
	vector <Point> v;

public:

	//벡터에 좌표를 저장해주는 함수
	void create(int x, int y) {
		v.push_back(Point(x, y));
	}

	//시계 반대방향일때 양수, 시계방향일때 음수, 평행일때 0을 반환
	int ccw(int x1, int x2, int x3, int y1, int y2, int y3) {
		return (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
	}

	//오목점의 개수를 반환하는 함수
	int omok(int n) {
		//오목점의 개수 count
		int count = 0;
		//ccw의 값이 음수 인 것의 개수를 세기(=오목한 점의 개수)
		//v[0](첫번째점)의 ccw 판단하기
		int result = ccw(v[n - 1].getpointx(), v[0].getpointx(), v[1].getpointx(),
			v[n - 1].getpointy(), v[0].getpointy(), v[1].getpointy());
		if (result < 0)
			count++;
		//v[n-1](마지막점)의 ccw 판단하기
		result = ccw(v[n - 2].getpointx(), v[n - 1].getpointx(), v[0].getpointx(),
			v[n - 2].getpointy(), v[n - 1].getpointy(), v[0].getpointy());
		if (result < 0)
			count++;
		//나머지 v[1]에서 부터 v[n-2]까지의 ccw 판단하기
		for (int i = 1; i < n - 1; i++) {
			result = ccw(v[i - 1].getpointx(), v[i].getpointx(), v[i + 1].getpointx(),
				v[i - 1].getpointy(), v[i].getpointy(), v[i + 1].getpointy());
			if (result < 0)
				count++;
		}
		//오목한 점의 개수를 반환함
		return count;
	}
	//다각형의 둘레를 반환하는 함수
	float perimeter(int n) {
		//점과 점 사이의 거리를 저장할 dist 변수
		//첫번째 점과 마지막 점 사이의 거리를 제외한 모든 점 사이의 거리를 더해서 dist에 저장함
		float dist = 0;
		for (int i = 0; i < n - 1; i++) {
			dist += sqrtf((v[i].getpointx() - v[i + 1].getpointx()) * (v[i].getpointx() - v[i + 1].getpointx()) +
				(v[i].getpointy() - v[i + 1].getpointy()) * (v[i].getpointy() - v[i + 1].getpointy()));
		}
		//첫번째 점~마지막 점 사이의 거리를 마저 더해줌
		dist += sqrtf((v[n - 1].getpointx() - v[0].getpointx()) * (v[n - 1].getpointx() - v[0].getpointx()) +
			(v[n - 1].getpointy() - v[0].getpointy()) * (v[n - 1].getpointy() - v[0].getpointy()));
		//둘레의 길이를 반환함
		return dist;
	}
	//다각형의 면적을 반환하는 함수
	float polygonarea(int n) {
		//면적을 저장할 변수 result
		float result = 0;
		//다각형의 면적을 구하는 공식을 이용해 result에 값을 저장
		for (int i = 0; i < n - 1; i++) {
			result += v[i].getpointx() * v[i + 1].getpointy();
			result -= v[i + 1].getpointx() * v[i].getpointy();
		}
		result += v[n - 1].getpointx() * v[0].getpointy()
			- v[0].getpointx() * v[n - 1].getpointy();
		//result의 절댓값 구하기
		//만약 result값이 음수인 경우에 양수로 바꾸어 준다
		if (result < 0)
			result *= -1;
		result = result / 2;
		//result 값을 반환해줌
		return result;
	}
};





int main() {
	//점의 개수 n, 좌표 x, y
	int n, x, y;
	//점의 개수 n을 입력받음
	cin >> n;
	//class Polygon의 멤버변수 vector v
	Polygon v;
	//반복문을 이용해 x, y값을 입력받아 create함수로 벡터에 좌표를 저장해준다
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.create(x, y);
	}

	//오목점의 개수 출력
	int omok(n);
	cout << v.omok(n) << endl;

	//다각형의 둘레 출력
	//반올림을 해서 소수 첫째자리까지만 나타낸다
	cout << fixed;//소수점 자릿수를 고정하는 표현
	cout.precision(1);//첫째자리 까지
	cout << v.perimeter(n) << endl;

	//다각형의 면적 출력
	//반올림을 해서 소수 첫째자리까지만 나타낸다

	cout << fixed;//소수점 자릿수를 고정하는 표현
	cout.precision(1);//첫째자리 까지
	cout << v.polygonarea(n) << endl;


	return 0;
}
