// 백준알고리즘 11722번 :: 가장 긴 감소하는 부분 수열
#include<iostream>
using namespace std;
#define max(a,b) (a > b) ? a: b
int N;
int arr[1001];
int lds[1001];

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++)
	{
		lds[i] = 1;
		for (int j = 0; j < i; j++)
		{
			// 앞의 값이 큰 값이면, 길이 갱신.
			if (arr[j] > arr[i]) lds[i] = max(lds[i], lds[j] + 1);
		}
	}

	int ans = lds[0];
	for (int i = 1; i < N; i++)
		if (ans < lds[i]) ans = lds[i];

	cout << ans;

	return 0;
}
