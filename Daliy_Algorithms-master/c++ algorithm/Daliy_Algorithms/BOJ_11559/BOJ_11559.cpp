// 백준알고리즘 11559번 :: Puyo Puyo
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;

int ans;
// 연쇄 여부
bool flag = true;
char map[12][6];
int visited[12][6];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0,0,-1,1 };


// 지금 들어간 값과 같고 4개 이상 연결되어 있으면 터진다.
void bfs(int _i, int _j)
{
	queue<pair<int, int>> q;
	queue <pair<int, int>>crush;
	q.push(make_pair(_i, _j));
	crush.push(make_pair(_i, _j));
	visited[_i][_j] = 1;
	int count = 1;
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

			if (mx < 0 || mx >= 12 || my < 0 || my >= 6) continue;
			if (visited[mx][my]) continue;
			if (map[mx][my] != map[x][y]) continue;
			visited[mx][my] = 1;
			q.push(make_pair(mx, my));
			crush.push(make_pair(mx, my));
			count++;
		}
		qsz = q.size();
	}

	if (count >= 4) {
		flag = true;
		// 블록 삭제 -> '.' 으로 바꾸기
		while (!crush.empty())
		{
			map[crush.front().first][crush.front().second] = '.';
			crush.pop();
		}
	}
//	cout << _i << ' ' << _j << ' ' << count << '\n';
	return;
}
int main()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> map[i][j];
		}
	}

	while (1)
	{
		flag = false;
		memset(visited, 0, sizeof(visited));
		for (int i = 11; i >= 0; i--)
		{
			for (int j = 0; j < 6; j++)
			{
				if (map[i][j] != '.' && visited[i][j] != 1)
				{
					bfs(i, j);
				}
			}
		}
		if (!flag) break;
		ans++;

		// 블록 밑으로 내리기
		queue<char> qu;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 11; j >= 0; j--)
			{
				if (map[j][i] != '.')
				{
					qu.push(map[j][i]);
					map[j][i] = '.';
				}
			}
			int standard = 11;
			while (!qu.empty())
			{
				map[standard][i] = qu.front();
				qu.pop();
				standard--;
			}			
		}
	}

	cout << ans;

	return 0;
}
