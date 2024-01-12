// 백준알고리즘 15685번 :: 드래곤 커브
#include<iostream>
#include<vector>
using namespace std;

struct info
{
	// 끝점의 좌표
	int x;
	int y;
	// 방향 저장하는 벡터
	vector<int> v;
};

struct info info;

int N;
int x, y, d, g;
int ans;
// 우, 상, 좌, 하
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

bool grid[101][101];

void countsquare()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (grid[i][j] && grid[i + 1][j] && grid[i][j + 1] && grid[i + 1][j + 1]) ans++;
		}
	}
	return;
}

void dragoncurve()
{
	int count = 0;

	while (count < g)
	{
		count++;

		// 드래곤커브가 그려질 방향을 갱신한다.
		// 2세대를 그려야 할 때, 
		if (count == 2)
		{
			info.v.push_back((d + 2) % 4);
		}
		// 3세대 이상을 그려야 할 때,
		else if(count >= 3)
		{
			// v2에 기존 벡터 복사
			vector<int> v2;
			v2.resize(info.v.size());
			copy(info.v.begin(), info.v.end(), v2.begin());

			// 원소 값 바꾸기
			for (size_t i = 0; i < v2.size() / 2; i++)
			{
				v2[i] = (v2[i] + 2) % 4;
			}

			// 벡터 이어붙이기
			info.v.insert(info.v.end(), v2.begin(), v2.end());
		}

		// 드래곤커브를 그린다.
		for (int i = (int)info.v.size()-1; i >= 0; i--)
		{
			int end_x = info.x + dx[info.v[i]];
			int end_y = info.y + dy[info.v[i]];

			grid[end_y][end_x] = true;

			info.x = end_x;
			info.y = end_y;
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> x >> y >> d >> g;
		
		grid[y][x] = true;
		info.v.clear();
		
		// 0 세대
		info.x = x + dx[d];
		info.y = y + dy[d];
		info.v.push_back((d + 1) % 4);

		grid[info.y][info.x] = true;

		dragoncurve();
	}

	// 정사각형 개수를 센다.
	countsquare();

	cout << ans;

	return 0;
}
