// 백준알고리즘 2234번 :: 성곽
#include<iostream>
#include<queue>
using namespace std;

int n, m, ans1, ans2, ans3;
unsigned int castle[51][51];
int visited[51][51];
int group[51][51];
int cnt = 0;

// 서 북 동 남
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int point[2501] = { 0 };

void bfs(int _x, int _y)
{
	cnt++;
	queue<pair<int, int>>q;
	q.push(make_pair(_x, _y));
	visited[_x][_y] = 1;
	group[_x][_y] = cnt;
	int size = 1;

	while (!q.empty())
	{
		int qsz = q.size();
		while (qsz--)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int mx = x + dx[i];
				int my = y + dy[i];

				if (mx < 0 || mx >= m || my < 0 || my >= n) continue;
				if (visited[mx][my]) continue;
				if (castle[x][y] & (1 << i)) continue;
				visited[mx][my] = 1;
				group[mx][my] = cnt;
				q.push(make_pair(mx, my));
				size++;
			}
		}
	}
	point[cnt] = size;
	return;
}

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> castle[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j]) continue;
			bfs(i, j);
		}
	}

	int ret = 0;
	ans1 = cnt;

	for (int i = 1; i <= cnt; i++)
	{
		ret = point[i];
		if (ans2 < ret) ans2 = ret;
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n-1; j++)
		{
			if (group[i][j] != group[i][j + 1])
				ret = point[group[i][j]] + point[group[i][j + 1]];
			if (ans3 < ret) ans3 = ret;
		}
	}

	for (int i = 0; i < m-1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (group[i][j] != group[i+1][j])
				ret = point[group[i][j]] + point[group[i+1][j]];
			if (ans3 < ret) ans3 = ret;
		}
	}

	cout << ans1 << '\n'<< ans2 << '\n' << ans3 << '\n';

	return 0;
}
