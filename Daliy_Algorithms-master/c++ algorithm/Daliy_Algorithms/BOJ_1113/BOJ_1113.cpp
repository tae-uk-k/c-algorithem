// 백준알고리즘 1113번 :: 수영장 만들기
#include<iostream>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
int N, M, ans;
int height = 0;
bool flag, clustering = false;
int visited[51][51];
int pool[51][51];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void bfs(int _x, int _y)
{
	queue <pair<int, int >> q;
	int tmp[51][51] = { 0 };
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			tmp[i][j] = visited[i][j];
	visited[_x][_y] = 1;
	q.push(make_pair(_x, _y));
	flag = false;
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
				// 수영장 안을 벗어나면 continue
				// flag = true 군집화 할 수 없다.
				if (mx < 0 || mx > N - 1 || my < 0 || my > M - 1) {
					flag = true;
					break;
				}
				// 이미 군집화된 곳이면 continue
				if (visited[mx][my]) continue;
				// 높으면 continue
				if (pool[mx][my] > height) continue;
				// 같으면 visited = true
				visited[mx][my] = 1;
				q.push(make_pair(mx, my));
			}
			// 군집화 할 수 없다.
			if (flag)
			{
				for (int i = 0; i < N; i++)
					for (int j = 0; j < M; j++)
						visited[i][j] = tmp[i][j];
				break;
			}
		}
		if (flag) break;
	}
	if (!flag) clustering = true;
	return;
}
int main(void)
{
	cin >> N >> M;
	
	string str;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			pool[i][j] = str[j]- '0';
		}
	}
	while(1)
	{
		height++;
		// 9까지 채웠을 때 종료
		if (height == 9) break;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (visited[i][j] == 0 && pool[i][j] == height)
				{
					bfs(i,j);
				}
			}
		}
		if (clustering)
		{
			// 물을 1 채우고 visited를 초기화한다.
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					pool[i][j] += visited[i][j];
					if (visited[i][j]) ans++;
				}
			}
			memset(visited, 0, sizeof(visited));
		}
		clustering = false;
	}
	cout << ans;
	return 0;
}
