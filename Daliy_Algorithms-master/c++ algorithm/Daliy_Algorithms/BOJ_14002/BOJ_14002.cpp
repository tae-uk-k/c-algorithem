// 백준알고리즘 14002번 :: 가장 긴 증가하는 부분 수열 4
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

struct info
{
	int len;
	int prev;
}typedef INFO;

int N;
int arr[1001];
INFO lis[1001];

int main()
{
	stack<int> st;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++) {
		lis[i].len = 1;
		lis[i].prev = -1;
		
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && (lis[i].len < lis[j].len + 1))
			{
				lis[i].len = lis[j].len + 1;
				lis[i].prev = j;
			}
		}
	}

	int idx = 0;
	int ans = lis[0].len;
	for (int i = 1; i < N; i++)
	{
		if (ans < lis[i].len) {
			ans = lis[i].len;
			idx = i;
		}
	}
	cout << ans << '\n';

	while (idx != -1)
	{
		st.push(arr[idx]);
		idx = lis[idx].prev;
	}

	while (!st.empty())
	{
		cout << st.top() << ' ';
		st.pop();
	}

	return 0;
}
