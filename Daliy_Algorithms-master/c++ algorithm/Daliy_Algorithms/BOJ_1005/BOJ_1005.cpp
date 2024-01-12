// 백준알고리즘 1005번 :: ACM Craft
#include<iostream>
#include<queue>
using namespace std;

int main(void)
{
	int T, N, K, delay_time, start, end, goal;

	cin >> T;
	while (T--)
	{
		queue<int> q;
		int delay[1001];
		int vertex_ans[1001] = { 0 };
		bool v[1001][1001] = { 0 };

		cin >> N >> K;

		for (int i = 1; i <= N; i++)
		{
			cin >> delay_time;
			delay[i] = delay_time;
		}

		for (int i = 0; i < K; i++)
		{
			cin >> start >> end;
			v[start][end] = 1;
		}
		cin >> goal;

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (v[j][i]) break;
				else if (j == N) {
					q.push(i); vertex_ans[i] = 0;
				}
			}
		}

		while (!q.empty())
		{
			int prev_vertex;
			int qsz = q.size();
			int max_delay = 0;
			while (qsz--)
			{
				prev_vertex = q.front();
				q.pop();

				if (prev_vertex == goal) break;

				for (int i = 1; i <= N; i++)
				{
					if (v[prev_vertex][i])
					{
						v[prev_vertex][i] = 0;

						int new_delay_time = vertex_ans[prev_vertex] + delay[prev_vertex];
						if (vertex_ans[i] < new_delay_time) vertex_ans[i] = new_delay_time;

						for (int j = 1; j <= N; j++)
						{
							if (v[j][i]) break;
							else if (j==N){
								q.push(i);
							}
						}
					}
				}
			}
			if (prev_vertex == goal) break;
		}
		cout << vertex_ans[goal] + delay[goal] << '\n';
	}

	return 0;
}
