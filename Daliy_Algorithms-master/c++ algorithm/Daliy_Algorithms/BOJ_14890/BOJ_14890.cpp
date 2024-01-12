// 백준알고리즘 14890번 :: 경사로
#include<iostream>
using namespace std;

int N, L;
int board[101][101];
int dx[2] = {1,0};
int dy[2] = {0,1};
int ans = 0;

void search(int x, int  y, int dir)
{
	int _x = x;
	int _y = y;
	bool flag = true;
	int value = 0;
	int len = 1;

	while (1)
	{
		value = board[x][y];

		int mx = x + dx[dir];
		int my = y + dy[dir];
		int mvalue = board[mx][my];

		if (mx >= N || my >= N) {
			if (flag) ans++;
			break;
		}
		// 차이가 2상이면, break;
		if (abs(value - mvalue) > 1) break;
		// 차이가 1이면, check
		if (abs(value - mvalue) == 1)
		{
			// 내려가는 경사로
			if (value > mvalue) {
				if (L == 1) len = 0;
				else if (!flag) break;
				else {
					flag = !flag;
					len = 1;
				}
			}
			// 올라가는 경사로
			else if (mvalue > value)
			{
				if (len >= L) len = 1;
				else break;
			}
		}
		// 차이가 0이면
		else if (value == mvalue)
		{
			len++;
			if (len == L && !flag) {
				flag = !flag;
				len = 0;
			}
		}
		x = mx;
		y = my;
	}
}

int main(void)
{
	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		search(0, i, 0);
		search(i, 0, 1);
	}

	cout << ans;

	return 0;
}
