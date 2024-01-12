// 백준알고리즘 2805번 :: 나무 자르기
#include<iostream>
using namespace std;
int N, M;
int tree[1000001];
// standard로 잘랐을 때의 가져갈 수 있는 나무길이의 합 구하는 함수
long long calc(int standard)
{
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		long long available = tree[i] - standard;
		if (available > 0) sum += available;
	}
	return sum;
}
// 절단기에 설정할 수 있는 높이의 최댓값 구하는 함수(이분 탐색)
long long find(int start, int end)
{
	while (1)
	{
		long long middle = (start + end) / 2;
		long long ret = calc(middle);
		if (ret == M) return middle;
		if (start > end) return end;
		// ret가 M보다 작으면 더 밑을 잘라야 한다.
		if (ret < M)
		{
			end = middle - 1;
		}
		// ret가 M보다 크거나 같으면 위를 잘라야 한다.
		else
		{
			start = middle + 1;
		}
	}
}
int main()
{
	long long max_value = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> tree[i];
		if (max_value < tree[i]) max_value = tree[i];
	}
	// 0 부터 나무 최대높이 사이에서 답 구하기
	long long ans = find(0, max_value);
	cout << ans;
	return 0;
}
