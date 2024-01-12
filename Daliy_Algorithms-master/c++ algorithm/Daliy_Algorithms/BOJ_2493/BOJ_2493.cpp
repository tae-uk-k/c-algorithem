// 백준알고리즘 2493번 :: 탑
#include <iostream>
#include <stack>
using namespace std;
int N;
int ans[500001];
// idx, height
stack<pair<int, int>> st;
int main()
{
	int height = 0;
	cin >> N;
	cin >> height;
	st.push(make_pair(1, height));
	for (int i = 1; i < N; i++)
	{
		cin >> height;
		// height가 st.top보다 크면
		// stack에서 큰 값을 찾는다.
		if (height > st.top().second)
		{
			while (!st.empty() && st.top().second < height)
			{
				st.pop();
			}
			// stack에 height보다 큰 값이 없으면
			if (st.empty())
			{
				ans[i] = 0;
			}
			// stack에 heigth보다 큰 값이 있으면
			else
			{
				ans[i] = st.top().first;
				if (st.top().second == height) st.pop();
			}
		}
		// height가 st.top보다 작거나 같으면 ans[i] = st.top().first다.
		else
		{
			ans[i] = st.top().first;
		}
		st.push(make_pair(i+1, height));
	}
	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
