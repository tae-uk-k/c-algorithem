// 백준알고리즘 1107 :: 리모컨
#include<iostream>
#include<string>
using namespace std;
int N;
int dest;
int len_dest;
int start = 100;
int ans = 1000000;
int num[7] = { 0 };
int disnum[10];
// pos : 몇 자리 수인지
int arrtonum(int pos)
{
	int ret = 0;
	for (int i = 0; i < pos; i++)
		ret = ret*10 + num[i];
	return ret;
}
// p자리까지 채워야 한다.
// idx 자리를 채워야 할 차례이다.
void fillnum(int p, int idx)
{
	// p자리까지 채웠다.ans 갱신
	if (idx == p)
	{
		int n = arrtonum(p);
		int lans = abs(dest - n)+p;
		if (ans > lans)	ans = lans;
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		if (disnum[i]) continue;
		num[idx] = i;
		fillnum(p, idx+1);
		// 이 구문을 넣었을 때가 오히려 4ms가 절약된다. 왜지..?
		num[idx] = 0;
	}
	return;
}
int main(void)
{
	string str;
	cin >> str;
	len_dest = str.length();
	dest = stoi(str);
	cin >> N;
	int data = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> data;
		disnum[data] = 1;
	}
	// 시작과 목적 채널이 같다.
	if (dest == 100) {
		cout << 0;
		return 0;
	}
	// 모든 숫자 버튼을 다 누를 수 있다. => 숫자 버튼으로 목적 채널을 누르는 것과 (+) / (-) 로 현재 채널에서 이동하는 것을 비교
	else if (N == 0) ans = len_dest;
	// 0만 누를 수 있다. => 0을 누르고 목적 채널로 이동하는 것과 (+) / (-) 로 현재 채널에서 이동하는 것을 비교
	else if (disnum[0] == 0 && N == 9) ans = 1 + dest;
	else
	{
		int idx = 0;
		// 0을 눌렀을 때
		if (disnum[0] == 0) ans = dest + 1;
		// 자릿수가 목적 채널보다 1 작은 채널부터 시작한다.
		int l = len_dest;
		if (l == 1) l = 2;
		// 1자리에서 7자리까지 채우기
		// 맨 앞은 0을 넣을 수 없다.
		for (int p = l-1; p < 8; p++)
		{
			// 자릿수가 목적 채널보다 2개 많은 채널로 이동할 필요가 없다.
			if (len_dest < p-1) break;
			for (int i = 1; i < 10; i++)
			{
				// 이 구문을 넣었을 때, 약 20ms가 절약되었다.
				if (disnum[i])continue;
				num[idx] = i;
				// 한 자리만 채우면 된다.
				if (p == 1)
				{
					int n = arrtonum(p);
					int lans = abs(dest - n)+p;
					if (ans > lans) ans = lans;
					continue;
				}
				fillnum(p, idx+1);
			}
		}
	}
	// ans와 (+) / (-) 로 현재 채널에서 이동하는 것을 비교한다.
	int movechannel = abs(dest - start);
	if (ans > movechannel) ans = movechannel;
	cout << ans;
	
	return 0;
}
