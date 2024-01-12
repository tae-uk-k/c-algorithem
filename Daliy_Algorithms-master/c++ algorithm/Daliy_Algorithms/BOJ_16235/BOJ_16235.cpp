// 백준알고리즘 16235번 :: 나무 재테크
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct info
{
	vector<int> old; // 현재 땅에 심어진 나무들의 나이를 담는 벡터
	int tnum; // 현재 땅에 심어진 나무들의 개수
	int food; // 현재 땅의 양분
}typedef INFO;
INFO ground[12][12];
int food_table[12][12];
int N, M, K, ans;
int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
void simulate()
{
	vector<pair<int, int>> v;
	// 봄
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			// 나무가 있으면, 나이가 어린 나무부터 나이만큼 양분을 먹는다.
			// 나이만큼 양분을 먹지 못하면 죽는다.
			if (ground[i][j].tnum != 0)
			{
				v.push_back(make_pair(i, j));
				sort(ground[i][j].old.begin(), ground[i][j].old.end());
				int tnum = ground[i][j].tnum;
				for (int k = 0; k < tnum; k++)
				{
					// 나이만큼 양분을 먹을 수 있다.
					if (ground[i][j].old[k] <= ground[i][j].food)
					{
						ground[i][j].food -= ground[i][j].old[k];
						ground[i][j].old[k]++;
					}
					// 나이만큼 양분을 먹을 수 없다. => 나무가 죽는다
					// 여름
					else
					{
						for (int l = tnum - 1; l >= k; l--) {
							ground[i][j].food += ground[i][j].old[l] / 2;
							ground[i][j].old.pop_back();
						}
						ground[i][j].tnum = k;
						break;
					}
				}
			}
		}
	}
	
	// 가을
	for (int i = 0; i < (int)v.size(); i++)
	{
		int x = v[i].first;
		int y = v[i].second;
		int tnum = ground[x][y].tnum;
		for (int k = 0; k < tnum; k++)
		{
			if (ground[x][y].old[k] % 5 == 0)
			{
				for (int l = 0; l < 8; l++)
				{
					int mx = x + dx[l];
					int my = y + dy[l];
					if (mx < 1 || mx > N || my < 1 || my > N) continue;
					ground[mx][my].old.push_back(1);
					ground[mx][my].tnum++;
				}
			}
		}
	}
	// 겨울
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			ground[i][j].food += food_table[i][j];
		}
	}
}
void findtnum()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			ans += ground[i][j].tnum;
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x = 0, y = 0, z = 0;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			ground[i][j].food = 5;
			ground[i][j].tnum = 0;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> food_table[i][j];
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y >> z;
		ground[x][y].old.push_back(z);
		ground[x][y].tnum++;
	}
	for(int i = 0; i < K; i++)
		simulate();
	findtnum();
	cout << ans;
	return 0;
}
