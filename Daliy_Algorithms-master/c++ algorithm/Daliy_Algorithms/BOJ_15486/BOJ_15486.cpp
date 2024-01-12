// 백준알고리즘 15486번 :: 퇴사2
#include<iostream>
using namespace std;
#define max(a, b) (a > b ? a : b)
int T[1500002];
int P[1500002];
int dp[1500002];
int main(void)
{
	int N, i;
	cin >> N;
	for (i = 1; i <= N; i++)
	{
		cin >> T[i] >> P[i];
	}
	for (i = N; i >= 1; i--)
	{
		// i+T[i] 가 N+1을 넘어가면 그 앞의 값 그대로.
		if (i + T[i] > N + 1)
		{
			dp[i] = dp[i + 1];
		}
		else
		{
			dp[i] = max(dp[i + 1], P[i] + dp[i + T[i]]);
		}
	}
	cout << dp[1];
	return 0;
}
