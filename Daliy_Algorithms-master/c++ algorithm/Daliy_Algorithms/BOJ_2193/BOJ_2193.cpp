// 백준알고리즘 2193번 :: 이친수
#include<iostream>
using namespace std;

int N;
long long dp[91];
int main()
{
	cin >> N;

	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= 90; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	cout << dp[N];

	return 0;
}
