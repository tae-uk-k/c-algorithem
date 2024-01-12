// 백준알고리즘 1938번 :: 통나무 옮기기
#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;
int N, ans, edir;
bool flag;
vector <pair<int, int>> start[3];
vector <pair<int, int>> eend[3];
queue<pair<pair<int, int>, int>> loc;
int map[51][51];
int visited[51][51][2];
//  U D L R UL UR DL DR
int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1};
void bfs()
{
	while (!loc.empty())
	{
		int qsz = loc.size();
		while (qsz--)
		{
			int x = loc.front().first.first;
			int y = loc.front().first.second;
			int d = loc.front().second;
			loc.pop();
			if (x == eend[1].front().first && y == eend[1].front().second && d == edir) {
				flag = true;
				return;
			}
			for (int i = 0; i < 4; i++)
			{
				int mx = x + dx[i];
				int my = y + dy[i];
				// 가로모양
				if (d == 0)
				{
					if (mx < 0 || mx >= N || my < 1 || my >= N - 1) continue;
					if (map[mx][my - 1] || map[mx][my] || map[mx][my + 1]) continue;
				}
				// 세로모양
				else
				{
					if (mx < 1 || mx >= N-1 || my < 0 || my >= N) continue;
					if (map[mx - 1][my] || map[mx][my] || map[mx + 1][my]) continue;
				}
				if (visited[mx][my][d]) continue;
				visited[mx][my][d] = 1;
				loc.push(make_pair(make_pair(mx, my), d));
			}
			for (int i = 0; i < 8; i++)
			{
				int mx = x + dx[i];
				int my = y + dy[i];
				if (mx < 0 || mx >= N || my < 0 || my >= N) {
					flag = 1; break;
				}
				if (map[mx][my]) {
					flag = 1;  break;
				}
			}
			if (!flag) {
				int md = (d + 1) % 2;
				if (!visited[x][y][md]) {
					visited[x][y][md] = 1;
					loc.push(make_pair(make_pair(x, y), md));
				}
			}
			flag = false;
		}
		ans++;
	}
	return;
}
int main(void)
{
	string str;
	cin >> N;
	int sidx = 0, eidx = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < N; j++)
		{
			map[i][j] = str[j];
			if (map[i][j] == '0' || map[i][j] == '1') map[i][j] -= '0';
			else
			{
				if (map[i][j] == 'B') start[sidx++].push_back(make_pair(i, j));
				else if (map[i][j] == 'E') eend[eidx++].push_back(make_pair(i, j));
				map[i][j] = 0;
			}
		}
	}
	int sdir = 0;
	// 가로모양 0
	if (start[0].front().first == start[1].front().first) sdir = 0;
	// 세로모양 1
	else sdir = 1;
	// 가로모양 0
	if (eend[0].front().first == eend[1].front().first) edir = 0;
	// 세로모양 1
	else edir = 1;
	visited[start[1].front().first][start[1].front().second][sdir] = 1;
	loc.push(make_pair(make_pair(start[1].front().first, start[1].front().second), sdir));
	bfs();
	if(flag) cout << ans;
	else cout << "0";
	return 0;
}
