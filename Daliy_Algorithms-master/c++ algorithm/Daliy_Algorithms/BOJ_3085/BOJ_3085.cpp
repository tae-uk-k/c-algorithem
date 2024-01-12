// 백준알고리즘 3085번 :: 사탕 게임
#include<iostream>
using namespace std;

int N;
char color[51][51];
int visited[51][51];
int answer = 1;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void findmaxnum(int x, int y);

// 교환 후, 가장 긴 수열 찾기
void swapping(int _x, int _y, int _mx, int _my)
{
	int temp = color[_x][_y];
	color[_x][_y] = color[_mx][_my];
	color[_mx][_my] = temp;

	// 변화된 행과 열만 탐색

	findmaxnum(_x, 0);
	findmaxnum(_y, 1);

	// 같은 행, 다른 열끼리 교환했다.
	if (_x == _mx)
	{
		findmaxnum(_my, 1);
	}
	// 같은 열, 다른 행끼리 교환했다.
	else
	{
		findmaxnum(_mx, 0);
	}

	temp = color[_x][_y];
	color[_x][_y] = color[_mx][_my];
	color[_mx][_my] = temp;
	return;
}

// 서로 다른 색을 가진 인접한 사탕 찾기
void findadjacent(int _x, int _y)
{
	for (int i = 0; i < 4; i++)
	{
		int mx = _x + dx[i];
		int my = _y + dy[i];

		if (mx < 0 || mx >= N || my < 0 || my >= N) continue;
		if (visited[mx][my]) continue;
		if (color[_x][_y] == color[mx][my]) continue;
		swapping(_x, _y, mx, my);
	}
	return;
}

// x : 몇 행 또는 열인지, y : 0은 행, 1은 열
void findmaxnum(int x, int y)
{
	if (y == 0) // x행에 대해서 탐색
	{
		for (int i = 0; i < N-1; i++)
		{
			int cnt = 1;
			for (int j = i+1; j < N; j++)
			{
				if (color[x][i] == color[x][j])
				{
					cnt++;
				}
				else break;
			}
			if (cnt > answer) answer = cnt;
		}
	}
	else // x열에 대해서 탐색
	{
		for (int i = 0; i < N - 1; i++)
		{
			int cnt = 1;
			for (int j = i + 1; j < N; j++)
			{
				if (color[i][x] == color[j][x])
				{
					cnt++;
				}
				else break;
			}
			if (cnt > answer) answer = cnt;
		}
	}
	return;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> color[i][j];
	}

	// 처음에 ans구하기
	// x : 몇 행 또는 열인지, y : 0은 행, 1은 열
	for (int i = 0; i < N; i++)
	{
		findmaxnum(i, 0);
		findmaxnum(i, 1);
	}

	// 교환하고 교환한 행, 열만 탐색하기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			findadjacent(i, j);
			visited[i][j] = 1;
		}
	}

	cout << answer;
	return 0;
}
