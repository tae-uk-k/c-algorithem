// 백준알고리즘 9328번 :: 열쇠
#include<iostream>
#include<queue>
#include<string>
using namespace std;
 
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
 
int main(void)
{
    int T;
    int w, h;
    string str;
 
    cin >> T;
 
    while (T--)
    {
        char map[101][101] = { 0 }; // 지도
        bool visited[101][101] = { 0 }; // 방문여부
        queue<pair<int, int>> q; // 갈 수 있는 위치
        queue<pair<int, int>> door[26]; // 잠긴 문 위치
        bool key[26] = { 0 }; // key 존재여부
        int ans = 0; // 정답
 
        cin >> w >> h;
 
        for (int i = 0; i < w; i++)
        {
            cin >> str;
            for (int j = 0; j < h; j++)
            {
                map[i][j] = str[j];
 
                if ((i == 0) || (i == w - 1) || (j == 0) || (j == h - 1))
                {
                    if (str[j] == '*') continue;
                    else if (str[j] >= 'A' && str[j] <= 'Z') {
                        door[str[j] - 'A'].push(make_pair(i, j)); continue;
                    }
                    else if (str[j] >= 'a' && str[j] <= 'z') key[str[j] - 'a'] = true;
                    q.push(make_pair(i, j));
                    visited[i][j] = true;
                }
            }
        }
 
        cin >> str;
        if (str != "0")
        {
            for (size_t i = 0; i < str.length(); i++)
            {
                key[str[i] - 'a'] = true;
 
                if (key[str[i] - 'a'] && !door[str[i] - 'a'].empty())
                {
                    while (!door[str[i] - 'a'].empty())
                    {
                        int x = door[str[i] - 'a'].front().first;
                        int y = door[str[i] - 'a'].front().second;
                        door[str[i] - 'a'].pop();
                        q.push(make_pair(x, y));
                        visited[x][y] = true;
                    }
                }
 
            }
        }
 
        while (!q.empty())
        {
            int qsize = q.size();
 
            while (qsize--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
 
                // 문서를 찾았다
                if (map[x][y] == '$') ans++;
 
                for (int i = 0; i < 4; i++)
                {
                    int mx = x + dx[i];
                    int my = y + dy[i];
 
                    if (mx >= 0 && mx < w && my >= 0 && my < h)
                    {
                        if (visited[mx][my]) continue;
                        else if (map[mx][my] == '*') continue;
                        else if (map[mx][my] >= 'A' && map[mx][my] <= 'Z') {
                            // 해당하는 키가 없다면 door에 대기 시키고 continue
                            if (!key[map[mx][my] - 'A']) { door[map[mx][my] - 'A'].push(make_pair(mx, my)); continue; }
                        }
                        else if (map[mx][my] >= 'a' && map[mx][my] <= 'z') {
                            // 키를 줍고 키에 해당하는 door가 대기 상태에 있으면 q에 넣음
                            key[map[mx][my] - 'a'] = true;
                            if (!door[map[mx][my] - 'a'].empty())
                            {
                                while (!door[map[mx][my] - 'a'].empty())
                                {
                                    int rx = door[map[mx][my] - 'a'].front().first;
                                    int ry = door[map[mx][my] - 'a'].front().second;
                                    door[map[mx][my] - 'a'].pop();
                                    q.push(make_pair(rx, ry));
                                }
                            }
                        }
                        // 방문하지 않았던 위치의 .인 경우, $인 경우, 키가 있는 door, 키
                        q.push(make_pair(mx, my));
                        visited[mx][my] = true;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
