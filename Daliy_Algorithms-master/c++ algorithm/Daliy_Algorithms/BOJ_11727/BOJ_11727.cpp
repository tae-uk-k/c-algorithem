// 백준알고리즘 11727번 :: 2×n 타일링 2
#include<iostream>
using namespace std;

int dp[1001];
int n;

int main()
{
	int n;
	int tmp = 0;

	cin >> n;

	dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		if (i % 2) tmp = -1;
		else tmp = 1;

		dp[i] = (dp[i - 1] * 2 + tmp)%10007;
	}
	cout << dp[n];

	return 0;
}
