// 백준알고리즘 1152번 :: 단어의 개수
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	char str[1000001];
	int ans = 0;
	scanf("%[^\n]", str);
	char *p = str;
	char token = ' ';
	
	while (*p == token) p++;
	while (1)
	{
		if (*p == '\0') {
			if (*(p-1) != token) ans++;
			break;
		}
		if (*(p-1) != token && *p == token) ans++;
		p++;
	}
	printf("%d", ans);
	return 0;
}
