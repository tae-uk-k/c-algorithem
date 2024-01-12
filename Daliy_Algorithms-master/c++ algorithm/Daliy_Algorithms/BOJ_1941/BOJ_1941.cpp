// 백준알고리즘 1841번 :: 소문난 칠공주
#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
#define MAX 5

int ans;
char map[MAX][MAX];
int visited[MAX][MAX];
vector<pair<int, int>>v;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs(int standard)
{
	queue <pair<int, int>> q;
	int lvisited[MAX][MAX] = { 0 };
	int x = v[standard].first;
	int y = v[standard].second;

	lvisited[x][y] = 1;
	q.push(make_pair(x,y));
	int num = 1;
	int snum = 0;
	if (map[x][y] == 'S') snum++;

	while (!q.empty())
	{
		int qsz = q.size();
		
		while (qsz--)
		{
			int qx = q.front().first;
			int qy = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int mx = qx + dx[i];
				int my = qy + dy[i];

				if (mx < 0 || mx >= MAX || my < 0 || my >= MAX) continue;
				if (visited[mx][my] == 0 || lvisited[mx][my] == 1) continue;
				if (map[mx][my] == 'S') snum++;
				lvisited[mx][my] = 1;
				q.push(make_pair(mx, my));
				num++;
			}
		}
	}
	if (num == 7 && snum >= 4) {
		ans++;
	}
	return;
}

// idx는 v 탐색시작 인덱스
void brute(int _idx, int _count)
{
	// 7명을 모두 체크하였으면 확인
	// 7명이 연결되지 않았으면 fail
	// S가 4이상이 아니면 fail
	// 7명이 모두 연결되었고 S가 4이상이면 ans++
	if (_count == 7)
	{
		bfs(_idx - 1);
		return;
	}

	for (int i = _idx; i < MAX*MAX; i++)
	{
		int x = v[i].first;
		int y = v[i].second;
		visited[x][y] = 1;
		brute(i + 1, _count+1);
		visited[x][y] = 0;		
	}
}
int main(void)
{
	string str;
	for (int i = 0; i < MAX; i++)
	{
		cin >> str;
		for (int j = 0; j < MAX; j++)
		{
			map[i][j] = str[j];
			v.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < MAX*MAX - 6; i++)
	{
		int x = v[i].first;
		int y = v[i].second;
		visited[x][y] = 1;
		brute(i + 1, 1);
		visited[x][y] = 0;
	}

	cout << ans;

	return 0;
}
