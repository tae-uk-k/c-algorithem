// 백준알고리즘 1079번 :: 마피아
#include<iostream>
using namespace std;

int N, mafia;
int ans = -1;
bool flag;

int point[16];
int R[16][16];
bool die[16];

// 유죄점수가 가장 높은 idx구하기, 같으면 낮은 idx
int calculate()
{
	int idx = -1;
	int idx_point = -10000;

	for (int i = 0; i < N; i++)
	{
		if (point[i] > idx_point && !die[i])
		{
			idx = i;
			idx_point = point[i];
		}
	}
	return idx;
}

// num : 남아있는 사람의 수
void kill(int num, int lcans)
{
	// 더이상 갱신될 값이 없다. 이미 최대 값이 결정되었다.
	if (flag) return;

	// 은진이가 죽었거나, 은진이만 남아있을 때, 답 갱신 후, 종료.
	if (die[mafia] || num == 1) {
		// 낮으로 끝났으면 +1
		if (num % 2) lcans += 1;

		if (lcans > ans || ans == -1) ans = lcans;
		if (num == 1) flag = true;
		return;
	}

	// 남아있는 사람이 짝수이면, 밤이다.
	// 마피아가 죽일 사람을 한 명 고른다.
	if (!(num % 2))
	{
		for (int i = 0; i < N; i++)
		{
			if (flag) return;

			// 죽지않은 시민일 때
			if (!die[i] && i != mafia)
			{
				int temp[16];
				for (int i = 0; i < N; i++)
					temp[i] = point[i];

				die[i] = true;

				// 점수 갱신
				for (int j = 0; j < N; j++)
					point[j] += R[i][j];

				kill(num - 1, lcans);
				die[i] = false;

				// 점수 갱신
				for (int j = 0; j < N; j++)
					point[j] = temp[j];
			}
		}
	}
	// 남아있는 사람의 수가 홀수이면, 낮이다.
	// 유죄점수가 가장 높은 사람을 죽인다, 같으면 플레이어 번호가 낮은 사람을 죽인다.
	else {
		
		int idx = calculate();

		die[idx] = true;
		kill(num - 1, lcans+1);
		die[idx] = false;
	}
}

int main(void)
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> point[i];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> R[i][j];
		
	cin >> mafia;

	if (N == 1) ans = 0;
	else
	{
		if (N % 2) kill(N, -1);
		else kill(N, 0);
	}

	cout << ans;

	return 0;
}
