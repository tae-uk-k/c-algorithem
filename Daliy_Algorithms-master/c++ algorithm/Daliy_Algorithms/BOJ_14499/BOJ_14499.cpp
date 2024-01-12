// 백준알고리즘 14499번 :: 주사위 굴리기
#include<iostream>
using namespace std;

int N, M, x, y, K;
// 위 앞 오 왼 뒤 밑
int dice[6];
int map[20][20];

// 동 서 북 남
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

// 주사위 면의 숫자를 갱신하는 함수
void newdice(int _ord)
{

	int temp[6] = {0};
	for (int i = 0; i < 6; i++)
		temp[i] = dice[i];

	switch (_ord)
	{
	case 1: // 동
		dice[0] = temp[3];
		dice[2] = temp[0];
		dice[3] = temp[5];
		dice[5] = temp[2];
		break;
	case 2: // 서
		dice[0] = temp[2];
		dice[2] = temp[5];
		dice[3] = temp[0];
		dice[5] = temp[3];
		break;
	case 3: // 남 : 밑->앞->위->뒤
		dice[0] = temp[4];
		dice[1] = temp[0];
		dice[4] = temp[5];
		dice[5] = temp[1];
		break;
	case 4: // 북 : 밑->뒤->위->앞
		dice[0] = temp[1];
		dice[1] = temp[5];
		dice[4] = temp[0];
		dice[5] = temp[4];
		break;
	}
	return;
}

int main(void)
{
	int ord;
	int top = 0, bottom = 5;
	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	while(K--)
	{
		cin >> ord;

		int mx = x + dx[ord-1];
		int my = y + dy[ord-1];

		if (mx >= 0 && mx < N && my >= 0 && my < M) {
			// 주사위 갱신
			newdice(ord);
			// 지도 0이면, 주사위 바닥면을 복사하여 넣는다.
			if (!map[mx][my]) map[mx][my] = dice[bottom];
			// 지도가 0이 아니면, 주사위 바닥면에 지도의 값을 넣고 지도는 0이 된다.
			else {
				dice[bottom] = map[mx][my];
				map[mx][my] = 0;
			}
			cout << dice[top] << '\n';
			x = mx;
			y = my;
		}
	}
	return 0;

}
