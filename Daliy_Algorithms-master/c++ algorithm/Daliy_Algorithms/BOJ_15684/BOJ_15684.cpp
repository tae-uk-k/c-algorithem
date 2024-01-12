// 백준알고리즘 15684번 :: 사다리 조작
#include<iostream>
#include<vector>
using namespace std;

struct node
{
	int x;
	int y;
};

int N, M, H, a, b;
int ans = -1;
bool flag; // 출발지와 도착지가 같은지 확인하는 변수
bool ladder[32][12]; // 사다리판
vector<node> v; // line을 그릴 수 있는 위치를 저장해놓은 벡터

// 출발지와 도착지가 같은지 확인하는 함수
bool operate()
{
	for (int node = 1; node <= N; node++)
	{
		int line = node;
		int row = 1;

		while (row <= H)
		{
			// 오른쪽으로 이동
			if (ladder[row][line]) line += 1;
			// 왼쪽으로 이동
			else if (ladder[row][line - 1]) line -= 1;
			row++;
		}
		// 출발지와 도착지가 다르면 false
		if (node != line) return false;
	}
	// 모든 node를 탐색했을 때, 출발지와 도착지가 같으면 true
	return true;
}

// line을 그리는 함수
// _count : 현재 line 그린 개수,
// _num : line 그릴 목표 개수,
// ord : 그릴 수 있는 line 위치가 담긴 vector의 시작 index
void addline(int _count, int _num, int ord)
{
	// 목표한 개수만큼 line을 그렸으면 올바른 도착지에 갔는지 확인하여 ans 갱신
	if (_count == _num)
	{
		flag = operate();
		if (flag) ans = _num;
		return;
	}

	// line 그리기
	for (size_t i = ord; i < v.size(); i++)
	{
		int _x = v[i].x;
		int _y = v[i].y;

		// 현재 위치에 line이 그려져 있거나 양쪽에 line이 그려져 있으면 continue
		if (ladder[_x][_y] || ladder[_x][_y-1] || ladder[_x][_y+1]) continue;
		ladder[_x][_y] = true;
		addline(_count + 1, _num, i+1);
		ladder[_x][_y] = false;

		if (flag) return;
	}
}

int main(void)
{
	cin >> N >> M >> H;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		ladder[a][b] = true;
	}

	node nd;

	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (!ladder[i][j])
			{
				nd.x = i;
				nd.y = j;
				v.push_back(nd);
			}
		}
	}

	// line  0개 그리기, 1개 그리기, 2개 그리기, 3개 그리기
	// 이미 ans가 갱신되었으면 최솟값이 결정된 것이니 끝낸다.
	for (int i = 0; i <= 3; i++)
	{
		if(!flag) addline(0, i, 0);
	}

	cout << ans;

	return 0;
}
