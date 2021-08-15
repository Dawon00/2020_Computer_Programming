#include <iostream>

using namespace std;

int main()
{

	int* score;
	int n;

	cin >> n;
	score = new int[n];
	for (int i = 0; i < n; i++){
		cin >> score[i];
	}
	for (int i = 0; i < n; i++){
		cout << score[i] << endl;
	}

	delete[] score;

	return 0;
}
