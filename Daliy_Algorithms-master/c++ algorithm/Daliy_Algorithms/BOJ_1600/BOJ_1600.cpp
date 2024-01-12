// 백준알고리즘 1600번 :: 말이 되고픈 원숭이
#include<iostream>
#include<queue>
using namespace std;

int W, H, K, ans;
bool flag;
int grid[201][201];
// 방문 여부 [x좌표][y좌표][말같이 움직인 횟수]
int visited[201][201][31];
queue<pair<pair<int, int>,int>> monkey;

// 말의 이동방식
int dh[8][2] = { {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1} };
// 원숭이의 이동방식
int dm[4][2] = { {0,1}, {0, -1}, {1, 0}, {-1,0} };

void bfs()
{
	while (!monkey.empty())
	{
		int qsz = monkey.size();
		while (qsz--)
		{
			int x = monkey.front().first.first;
			int y = monkey.front().first.second;
			int count = monkey.front().second;
			monkey.pop();

			if (x == H - 1 && y == W - 1)
			{
				flag = 1;
				return;
			}

			// K번 보다 적게 말같이 움직였으면, 지금 말같이 움직일 수 있다.
			if (count < K)
			{
				for (int i = 0; i < 8; i++)
				{
					int mx = x + dh[i][0];
					int my = y + dh[i][1];
					int mcount = count + 1;

					if (mx < 0 || mx >= H || my < 0 || my >= W) continue;
					if (grid[mx][my] || visited[mx][my][mcount]) continue;
					visited[mx][my][mcount] = 1;
					monkey.push(make_pair(make_pair(mx, my), mcount));
				}
			}

			for (int i = 0; i < 4; i++)
			{
				int mx = x + dm[i][0];
				int my = y + dm[i][1];
				int mcount = count;

				if (mx < 0 || mx >= H || my < 0 || my >= W) continue;
				if (grid[mx][my] || visited[mx][my][mcount]) continue;
				visited[mx][my][mcount] = 1;
				monkey.push(make_pair(make_pair(mx, my), mcount));
			}
		}
		ans++;
	}
	return;
}

int main(void)
{
	cin >> K >> W >> H;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> grid[i][j];
		}
	}

	visited[0][0][0] = 1;
	monkey.push(make_pair(make_pair(0, 0), 0));

	bfs();

	if (flag) cout << ans;
	else cout << "-1";

	return 0;
}
