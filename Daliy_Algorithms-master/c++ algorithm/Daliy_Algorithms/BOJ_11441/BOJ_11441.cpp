// 백준알고리즘 11441번 :: 합 구하기
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int psum[100001];
int main(void)
{
	int N, M, i, start, end, ans = 0;
	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		scanf("%d", &ans);
		psum[i] = psum[i-1] + ans;
	}
	scanf("%d", &M);
	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &start, &end);
		printf("%d\n", psum[end] - psum[start-1]);
	}

	return 0;
}
