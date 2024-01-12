// 백준알고리즘 1725번 :: 히스토그램
#include<iostream>
#include<stack>
using namespace std;
#define max(a,b) a > b ? a : b
stack<int> st;
int arr[1000002];
int N = 0;
int ret = 0;

int main(void)
{
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	st.push(0);
	for (int i = 1; i <= N+1; i++)
	{
		while (!st.empty() && arr[st.top()] > arr[i])
		{
			int height = arr[st.top()];
			st.pop();
			int width = i - st.top()-1;

			ret = max(ret, height*width);
		}
		st.push(i);
	}

	cout << ret;

	return 0;
}
