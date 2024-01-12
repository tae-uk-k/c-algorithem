// 백준알고리즘 11660번 :: 구간 합 구하기5
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int psum[1025][1025];
int main(void)
{
	int N, M, i,j, sx, sy, ex ,ey, val = 0;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &val);
			if (i == 1) psum[i][j] = psum[i][j-1] + val;
			else if (j == 1) psum[i][j] = psum[i-1][j] + val;
			else psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + val;
		}
	}
	for (i = 0; i < M; i++)
	{
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
		printf("%d\n", psum[ex][ey] - psum[ex][sy-1]- psum[sx-1][ey] + psum[sx-1][sy-1]);
	}
	return 0;
}
