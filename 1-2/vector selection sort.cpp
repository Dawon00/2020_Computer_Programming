#include <iostream>
#include <vector>
using namespace std;
int findMaxIndex(vector<int> v, int n)
{
	int maxPos = 0;
	for (int i = 1; i < n; i++) {
		if (v[i] > v[maxPos])
			maxPos = i;
	}
	return maxPos;
}

void sort(vector<int>& v)
{
	int temp;
	for (int i = v.size(); i > 1; i--) {
		int maxPos = findMaxIndex(v, i);
		temp = v[i-1];
		v[i-1] = v[maxPos];
		v[maxPos] = temp;
	}
}

int main()
{
	vector<int>v;
	int n, in_score;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> in_score;
		v.push_back(in_score);
	}


	sort(v);

	for (int i = 0; i < n; i++)
		cout << v[i] << " ";

	cout << endl;

	return 0;
}
