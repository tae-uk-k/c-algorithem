// 백준알고리즘 1986번 :: 체스
#include<iostream>
#include<queue>
using namespace std;

int n, m;
int block[1010][1010];
int ans[1010][1010];
int ret = 0;

// 상 하 좌 우 대각왼위 대각오위 대각왼아래 대각오아래
int qdx[8] = {-1,1,0,0,-1,-1,1,1};
int qdy[8] = {0,0,-1,1,-1,1,-1,1};

int kdx[8] = {2,2,1,1,-1,-1,-2,-2};
int kdy[8] = {1,-1,2,-2,2,-2,1,-1};

queue<pair<int, int>> knight;
queue<pair<int, int>> queen;

void knight_simulate()
{
	while (!knight.empty())
	{
		int kx = knight.front().first;
		int ky = knight.front().second;
		knight.pop();

		for (int i = 0; i < 8; i++)
		{
			int mkx = kx + kdx[i];
			int mky = ky + kdy[i];

			if (mkx < 1 || mkx > n || mky < 1 || mky > m) continue;
			if (block[mkx][mky]) continue;
			else
			{
				if (!ans[mkx][mky]) {
					ans[mkx][mky] = 1;
					ret++;
				}
			}
		}
	}
	return;
}

void queen_simulate()
{
	while (!queen.empty())
	{
		int qx = queen.front().first;
		int qy = queen.front().second;
		queen.pop();

		for (int i = 0; i < 8; i++)
		{
			int mqx = qx + qdx[i];
			int mqy = qy + qdy[i];

			while (1)
			{
				if (mqx < 1 || mqx > n || mqy < 1 || mqy > m) break;

				if (block[mqx][mqy]) break;
				else
				{
					if (!ans[mqx][mqy]) {
						ans[mqx][mqy] = 1;
						ret++;
					}
				}
				mqx += qdx[i];
				mqy += qdy[i];
			}
		}
	}
	return;
}

int main(void)
{
	int num = 0;
	int x, y;

	cin >> n >> m;

	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> x >> y;
		block[x][y] = 1;
		ans[x][y] = 1;
		ret++;
		queen.push(make_pair(x, y));
	}
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> x >> y;
		block[x][y] = 1;
		ans[x][y] = 1;
		ret++;
		knight.push(make_pair(x, y));
	}
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> x >> y;
		block[x][y] = 1;
		ret++;
		ans[x][y] = 1;
	}

	queen_simulate();
	knight_simulate();

	cout << n*m - ret;

	return 0;
}
