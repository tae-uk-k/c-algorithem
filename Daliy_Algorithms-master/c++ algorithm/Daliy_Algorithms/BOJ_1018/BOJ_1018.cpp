// 백준알고리즘 1018번 :: 체스판 다시 칠하기
#include<iostream>
#include<string>
using namespace std;

int N, M;
int ans = -1;
char board[51][51];
char color[2] = { 'B', 'W' };

int main(void)
{
	string str;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			board[i][j] = str[j];
		}
	}

	// B로 시작 혹은 W로 시작
	for (int c = 0; c < 2; c++)
	{
		// 시작 x인덱스
		for (int sx = 0; sx < (N - 8 + 1); sx++)
		{
			// 시작 y인덱스
			for (int sy = 0; sy < (M - 8 + 1); sy++)
			{
				int cnt = 0;

				// board를 탐색하며 count
				for (int i = sx; i < sx + 8; i++)
				{
					for (int j = sy; j < sy + 8; j++)
					{
						if (board[i][j] != color[(i + j + c) % 2]) cnt++;
					}
				}
				// ans 갱신
				if (ans > cnt || ans == -1) ans = cnt;
			}
		}
	}

	cout << ans;

	return 0;
}
