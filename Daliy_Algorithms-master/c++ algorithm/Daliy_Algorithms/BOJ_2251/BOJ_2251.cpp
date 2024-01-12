// 백준알고리즘 2251번 :: 물통
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int A, B, C;
vector<int> ans;
queue<pair<pair<int, int>, int>> bucket;
int visited[201][201][201];
int selected[200];

void bfs()
{
	while (!bucket.empty())
	{
		int qsz = bucket.size();
		while (qsz--)
		{
			int a = bucket.front().first.first;
			int b = bucket.front().first.second;
			int c = bucket.front().second;
			bucket.pop();

			if (a == 0 && selected[c] != 1)
			{
				selected[c] = 1;
				ans.push_back(c);
			}

			if (a != 0)
			{
				// a를 b에 넣기
				if (B - b < a) {
					if (visited[a - (B - b)][B][c] == 0) {
						bucket.push(make_pair(make_pair(a - (B - b), B), c));
						visited[a - (B - b)][B][c] = 1;
					}
				}
				else {
					if (visited[0][a + b][c] == 0) {
						bucket.push(make_pair(make_pair(0, a + b), c));
						visited[0][a + b][c] = 1;
					}
				}
				// a를 c에 넣기
				if (C - c < a) {
					if (visited[a - (C - c)][b][C] == 0) {
						bucket.push(make_pair(make_pair(a - (C - c), b), C));
						visited[a - (C - c)][b][C] = 1;
					}
				}
				else {
					if (visited[0][b][a+c] == 0) {
						bucket.push(make_pair(make_pair(0, b), a+c));
						visited[0][b][a + c] = 1;
					}
				}
			}
			if (b != 0)
			{
				// b를 a에 넣기
				if (A - a < b) {
					if (visited[A][b-(A-a)][c] == 0) {
						bucket.push(make_pair(make_pair(A, b-(A-a)), c));
						visited[A][b - (A - a)][c] = 1;
					}
				}
				else {
					if (visited[a+b][0][c] == 0) {
						bucket.push(make_pair(make_pair(a+b, 0), c));
						visited[a + b][0][c] = 1;
					}
				}
				// b를 c에 넣기
				if (C - c < b) {
					if (visited[a][b-(C-c)][C] == 0) {
						bucket.push(make_pair(make_pair(a, b-(C-c)), C));
						visited[a][b - (C - c)][C] = 1;
					}
				}
				else {
					if (visited[a][0][b + c] == 0) {
						bucket.push(make_pair(make_pair(a, 0), b + c));
						visited[a][0][b + c] = 1;
					}
				}
			}
			if (c != 0)
			{
				// c를 a에 넣기
				if (A - a < c) {
					if (visited[A][b][c-(A-a)] == 0) {
						bucket.push(make_pair(make_pair(A, b), c-(A-a)));
						visited[A][b][c - (A - a)] = 1;
					}
				}
				else {
					if (visited[a + c][b][0] == 0) {
						bucket.push(make_pair(make_pair(a + c, b), 0));
						visited[a + c][b][0] = 1;
					}
				}
				// c를 b에 넣기
				if (B - b < c) {
					if (visited[a][B][c-(B-b)] == 0) {
						bucket.push(make_pair(make_pair(a, B), c-(B-b)));
						visited[a][B][c - (B - b)] = 1;
					}
				}
				else {
					if (visited[a][b+c][0] == 0) {
						bucket.push(make_pair(make_pair(a, b+c), 0));
						visited[a][b + c][0] = 1;
					}
				}
			}
		}
	}
}

int main()
{
	cin >> A >> B >> C;
	bucket.push(make_pair(make_pair(0, 0), C));

	bfs();

	sort(ans.begin(), ans.end());
	for(int i = 0; i < (int)ans.size(); i++)
		cout << ans[i] << ' ';

	return 0;
}
