// Problem:      P1129 [ZJOI2007] 矩阵游戏
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1129
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-10 20:52:13

#include <iostream>

#include <vector>
#include <cstring>

#define i64 long long
#define reg register
#define pb push_back
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int n, T, ans;
int match[510];
bool g[510][510], vis[510];

inline bool dfs(int u)
{
    for (reg int i = 1; i <= n; ++i)
        if (g[u][i] && !vis[i])
        {
            vis[i] = 1;
            if (!match[i] || dfs(match[i]))
                return match[i] = u, 1;
        }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while (T--)
    {
        memset(g, 0, sizeof g);
        memset(match, 0, sizeof match);
        
        cin >> n; ans = 0;
        for (reg int i = 1; i <= n; ++i)
            for (reg int j = 1; j <= n; ++j)
                cin >> g[i][j];
        for (reg int i = 1; i <= n; ++i)
        {
        	memset(vis, 0, sizeof vis);
            ans += dfs(i);
        }
        cout << (ans == n ? "Yes" : "No") << endl;
    }
    return 0;
}