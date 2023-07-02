#include <bits/stdc++.h>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define pb push_back

using namespace std;

struct MapNode
{
    bool way[4];
} mp[61][61];

struct Node
{
    int x, y;
};

int n, m;
bool vis[61][61];
// int x[2510];
// int dx[4] = {0, 1, 0, -1};
// int dy[4] = {-1, 0, 1, 0};
int cnt, ans;

queue<Node> q;

void bfs(int x, int y)
{
    int s = 0;
    q.push(Node{x, y});
    while (!q.empty())
    {
        int xx = q.front().x;
        int yy = q.front().y;
        q.pop();
        if (vis[xx][yy])
            continue;
        vis[xx][yy] = true;
        ++s;
        // printf("log: x:%d, y:%d, count:%d\n", xx, yy, s);
        // printf("also: w:%d, n:%d, e:%d, s:%d\n", mp[xx][yy].way[0], mp[xx][yy].way[1], mp[xx][yy].way[2], mp[xx][yy].way[3]);
        
        if (!vis[xx][yy - 1] && !mp[xx][yy].way[0])
            q.push(Node{xx, yy - 1});
            
        if (!vis[xx - 1][yy] && !mp[xx][yy].way[1])
            q.push(Node{xx - 1, yy});
            
        if (!vis[xx][yy + 1] && !mp[xx][yy].way[2])
            q.push(Node{xx, yy + 1});
            
        if (!vis[xx + 1][yy] && !mp[xx][yy].way[3])
            q.push(Node{xx + 1, yy});
            
    }
    ans = max(ans, s);
}

int main()
{
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    
    scanf("%d%d", &n, &m);
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1, s; j <= m; ++j)
        {
            scanf("%d", &s);
            if ((s / 1) % 2)
                mp[i][j].way[0] = 1;
            if ((s / 2) % 2)
                mp[i][j].way[1] = 1;
            if ((s / 4) % 2)
                mp[i][j].way[2] = 1;
            if ((s / 8) % 2)
                mp[i][j].way[3] = 1;
        }
        
    for (reg int i = 1; i <= n; ++i)
    	vis[i][0] = vis[i][m + 1] = 1;
    for (reg int i = 1; i <= m; ++i)
    	vis[0][i] = vis[n + 1][i] = 1;
    	
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j <= m; ++j)
            if (!vis[i][j])
                ++cnt, bfs(i, j);//, printf("newblock: x:%d y:%d\n\n", i, j);
    printf("%d\n%d\n", cnt, ans);
    return 0;
}