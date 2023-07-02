/*
    FileName: T_309757_yLOI_2023_云梦谣.cpp
        + randomhash: 57b32524800e8ef312f6c6a4
    Author: fengziyi
        + base64: ZmVuZ3ppeWk=
        + MD5: 9b0454ce8364ba54b28c8b9b7f9dafc7
    Date: 2023/02/11 星期六
    Time: 17:25:50
        + Unix Timestamp(second): 1676107550
    Encoding: UTF-8
        + Encodeing Test: 哦，你使用了UTF-8编码。不是么？ovo
*/

#include <iostream>

#include <queue>
#include <vector>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n'
#define space ' '

using namespace std;

struct Node
{
    int x, y;
    int step;
};

int n, m, k;
int a[3010][3010];
int dis1[3010][3010];
int dis2[3010][3010];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool vis1[3010][3010];
bool vis2[3010][3010];
bool fly[3010][3010];

int startfly;
int endfly;

queue<Node> q;

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);

    for (reg int i = 1, x, y; i <= k; ++i)
    {
        scanf("%d%d", &x, &y);
        fly[x][y] = 1;
    }

    q.push(Node{ 1, 1 });
    bool found = false;

    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        // printf("log: Arrived at (%d,%d) with %d steps.\n", now.x, now.y,
        // now.step);

        if (vis1[now.x][now.y])
            continue;
        vis1[now.x][now.y] = 1;
        if (fly[now.x][now.y] == 1)
        {
            if (!found)
            {
                found = true;
                startfly = dis1[now.x][now.y];
            }
            else
            {
                
            }
        }
        for (reg int d = 0; d < 4; ++d)
        {
            int xx = now.x + dx[d];
            int yy = now.y + dy[d];
            if (a[xx][yy] != 0)
            {
                q.push(Node{ xx, yy });
                dis1[xx][yy] = dis1[now.x][now.y] + 1;
            }
        }
    }
    printf("%d\n", -1);
    return 0;
}