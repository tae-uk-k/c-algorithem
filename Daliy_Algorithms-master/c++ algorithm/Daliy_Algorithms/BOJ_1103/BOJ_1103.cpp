// 백준알고리즘 1103번 :: 게임

// 접근은 맞았으나 계속 틀림.
// 틀린 원인 : dp에 값이 있을 때, 바로 return 해주지 않았다. => 시간초과
//				return count; dfs(x, y, count+1); 로 풀었는데 틀렸습니다가 나왔다
//				다른 사람의 코드를 참고하여 return 0; dfs(x,y)+1; 로 바꾸었는데 원인을 아직 정확히 파악하지 못했다.

// *** 래퍼런스 변수 사용 익히기

#include<iostream>
#include<string>
#include<memory.h>
#define max(a,b) a > b ? a: b
using namespace std;

int N, M;
int cycle = 0;
char board[50][50];
int dp[50][50] = {-1,};
int visited[50][50];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int dfs(int x,int y)
{
	// 범위를 넘어갈 때
	if (x < 0 || x >= N || y < 0 || y >= M)
		return 0;
	// 구멍에 빠질 때
	if (board[x][y] == 'H')
		return 0;
	// 방문한 곳을 다시 방문할 때
	if (visited[x][y]) {
		cout <<  "-1";
		exit(0);
	}
	int &ret = dp[x][y];
	if (ret != -1) return ret;
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		int mx = x + (board[x][y] - '0')*dx[i];
		int my = y + (board[x][y] - '0')*dy[i];

		int val = dfs(mx, my)+1;
		ret = max(ret, val);
	}
	visited[x][y] = 0;
	return ret;
}

int main()
{
	string str;
	cin >> N >> M;
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			board[i][j] = str[j];
		}
	}

	cout << dfs(0,0);
	return 0;
}
