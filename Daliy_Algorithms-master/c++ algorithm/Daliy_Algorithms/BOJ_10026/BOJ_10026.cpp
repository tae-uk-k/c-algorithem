// 백준알고리즘 10026번 :: 적록색약
#include<iostream>
#include<queue>
#include<string>
#include<string.h>
using namespace std;

int N;
bool flag;
int picture[101][101];
int visited[101][101];
queue<pair<int, int>> q;
int pub;
int npub;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs(int ch)
{
	while (!q.empty())
	{
		int qsz = q.size();
		while (qsz--)
		{
			int x = q.front().first;
			int y = q.front().second;
			int color = picture[x][y];
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int mx = x + dx[i];
				int my = y + dy[i];
				int mcolor = picture[mx][my];

				if (mx < 0 || mx >= N || my < 0 || my >= N) continue;
				if (visited[mx][my]) continue;
				if((flag && (mcolor == 'R' || mcolor == 'G')) || color == mcolor)
				{
					q.push(make_pair(mx, my));
					visited[mx][my] = 1;
				}
			}
		}
	}
	if (ch == 0) pub++;
	else npub++;

	return;
}

int main(void)
{
	string str;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < N; j++)
		{
			picture[i][j] = str[j];
		}
	}

	// 일반인
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j]) {
				q.push(make_pair(i,j));
				bfs(0);
			}
		}
	}

	memset(visited, 0, sizeof(visited));

	// 적록색약인
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j]) {

				if (picture[i][j] == 'R' || picture[i][j] == 'G') flag = true;
				else flag = false;

				q.push(make_pair(i, j));
				bfs(1);
			}
		}
	}
	cout << pub << ' ' << npub;
	return 0;
}
