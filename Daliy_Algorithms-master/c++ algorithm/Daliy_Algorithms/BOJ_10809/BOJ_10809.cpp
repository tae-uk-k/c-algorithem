// 백준알고리즘 10809번 :: 알파벳 찾기
#include<iostream>
#include<string>
#include<memory.h>
using namespace std;

int main(void)
{
	string str;

	getline(cin, str);
	cin.clear();

	int ans[26];
	memset(ans, -1, sizeof(int) * 26);

	for (size_t i = 0; i < str.length(); i++)
	{
		char alpha = str[i];
		if (ans[alpha - 'a'] == -1) ans[alpha - 'a'] = i;
	}
	
	for (int i = 0; i < 26; i++) cout << ans[i] << ' ';

	return 0;
}
