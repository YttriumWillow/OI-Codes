// Problem:      P1963 [NOI2009] 变换序列
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1963
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-17 20:22:10

#include <iostream>

#include <set>
#include <vector>

#define i64 long long
#define endl '\n'
// #define pb pb
#define pb insert
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 10010;

int n, m, ans, x, y;
int d[N], match[N], nxt[N];
bool vis[N];
set<int> g[N];

inline bool dfs(int u)
{
    for (auto v : g[u])
        if (!vis[v])
        {
            vis[v] = 1;
            if (!match[v] || dfs(match[v]))
                return match[v] = u, nxt[u] = v, 1;
        }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> d[i];
        // x = (i + d[n] + n) % n;
        // y = (i - d[i] + n) % n;
        // g[i].pb(x);
        // g[i].pb(y);

        if (i + d[i] <= n) g[i].pb(i + d[i]);
        if (i - d[i] >= 1) g[i].pb(i - d[i]);
        if (i + n - d[i] <= n) g[i].pb(i + n - d[i]);
        if (i - n + d[i] >= 1) g[i].pb(i - n + d[i]);
        
    }
    for (int i = n; i; --i)
    {
        fill(vis + 1, vis + n + 1, 0);
        ans += dfs(i);
    }
    if (ans < n) { cout << "No Answer" << endl; return 0; }
    for (int i = 1; i <= n; ++i)
        cout << nxt[i] - 1 << ' ';
    return 0;
}