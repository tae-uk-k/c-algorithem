// 백준알고리즘 11053번 :: 가장 긴 증가하는 부분 수열
#include<iostream>
#include<string.h>
#define max(a , b) (a > b) ? a : b
int N, ans;
int arr[1001];
int dp[1001];
using namespace std;
int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		dp[i] = 1;
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			// 뒤가 더 크면 증가하는 수열이다. 길이를 갱신한다.
			if (arr[j] < arr[i]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	ans = dp[0];
	for (int i = 0; i < N-1; i++)
	{
		if (ans < dp[i + 1]) ans = dp[i + 1];
	}
	cout << ans;
	return 0;
}
