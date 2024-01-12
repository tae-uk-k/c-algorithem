// 백준알고리즘 2163번 :: 초콜릿 자르기
#include<iostream>
using namespace std;

int N, M, ans;

int main(void)
{
	cin >> N >> M;
	ans = N*M - 1;
	cout << ans;
	return 0;
}
