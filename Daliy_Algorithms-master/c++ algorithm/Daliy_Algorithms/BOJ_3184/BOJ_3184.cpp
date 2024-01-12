#include<iostream>
#include<queue>
using namespace std;

int R, C;

queue<pair<int, int>> loc;
int total_sheep = 0;
int total_wolf = 0;

char map[251][251];
bool visited[251][251];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs()
{
	int local_sheep = 0;
	int local_wolf = 0;

	while (!loc.empty())
	{
		int qsz = loc.size();

		while (qsz--)
		{
			int x = loc.front().first;
			int y = loc.front().second;
			loc.pop();

			for (int i = 0; i < 4; i++)
			{
				int mx = x + dx[i];
				int my = y + dy[i];

				if (mx < 0 || mx >= R || my < 0 || my > C) continue;
				if (visited[mx][my] || map[mx][my] == '#') continue;
				if (map[mx][my] == 'o') local_sheep++;
				if (map[mx][my] == 'v') local_wolf++;
				visited[mx][my] = true;
				loc.push(make_pair(mx, my));
			}
		}
	}

	if (local_sheep > local_wolf) total_wolf -= local_wolf;
	else total_sheep -= local_sheep;

	return;
}

int main(void)
{
	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'o') total_sheep++;
			else if (map[i][j] == 'v') total_wolf++;
		}
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] != '#' && !visited[i][j])
			{
				loc.push(make_pair(i, j));
				bfs();
			}
		}
	}

	cout << total_sheep << ' ' << total_wolf;

	return 0;
}
