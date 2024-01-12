// 백준알고리즘 12101번 :: 1, 2, 3 더하기 2
#include<iostream>
using namespace std;

int n, k;
int ans[10];
int cnt;
bool flag = true;

void answer(int _idx)
{
	int i;
	for (i = 0; i < _idx-1; i++)
	{
		cout << ans[i] << '+';
	}
	cout << ans[i];
	return;
}

void dfs(int _idx, int _sum)
{
	if (!flag || _sum > n) return;
	if (n == _sum)
	{
		cnt++;
		if (cnt == k) {
			flag = 0;
			answer(_idx);
		}
		return;
	}
	for (int i = 1; i <= 3; i++)
	{
		ans[_idx] = i;
		dfs(_idx+1, _sum+i);
	}
}
int main(void)
{
	cin >> n >> k;
	
	int idx = 0;
	int length = 0;

	for (int i = 1; i <= 3; i++)
	{
		ans[idx] = i;
		dfs(idx+1, i);
	}

	if (flag) cout << -1;

	return 0;
}
