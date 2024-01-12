// 백준알고리즘 2146번 :: 다리 만들기
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int N;
int init_land;
int ans = 10000;

queue<pair<int, int>> bridge;

int map[101][101];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool visited_sea[101][101] = { false };

// 섬의 개수를 세는 함수
int countland()
{
	queue<pair<int, int>> land;
	bool visited_land[101][101] = { false };

	int num = 0;
	// 섬 개수 세기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] && !visited_land[i][j]) {
				num++;
				visited_land[i][j] = true;
				map[i][j] = num;
				land.push(make_pair(i, j));

				while (!land.empty())
				{
					int qsz = land.size();

					while (qsz--)
					{
						int x = land.front().first;
						int y = land.front().second;
						land.pop();

						for (int k = 0; k < 4; k++)
						{
							int mx = x + dx[k];
							int my = y + dy[k];

							if (mx < 0 || mx >= N || my < 0 || my >= N) continue;

							// 섬의 개수 세기 map이 0이 아니고 방문하지 않았던 것 push
							if (!map[mx][my] || visited_land[mx][my]) continue;
							visited_land[mx][my] = true;
							map[mx][my] = num;
							land.push(make_pair(mx, my));
						}
					}
				}
			}
		}
	}
	return num;
}

// 다리를 연결하는 함수
int bfs()
{
	int temp[101][101];
	memcpy(temp, map, sizeof(temp));
	int count = 0;
	int ret_land = -1;
	while (!bridge.empty())
	{
		if (ans < count) { count = -1; break; }
		if ((ret_land < init_land) && ret_land > 0)  break;

		int qsz = bridge.size();

		while (qsz--)
		{
			int x = bridge.front().first;
			int y = bridge.front().second;
			map[x][y] = 1;
			bridge.pop();

			for (int k = 0; k < 4; k++)
			{
				int mx = x + dx[k];
				int my = y + dy[k];

				if (mx < 0 || mx >= N || my < 0 || my >= N) continue;

				// 다리 놓기
				if (map[mx][my] || visited_sea[mx][my]) continue;
				visited_sea[mx][my] = true;
				bridge.push(make_pair(mx, my));
			}
		}
		// 섬의 개수 세기
		ret_land = countland();
		count++;
	}
	memcpy(map, temp, sizeof(temp));
	return count;
}

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	// 클러스터링
	init_land = countland();

	// 탐색
	for (int land_num = 1; land_num <= init_land; land_num++)
	{
		memset(visited_sea, false, sizeof(visited_sea));

		if (!bridge.empty())
		{
			while (!bridge.empty()) bridge.pop();
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] == land_num)
				{
					for (int k = 0; k < 4; k++)
					{
						int mx = i + dx[k];
						int my = j + dy[k];

						// 섬과 닿아 있는 0 넣기
						if (mx < 0 || mx >= N || my < 0 || my >= N) continue;
						if (map[mx][my] || visited_sea[mx][my]) continue;
						// 섬이 아니고 방문하지 않았던 곳
						visited_sea[mx][my] = true;
						bridge.push(make_pair(mx, my));
					}
				}
			}
		}
		// 탐색 시작.
		int ret = bfs();

		if (ans > ret && ret > 0) ans = ret;

	}
	cout << ans;

	return 0;
}
