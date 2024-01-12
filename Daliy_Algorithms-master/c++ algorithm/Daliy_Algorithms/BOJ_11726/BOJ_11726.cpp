// 백준알고리즘 11726번 :: 2×n 타일링
#include<iostream>
using namespace std;

int N;
int dp[1001];
int main()
{
	cin >> N;

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= 1000; i++)
	{
		dp[i] = (dp[i - 2] + dp[i - 1])%10007;
	}

	cout << dp[N];

	return 0;
}
