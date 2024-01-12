// 백준알고리즘 15683번 :: 감시
#include<iostream>
#include<queue>
using namespace std;
struct CCTV
{
	int x;
	int y;
	int CTNUM;
};
int N, M;
int office[9][9];
struct CCTV CCTV[9];
int ans = -1;
int direct[6] = { 0,4,2,4,4,1 };
int rot[6] = { 0,1,2,2,3,4 };
// 상 우 하 좌
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int count_office()
{
	int value = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!office[i][j]) value++;
		}
	}
	return value;
}
void monitor(int _idx, int _num)
{
	int cctv_num = CCTV[_idx].CTNUM; // cctv 번호
	int rot_cnt = rot[cctv_num]; // cctv 번호에 따른 회전 횟수
	int mx = 0;
	int my = 0;
	int dir = 0; // 방향
	for (int i = 0; i < rot_cnt; i++)
	{
		// cctv_num, _num, i
		// _num : 몇 번 돌려야 하는지, i : 몇 방향 감시할 수 있는지
		if (cctv_num == 1 && _num == 0) dir = 1;
		else if (cctv_num == 1 && _num == 1) dir = 2;
		else if (cctv_num == 1 && _num == 2) dir = 3;
		else if (cctv_num == 1 && _num == 3) dir = 0;
		else if (cctv_num == 2 && _num == 0 && i == 0) dir = 1;
		else if (cctv_num == 2 && _num == 0 && i == 1) dir = 3;
		else if (cctv_num == 2 && _num == 1 && i == 0) dir = 0;
		else if (cctv_num == 2 && _num == 1 && i == 1) dir = 2;
		else if (cctv_num == 3 && _num == 0 && i == 0) dir = 0;
		else if (cctv_num == 3 && _num == 0 && i == 1) dir = 1;
		else if (cctv_num == 3 && _num == 1 && i == 0) dir = 1;
		else if (cctv_num == 3 && _num == 1 && i == 1) dir = 2;
		else if (cctv_num == 3 && _num == 2 && i == 0) dir = 2;
		else if (cctv_num == 3 && _num == 2 && i == 1) dir = 3;
		else if (cctv_num == 3 && _num == 3 && i == 0) dir = 3;
		else if (cctv_num == 3 && _num == 3 && i == 1) dir = 0;
		else if (cctv_num == 4 && _num == 0 && i == 0) dir = 3;
		else if (cctv_num == 4 && _num == 0 && i == 1) dir = 0;
		else if (cctv_num == 4 && _num == 0 && i == 2) dir = 1;
		else if (cctv_num == 4 && _num == 1 && i == 0) dir = 0;
		else if (cctv_num == 4 && _num == 1 && i == 1) dir = 1;
		else if (cctv_num == 4 && _num == 1 && i == 2) dir = 2;
		else if (cctv_num == 4 && _num == 2 && i == 0) dir = 1;
		else if (cctv_num == 4 && _num == 2 && i == 1) dir = 2;
		else if (cctv_num == 4 && _num == 2 && i == 2) dir = 3;
		else if (cctv_num == 4 && _num == 3 && i == 0) dir = 2;
		else if (cctv_num == 4 && _num == 3 && i == 1) dir = 3;
		else if (cctv_num == 4 && _num == 3 && i == 2) dir = 0;
		else if (cctv_num == 5 && _num == 0 && i == 0) dir = 0;
		else if (cctv_num == 5 && _num == 0 && i == 1) dir = 1;
		else if (cctv_num == 5 && _num == 0 && i == 2) dir = 2;
		else if (cctv_num == 5 && _num == 0 && i == 3) dir = 3;
		mx = CCTV[_idx].x + dx[dir];
		my = CCTV[_idx].y + dy[dir];
		while (1)
		{
			if (mx < 0 || mx >= N || my < 0 || my >= M) break;
			if (office[mx][my] == 6) break;
			if (office[mx][my] == 0) office[mx][my] = -1;
			mx += dx[dir];
			my += dy[dir];
		}
	}
}
void search(int idx)
{
	if (idx < 0)
	{
		int value = count_office();
		if (ans == -1 || ans > value) {
			ans = value;
		}
		return;
	}
	int temp[9][9];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			temp[i][j] = office[i][j];
	// CCTV[idx]번 cctv로 감시할 수 있는 칸을 감시한다.
	// office에 갱신한다.
	int cctv_num = CCTV[idx].CTNUM;
	for (int i = 0; i < direct[cctv_num]; i++)
	{
		monitor(idx, i);
		search(idx - 1);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				office[i][j] = temp[i][j];
	}
}
int main(void)
{
	cin >> N >> M;
	int idx = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> office[i][j];
			if (office[i][j] >= 1 && office[i][j] <= 5)
			{
				CCTV[idx].CTNUM = office[i][j];
				CCTV[idx].x = i;
				CCTV[idx].y = j;
				idx++;
			}
		}
	}
	search(idx-1);
	cout << ans;
}
