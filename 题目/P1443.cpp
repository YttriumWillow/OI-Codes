// Problem:	P1443 马的遍历
// Contest:	Luogu
// URL:	https://www.luogu.com.cn/problem/P1443
// Memory Limit:	128 MB
// Time Limit:	1000 ms
// Created Time:	2023-02-18 12:55:45

#include <iostream>

#include <queue>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m, x, y, xx, yy;

struct Node
{
    int x, y, s;
    Node() {}
    Node(int x, int y, int s) : x(x), y(y), s(s) {}
} now;

queue<Node> q;

bool vis[410][410];
int step[410][410];
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, 2, -2, -1, 1};

inline bool check(int x, int y)
{
    return !vis[x][y] && x <= n && y <= m && x >= 1 && y >= 1;
};

int main()
{
    scanf("%d%d%d%d", &n, &m, &x, &y);

    q.push(Node(x, y, 0));
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        xx = now.x;
        yy = now.y;
        if(vis[xx][yy]) continue;
        vis[xx][yy] = true;
        step[xx][yy] = now.s;
        for (reg int i = 0; i < 8; ++i)
            if (check(now.x + dx[i], now.y + dy[i]))
                q.push(Node(now.x + dx[i], now.y + dy[i], now.s + 1));
    }

    for (reg int i = 1; i <= n; ++i)
    {
        for (reg int j = 1; j <= m; ++j)
        {
            if (!vis[i][j])
                printf("%-5d", -1);
            else
                printf("%-5d", step[i][j]);
        }
        printf("\n");
    }
    return 0;
}