// 백준알고리즘 9095번 :: 1, 2, 3 
#include<iostream>
using namespace std;

int dp[10];

int main(void)
{
	int T, data;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i <= 10; i++)
	{
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}

	cin >> T;

	while (T--)
	{
		cin >> data;
		cout << dp[data] << '\n';
	}
	return 0;
}
