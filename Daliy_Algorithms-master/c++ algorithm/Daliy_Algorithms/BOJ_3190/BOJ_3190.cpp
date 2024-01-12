// 백준알고리즘 3190번 :: 뱀
#include<iostream>
#include<vector>
using namespace std;

int N, K;
bool board[101][101];
int X[10001][2]; // 0 왼쪽,  1 오른쪽
vector<pair<int, int>> snake;

// 오른쪽부터 시계방향.. 우 하 좌 상
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

// 뱀의 머리와 뱀의 몸 겹치면 TRUE 반환
bool crash()
{
	int size = snake.size() -1;
	int x = snake[size].first;
	int y = snake[size].second;

	for (int i = 0; i < size; i++)
	{
		if (snake[i].first == x && snake[i].second == y) return true;
	}
	return false;
}

int main(void)
{
	int applex, appley, ndir, chtime = 0, time = 1;
	char chdir = 0;
	int sx = 1, sy = 1;
	cin >> N >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> applex >> appley;
		board[applex][appley] = true;
	}
	snake.push_back(make_pair(sx, sy)); // 1,1

	cin >> ndir;

	for (int i = 0; i < ndir; i++)
	{
		cin >> chtime >> chdir;
		if (chdir == 'L') X[chtime][0] = true;
		else X[chtime][1] = true;
	}

	bool flag = false;
	int dir = 0;
	
	// 벽에 부딪혔을 때, 자기 몸에 부딪혔을 때 종료 
	while (1)
	{
		sx += dx[dir];
		sy += dy[dir];
		snake.push_back(make_pair(sx, sy));

		// 다음에 갈 방향 확인
		if (X[time][0]) dir = (dir + 3) % 4;
		else if (X[time][1]) dir = (dir + 1) % 4;

		// 벽에 부딪혔다 break
		if (sx <= 0 || sx > N || sy <= 0 || sy > N) break;

		// 자기 몸에 부딪혔다 break
		flag = crash();
		if (snake.size() >= 4 && flag) break;

		// 사과 존재 여부
		if (!board[sx][sy]) snake.erase(snake.begin());
		else if(board[sx][sy]) board[sx][sy] = false;

		time++;
	}

	cout << time;
	
	return 0;
}
