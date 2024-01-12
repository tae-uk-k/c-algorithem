// 백준 알고리즘 14620번 :: 꽃길
#include<iostream>
#include<vector>
using namespace std;
int N, G;
int ans = -1;
vector<pair<int, int>> available;
int visited[15][15];
int grid[15][15];
// 탐색했을 때 꽃잎이 겹치는 위치
// 아래 세 가지 경우는 하지 않음. 위에서부터 순차적으로 탐색해나가므로 아래에 겹치는 꽃잎은 없다.
int dx[8] = { 0, 0, -1, -1, -2, -1, 0, 0 };
int dy[8] = { -2, -1, -1, 0, 0, 1, 1, 2 };
// 격자에 씨앗을 채워나가는 함수
// start : 앞으로 격자에 놓을 수 있는 씨앗의 맨 처음 위치
// count : 놓은 씨앗의 개수
void fillgrid(int start, int count)
{
	bool flag = false;
	// 씨앗을 3개 놓았을 때, 최소 비용을 갱신한다.
	if (count == 3)
	{
		int price = 0;
		for (int m = 2; m < N+2; m++)
		{
			for (int n = 2; n < N+2; n++)
			{
				if (visited[m][n])
				{
					price += grid[m][n] + grid[m-1][n] + grid[m+1][n] + grid[m][n-1] + grid[m][n+1];
				}
			}
		}
		if (ans > price || ans < 0) ans = price;
		return;
	}
	// 씨앗을 놓을 위치를 결정한다.
	for (size_t i = start; i < available.size(); i++)
	{
		int x = available[i].first;
		int y = available[i].second;
		// 씨앗을 놓을 위치에 꽃잎이 겹치는 경우가 생기는지 확인한다.
		for (int k = 0; k < 8; k++)
		{
			int mx = x + dx[k];
			int my = y + dy[k];
			// 씨앗을 놓지 않은 곳이 씨앗을 놓을 수 없는 위치이다 = 꽃잎이 겹칠 
			if (visited[mx][my]) {
				flag = true;  break;
			}
		}
		// 꽃잎이 겹친다. => 씨앗을 놓을 위치를 다음 위치로 넘긴다.
		if (flag) {
			flag = !flag;  continue;
		}
		// 꽃잎이 겹치지 않는다. ==> 씨앗을 높을 수 있다.
		// 다음으로 놓을 수 있는 씨앗의 시작 위치와 놓은 씨앗의 개수를 갱신하여 재귀적으로 반복한다.
		else
		{
			visited[x][y] = true;
			fillgrid(i + 1, count + 1);
			visited[x][y] = false;
		}
	}
}
int main()
 {
	cin >> N;
	// 꽃잎이 겹치는지 왼쪽으로 2칸이동, 위로 2칸이동, 오른쪽으로 2칸이동하여 확인하기 때문에
	// 데이터를 배열의 2번째 행,열부터 채운다.
	for (int i = 2; i < N+2; i++)
	{
		for (int j = 2; j < N+2; j++)
		{
			cin >> grid[i][j];
			if (i == 2 || i == N + 1 || j == 2 || j == N + 1) continue;
			available.push_back(make_pair(i, j));
		}
	}
	for (size_t i = 0; i < available.size(); i++)
	{
		int x = available[i].first;
		int y = available[i].second;
		
		visited[x][y] = true;
		fillgrid(i + 1, 1);
		visited[x][y] = false;
	}
	cout << ans;
	return 0;
}
