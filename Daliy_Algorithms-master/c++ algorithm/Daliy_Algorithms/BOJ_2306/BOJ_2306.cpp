// 백준알고리즘 2306번 :: 유전자
#include<iostream>
#include<string>
using namespace std;
#define max(a,b) (a > b) ? a: b

char arr[502];

// dp[i][j] : i부터 j 인덱스의 문자열에서의 KOI 유전자 길이가 저장된 배열
int dp[502][502];

int main(void)
{
	string str;
	cin >> str;

	// 문자열의 길이
	int len = str.size();

	// 배열에 문자 저장
	for (int i = 0; i < len; i++)
		arr[i] = str[i];

	for (int size = 1; size < len; size++)
	{
		for (int start = 0; start + size < len; start++)
		{
			int end = start + size;
		
			// 어떤 X가 KOI 유전자라면, aXt와 gXc도 KOI 유전자이다.
			if ((arr[start] == 'a' && arr[end] == 't') || (arr[start] == 'g' && arr[end] == 'c'))
				dp[start][end] = dp[start+1][end - 1] + 2;

			// 어떤 X와 Y가 KOI 유전자라면, 이 둘을 연결한 XY도 KOI 유전자이다.
			for (int mid = start; mid < end; mid++)
			{
				int v = dp[start][mid] + dp[mid + 1][end];
				dp[start][end] = max(dp[start][end], v);
			}
		}
	}

	cout << dp[0][len-1];

	return 0;
}
