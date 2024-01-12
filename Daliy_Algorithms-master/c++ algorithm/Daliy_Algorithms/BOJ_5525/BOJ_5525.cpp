// 백준알고리즘 5525번 :: IOIOI
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int N, ssize;
string sentence;
string pattern;

vector<int> makeTable()
{
	int psize = (int)pattern.size();
	vector<int> Table(psize, 0);
	int j = 0;

	for (int i = 1; i < psize; i++)
	{
		while (j != 0 && pattern[i] != pattern[j])
			j = Table[j - 1];
		if (pattern[i] == pattern[j])
			Table[i] = ++j;
	}
	return Table;
}
int KMP()
{
	int ans = 0;
	vector<int> Table = makeTable();
	int psize = (int)pattern.size();
	int j = 0;
	for (int i = 0; i < ssize; i++)
	{
		while (j != 0 && sentence[i] != pattern[j])
			j = Table[j - 1];
		if (sentence[i] == pattern[j])
		{
			if (j == psize - 1)
			{
				ans++;
				j = Table[j];
			}
			else j++;
		}
	}
	return ans;
}

int main()
{
	cin >> N >> ssize >> sentence;

	for (int i = 0; i < (2 * N + 1); i++)
	{
		if ((i % 2) == 0) pattern.push_back('I');
		else pattern.push_back('O');
	}

	int ans = KMP();
	cout << ans;
	return 0;
}
