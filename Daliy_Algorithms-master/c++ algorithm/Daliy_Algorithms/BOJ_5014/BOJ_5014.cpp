// BOJ 5014 :: 스타트링크
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int F, S, G, U, D, ret;
bool flag;
int visited[1000001];
vector<int> v;

void bfs(int _S)
{
	queue<int> q;
	q.push(_S);
	visited[_S] = 1;

	while (!q.empty())
	{
		int qsz = q.size();
		while (qsz--)
		{
			int cur = q.front();
			q.pop();

			if (cur == G) { flag = true;  return; };

			for (int i = 0; i < (int)v.size(); i++)
			{
				int mcur = cur + v[i];

				if (mcur < 1 || mcur > F) continue;
				if (visited[mcur]) continue;
				q.push(mcur);
				visited[mcur] = 1;
			}
		}
		ret++;
	}
	return;
}

int main() {

	cin >> F >> S >> G >> U >> D;
	if (U != 0) v.push_back(U);
	if (D != 0) v.push_back(-D);
	
	if (S != G)
	{
		if ((S > G && D == 0) || (S < G && U == 0) || (U == 0 && D == 0))
		{
			cout << "use the stairs";
		}
		else
		{
			bfs(S);
			if (flag) cout << ret;
			else cout << "use the stairs";
		}
	}
	else cout << "0";

	return 0;
}
