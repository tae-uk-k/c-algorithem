// 백준알고리즘 9663번 :: N-Queen
#include<iostream>
using namespace std;

int N;
int l[30], r[30], u[15], d[15];
int ans = 0;

// 놓을 수 있는 N-Queen의 방법의 수를 구하는 함수
void tracking(int row, int col, int count)
{
	// N개의 queen을 놓았다.
	if (count == N)
	{
		ans++;
		return;
	}
	// 한 행에 queen이 놓여져있지 않거나 체스판의 범위를 넘어갔으면 return
	if (col >= N || row >= N)
		return;

	if (!l[col - row + N - 1] && !r[row + col] && !u[col] && !d[row])
	{
		l[col - row + N - 1] = r[row + col] = u[col] = d[row] = 1;
		tracking(row+1, 0, count + 1);
		l[col - row + N - 1] = r[row + col] = u[col] = d[row] = 0;
	}
	tracking(row, col+1, count);
}

int main(void)
{
	cin >> N;
	tracking(0, 0, 0);
	cout << ans;

	return 0;
}
