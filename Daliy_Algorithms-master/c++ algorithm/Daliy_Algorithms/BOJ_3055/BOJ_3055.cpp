// 백준알고리즘 3055번 :: 탈출
#include<iostream>
#include<queue>
#include<string>
using namespace std;

int R, C;
int ex, ey;
int ans;
bool flag;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
char map[51][51];
int visited[51][51];
queue<pair<int, int>> water;
queue<pair<int, int>> pos;

void bfs()
{
	while (!pos.empty())
	{
		int wsz = water.size();

		// 물 채우기
		while (wsz--)
		{
			int wx = water.front().first;
			int wy = water.front().second;
			water.pop();

			for (int i = 0; i < 4; i++)
			{
				int wmx = wx + dx[i];
				int wmy = wy + dy[i];

				if (wmx < 0 || wmx >= R || wmy < 0 || wmy >= C) continue;
				if (map[wmx][wmy] == 'D' || map[wmx][wmy] == 'X' || map[wmx][wmy] == '*') continue;
				map[wmx][wmy] = '*';
				water.push(make_pair(wmx, wmy));
			}
		}

		int qsz = pos.size();
		while (qsz--)
		{
			int x = pos.front().first;
			int y = pos.front().second;
			pos.pop();

			if (x == ex && y == ey) flag = 1;
			if (flag) break;

			for (int i = 0; i < 4; i++)
			{
				int mx = x + dx[i];
				int my = y + dy[i];

				if (mx < 0 || mx >= R || my < 0 || my >= C) continue;
				if (map[mx][my] == '*' || map[mx][my] == 'X') continue;
				if (visited[mx][my]) continue;
				visited[mx][my] = 1;
				pos.push(make_pair(mx, my));
			}
		}
		if (flag) break;
		ans++;
	}
	return;
}

int main(void)
{
	string str;
	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		cin >> str;
		for (int j = 0; j < C; j++)
		{
			map[i][j] = str[j];
			if (map[i][j] == 'S')
			{
				visited[i][j] = 1;
				pos.push(make_pair(i, j));
			}
			else if (map[i][j] == 'D')
			{
				ex = i; ey = j;
			}
			else if (map[i][j] == '*')
			{
				water.push(make_pair(i, j));
			}
		}
	}

	bfs();

	if (flag) cout << ans;
	else cout << "KAKTUS";

	return 0;
}
