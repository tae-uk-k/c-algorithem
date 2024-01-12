// 백준알고리즘 11659번 :: 구간 합 구하기4
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int arr[100001];
int psum[100001];
int main(void)
{
	int N, M, i, start, end, ans = 0;
	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
		ans += arr[i];
		psum[i] = ans;
	}

	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &start, &end);
		printf("%d\n", psum[end] - psum[start-1]);
	}

	return 0;
}
