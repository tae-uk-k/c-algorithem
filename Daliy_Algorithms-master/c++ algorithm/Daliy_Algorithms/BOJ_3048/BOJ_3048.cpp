// 백준알고리즘 3048번 :: 개미
#include<iostream>
using namespace std;

struct info{
	int dir;
	char alpha;
};
int N1, N2, T;
struct info ans[27];

int main()
{
	char ant = 0;
	cin >> N1 >> N2;
	for (int i = 0; i < N1; i++) {
		cin >> ant;
		ans[N1-1 -i] = { 0, ant };
	}

	for (int i = N1; i < N1+N2; i++) {
		cin >> ant;
		ans[i] = { 1, ant };
	}
	
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < N1 + N2 - 1; j++)
		{
			if (ans[j].dir != ans[j + 1].dir && ans[j].dir == 0)
			{
				struct info temp = ans[j];
				ans[j] = ans[j + 1];
				ans[j + 1] = temp;
				j++;
			}
		}
	}

	for (int i = 0; i < N1 + N2; i++)
		cout << ans[i].alpha;
	
	return 0;
}
