#include <iostream>
#include <vector>
using namespace std;
//배열중에서 제일 큰거 찾고 맨 뒤에 있는 숫자랑 바꾸기
//이걸 다하면 오름차순이 됨
int findMaxIndex(int s[], int n)//제일 큰 수 인덱스 리턴
{
	int maxPos = 0;//max의 인덱스
	for(int i=1; i<n; i++)
		if (s[i] > s[maxPos])
			maxPos = i;
		
	return maxPos;
}

void swap(int& a, int& b)//call by value로 하면 안됨
{
	int temp;
	temp = a;
	a =b;
	b =temp;
}

void sort(int s[], int n)
{
	for(int i=n; i>1; i--){
		//최대 숫자를 찾고 그 인덱스를 max라고 하기
		int maxPos = findMaxIndex(s, i);
	//맨 뒤의 수와 최대 숫자를 바꿔주기
		swap(s[maxPos], s[i-1]);
	}
	
}

int main()
{
	int *score;
	int n;
	cin >> n;
	score = new int[n];//몇개를 입력할건지
	
	for (int i = 0; i < n; i++)
		cin >> score[i];//숫자를 입력받음

	sort(score,n);

	for (int i = 0; i < n; i++)
		cout << score[i] << " ";

	cout << endl;

	return 0;
}
