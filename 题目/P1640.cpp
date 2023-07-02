// Problem:      P1640 [SCOI2010] 连续攻击游戏
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1640
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-11 21:05:20

// Problem:      P1129 [ZJOI2007] 矩阵游戏
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1129
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-10 20:52:13

#include <iostream>

#include <cstring>
#include <vector>

#define i64 long long
#define reg register
#define pb push_back
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int n, T, ans, now;
int match[1000010];
int vis[1000010];
vector<int> g[1000010];

inline bool dfs(int u)
{
    for (auto v : g[u])
        if (vis[v] != now)
        {
            vis[v] = now;
            if (match[v] == -1 || dfs(match[v]))
                return match[v] = u, 1;
        }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    fill(match + 1, match + n + 1, -1);
    for (reg int i = 1, s1, s2; i <= n; ++i)
    {
        cin >> s1 >> s2;
        g[s1].pb(i);
        g[s2].pb(i);
    }
    for (reg int i = 1; i <= 1000000; ++i)
    {
        ++now;
        if (dfs(i)) ++ans;
        else break;
    }
    cout << ans << endl;
    return 0;
}