// 백준알고리즘 1932번 :: 정수삼각형
#include<iostream>
using namespace std;
#define max(a,b) (a > b) ? a : b
int n, ans;
int arr[502][502];

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0) arr[i][j] += arr[i-1][j];
			else if (j == i) arr[i][j] += arr[i - 1][j - 1];
			else arr[i][j] += max(arr[i - 1][j], arr[i - 1][j - 1]);
		}
	}

	ans = arr[n - 1][0];
	for (int i = 1; i < n; i++)
	{
		if (ans < arr[n - 1][i]) ans = arr[n - 1][i];
	}

	cout << ans;

	return 0;
}
