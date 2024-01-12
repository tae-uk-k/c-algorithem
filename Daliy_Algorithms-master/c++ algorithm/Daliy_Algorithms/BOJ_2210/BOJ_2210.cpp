// 백준알고리즘 2210번 :: 숫자판 점프
#include<iostream>
using namespace std;
 
int ans;
int board[5][5];
bool flag[1000000];
int number;
 
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
 
void search(int x, int y, int count)
{
    number = number*10 + board[x][y];
 
    if(count == 6)
    {
        // 이미 체크된 숫자인지 확인
        if (!flag[number]) {
            flag[number] = true;
            ans++;
        }
        return;
    }
 
    for (int i = 0; i < 4; i++)
    {
        int mx = x + dx[i];
        int my = y + dy[i];
 
        if (mx >= 0 && mx < 5 && my >= 0 && my < 5)
        {
            search(mx, my, count+1);
            number /= 10;
        }
    }
}
 
int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> board[i][j];
        }
    }
 
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            search(i, j, 1);
            number /= 10;
        }
    }
 
    cout << ans;
 
    return 0;
}
