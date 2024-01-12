// 백준알고리즘 12738번 :: 가장 긴 증가하는 부분 수열 3
#include<iostream>
#include<algorithm>
using namespace std;

int N;
long long ans = 1;
long long num;
long long lis[1000002];

int main()
{
	cin >> N;
	cin >> lis[ans];

	for (int i = 2; i <= N; i++)
	{
		cin >> num;
		if (lis[ans] < num) lis[++ans] = num;
		else
		{
			auto p = lower_bound(lis+1, lis + ans, num);
			*p = num;
		}
	}
	cout << ans;

	return 0;
}
