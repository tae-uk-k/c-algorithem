// 백준알고리즘 1010번 :: 다리 놓기
#include<iostream>
using namespace std;
int T, N, M;
long long dp[31][31];
int main(void)
{
	for (int n = 0; n <= 30; n++)
	{
		dp[0][n] = dp[n][n] = 1;
	}
	for (int n = 1; n < 30; n++)
	{
		for (int m = 1; m <= (30 - n); m++)
		{
			dp[m][m + n] = dp[m][m+n-1] + dp[m-1][m+n-1];
		}
	}
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		cout << dp[N][M] << '\n';
	}
	return 0;
}
