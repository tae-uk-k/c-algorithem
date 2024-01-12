// 백준알고리즘 1726번 :: 로봇
#include<iostream>
#include<queue>
using namespace std;

int M, N, ans;
int startx, starty, startdir, destx, desty, destdir;
// 로봇의 x좌표, y좌표, 방향
queue <pair<pair<int, int>, int>> robot;
int visited[101][101][5];
int factory[101][101];

// 동, 서, 남, 북
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs()
{
	int count = 0;
	while (!robot.empty())
	{
		int qsz = robot.size();

		while (qsz--)
		{
			int x = robot.front().first.first;
			int y = robot.front().first.second;
			int d = robot.front().second;
			robot.pop();

			if (x == destx && y == desty && d == destdir) return count;

			// d 방향으로 최대 3칸까지 갈 수 있다.
			int mx = x + dx[d-1];
			int my = y + dy[d-1];
			int md = d;
			int k = 3;

			while (k > 0)
			{
				if (mx < 1 || mx > M || my < 1 || my > N) break;
				if (factory[mx][my] == 1) break;
				if (!visited[mx][my][md]) {
					visited[mx][my][md] = 1;
					robot.push(make_pair(make_pair(mx, my), md));
				}
				mx += dx[d-1];
				my += dy[d-1];
				k--;
			}

			if (d <= 2) md = 3;
			else md = 1;

			// 왼쪽/오른쪽 2 방향으로 회전할 수 있다.
			for (int i = 0; i < 2; i++)
			{
				mx = x;
				my = y;
				md += i;

				if (visited[mx][my][md]) continue;
				visited[mx][my][md] = 1;
				robot.push(make_pair(make_pair(mx, my), md));
			}
		}
		count++;
	}
	return count;
}

int main()
{
	cin >> M >> N;

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> factory[i][j];
		}
	}

	cin >> startx >> starty >> startdir;
	robot.push(make_pair(make_pair(startx, starty), startdir));
	visited[startx][starty][startdir] = 1;

	cin >> destx >> desty >> destdir;

	ans = bfs();

	cout << ans;

	return 0;
}
