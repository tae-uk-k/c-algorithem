// 백준알고리즘 16234번 :: 인구 이동
#include<iostream>
#include<queue>
using namespace std;

int N, L, R, ans;

bool flag = false;
int A[51][51];
int visited[51][51];
int group[2502];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

queue<pair<int, int>> q;
vector<int> v;

// 국경선을 열고 연합하는 그룹만들기
void bfs(int _x, int _y, int _g)
{
	visited[_x][_y] = _g;
	int sum = 0;
	int Nsum = 0;

	q.push(make_pair(_x, _y));

	while (!q.empty())
	{
		int qsz = q.size();
		while (qsz--)
		{
			int x = q.front().first;
			int y = q.front().second;
			sum += A[x][y];
			Nsum++;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int mx = x + dx[i];
				int my = y + dy[i];

				if (mx < 0 || mx >= N || my < 0 || my >= N) continue;
				if (visited[mx][my]) continue;
				if ((abs(A[x][y] - A[mx][my]) < L) || (abs(A[x][y] - A[mx][my]) > R)) continue;
				visited[mx][my] = _g;
				q.push(make_pair(mx, my));
				flag = true;
			}
		}
	}
	// 국경선을 한 번이라도 열었을 때, 그룹을 만들고 대체할 값을 저장해둔다.
	if (flag)
	{
		int nvalue = sum / Nsum;
		group[_g] = nvalue;
	}
	// 국경선을 연 적이 없다면, 방문여부를 다시 표시한다.
	else
		visited[_x][_y] = 0;
	return;
}
int main(void)
{
	cin >> N >> L >> R;


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> A[i][j];
	}

	while (1)
	{
		// 인구이동을 위한 탐색을 시작할 때, flag와 visited 배열을 초기화한다. 
		flag = false;
		memset(visited, 0, sizeof(visited));
		
		int g = 1;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visited[i][j] == 0) {
					bfs(i, j, g);
					if(flag)g++;
				}
			}
		}
		// 인구수가 갱신될 수 없으면 종료한다.
		if (!flag) break;

		// 그룹에 따른 인구수 갱신
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visited[i][j])
					A[i][j] = group[visited[i][j]];
			}
		}
		// 모든 국가를 탐색하고 인구수를 갱신한 후, 인구 이동 횟수를 증가시킨다.
		ans++;
	}
	cout << ans;

	return 0;
}
