// 백준 알고리즘 1062번 :: 가르침
#include<iostream>
#include<string>
using namespace std;

int N, K;
int ans = 0;
string sentence[51];
bool alpha[26];

int findmaxwordnum()
{
	int count = 0;

	for (int i = 0; i < N; i++)
	{
		bool flag = true;
		int stlen = sentence[i].size();
		for (int j = 0; j < stlen; j++)
		{
			if (!alpha[sentence[i][j] - 'a']) flag = false;
			if (!flag) break;
		}
		if (flag) count++;
	}
	return count;
}
void simulate(int start, int count)
{
	if (count == K - 5) {
		// 읽을 수 있는 문장 개수 구하기
		int numword = findmaxwordnum();
		// ans 갱신하기
		if (ans < numword) ans = numword;
		return;
	}
	// 알파벳 체크하기
	// 내가 고려하지 못한 것!!!!!!!!!!!!!!!!!!!!! (4)
	for (size_t i = start; i < 26; i++)
	{
		if (alpha[i]) continue;
		alpha[i] = true;
		simulate(i+1, count + 1);
		alpha[i] = false;
	}
	return;
}

int main()
{
	string str;
	cin >> N >> K;

	// 내가 고려하지 못한 것!!!!!!!!!!!!!!!!!!!!! (1, 2)
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		//anta
		str = str.substr(4, str.length());

		//tica
		for (int j = 0; j < 4; j++)
			str.pop_back();

		sentence[i] = str;

	}

	// K가 5이상일 때에만 simulate한다.
	// 그렇지 않은 경우는 "anta"+"tica"를 읽을 수 없으므로 0을 출력한다.
	// K가 26일 때에는 모든 단어를 읽을 수 있다.

	// 내가 고려하지 못한 것!!!!!!!!!!!!!!!!!!!!! (3)
	if (K == 26) ans = N;
	else if (K >= 5)
	{
		alpha['a' - 'a'] = true;
		alpha['n' - 'a'] = true;
		alpha['t' - 'a'] = true;
		alpha['i' - 'a'] = true;
		alpha['c' - 'a'] = true;

		simulate(0,0);
	}

	cout << ans;

	return 0;
}
