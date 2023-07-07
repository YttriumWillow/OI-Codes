// Problem:      P6175 无向图的最小环问题
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P6175
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-07-06 10:22:07

#include <iostream>

#define int long long
#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int inf = 1e13;

int n, m, u, v, w, ans = inf;

int dis[128][128];
int mp[128][128];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j)
                dis[i][j] = mp[i][j] = inf;
    
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[v][u], w);
        mp[u][v] = min(mp[u][v], w);
        mp[v][u] = min(mp[v][u], w);
    }
    
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i < k; ++i)
            for (int j = i + 1; j < k; ++j)
                ans = min(ans, dis[i][j] + mp[i][k] + mp[k][j]);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                dis[j][i] = dis[i][j];
            }
    }
    
    if (ans == inf) cout << "No solution.";
    else			cout << ans << endl;
    return 0;
}
