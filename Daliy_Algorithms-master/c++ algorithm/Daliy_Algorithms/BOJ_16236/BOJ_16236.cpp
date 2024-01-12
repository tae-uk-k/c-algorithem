// 백준알고리즘 16236번 :: 아기 상어
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct shark_info
{
	int x; // x좌표
	int y; // y좌표
	int size_shark; // 아기 상어의 크기
	int howmanyeat; // 얼만큼 더 먹어야 크기가 갱신되는가
	int psum; // 누적 상어
	int time; // 시간
	int caneat; // 먹을 수 있는 상어인가

}typedef SHARK;

int N;
int ans;
queue<SHARK>q;
int fishbowl[21][21];
int visited[21][21][400];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool cmp(const SHARK& a, const SHARK& b) {
	if (a.x == b.x)
	{
		return a.y < b.y;
	}
	else return a.x < b.x;
}

void selectpos(int _cnt)
{
	vector<SHARK>v;
	SHARK shark = { 0 };
	while (!q.empty()) {
		shark = q.front();
		if(shark.caneat == 1) v.push_back(shark);
		q.pop();
	}
	sort(v.begin(), v.end(), cmp);
	if (v[0].size_shark == v[0].howmanyeat + 1)
	{
		v[0].size_shark++;
		v[0].howmanyeat = 0;
	}
	else v[0].howmanyeat++;
	
	v[0].psum++;
	v[0].caneat = 0;
	fishbowl[v[0].x][v[0].y] = 0;
	q.push(v[0]);
	ans = v[0].time;

	return;
}

void bfs()
{
	while (!q.empty())
	{
		int qsz = q.size();
		int cnt = 0;

		while(qsz--)
		{
			SHARK shark = q.front();
			int x = shark.x;
			int y = shark.y;
			int shark_size = shark.size_shark;
			int psum = shark.psum;
			int time = shark.time;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int mx = x + dx[i];
				int my = y + dy[i];
				int caneat = 0;

				if (mx < 0 || mx >= N || my < 0 || my >= N) continue;
				if (fishbowl[mx][my] > shark_size) continue;
				if (visited[mx][my][psum]) continue;
				if (fishbowl[mx][my] > 0 && fishbowl[mx][my] < shark_size)
				{
					// 먹을 수 있는 상어
					caneat = 1;
					cnt++;
				}
				shark.x = mx; shark.y = my; shark.caneat = caneat; shark.time = time+1;
				visited[mx][my][psum] = 1;
				q.push(shark);
			}
		}
		// 먹을 수 있는 상어가 1마리 이상 있다.
		// 1마리인 경우, 그 위치만 남긴다.
		// 2마리 이상인 경우, x좌표와 y좌표로 판단하여 하나만 남긴다.
		if (cnt != 0)
		{
			selectpos(cnt);
			visited[q.front().x][q.front().y][q.front().howmanyeat] = 1;
		}
	}
	return;
}

int main()
{
	cin >> N;

	SHARK shark = { 0, 0, 2, 0, 0, 0 };

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> fishbowl[i][j];
			if (fishbowl[i][j] == 9)
			{
				shark.x = i;
				shark.y = j;
				q.push(shark);
				fishbowl[i][j] = 0;
				visited[i][j][0] = 1;
			}
		}
	}

	bfs();

	cout << ans;

	return 0;
}
