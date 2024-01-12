// 백준알고리즘 1890번 :: 점프
#include<iostream>
using namespace std;

int N;
long long dp[101][101];
int visited[101][101];
int board[101][101];

// 하, 우
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };

long long dfs(int x, int y)
{
	visited[x][y] = 1;

	if (x == N - 1 && y == N - 1) return 1;
	long long &ret = dp[x][y];
	if (ret) return ret;
	if (board[x][y] == 0) return ret;

	for (int i = 0; i < 2; i++)
	{
		int mx = x;
		int my = y;

		for (int j = 0; j < board[x][y]; j++)
		{
			mx += dx[i];
			my += dy[i];
		}

		if (mx < 0 || mx >= N || my < 0 || my >= N) continue;
		if (visited[mx][my]) continue;
		dp[x][y] += dfs(mx, my);
		visited[mx][my] = 0;
	}
	return ret;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	long long ans = dfs(0,0);

	cout << ans;
	return 0;
}
