// Problem:      P3379 【模板】最近公共祖先（LCA）
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3379
// Memory Limit: 512 MB
// Time Limit:   2000 ms
// Created Time: 2023-03-10 13:48:57

#include <iostream>

#include <cmath>
#include <vector>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");
#define pb push_back

namespace IO
{
template <typename _Tp> inline void read(_Tp &x)
{
#define gc() getchar()
    x = 0;
    char c = gc();
    bool f = 0;
    while (!std::isdigit(c))
        f |= c == 45, c = gc();
    while (std::isdigit(c))
        x = x * 10 + (c ^ 48), c = gc();
    return (void)(f ? x = -x : 1);
}

template <typename _Tp> inline void write(_Tp x)
{
    static char stk[20];
    int top = 0;
    if (!x)
        return putchar(48), void();
    if (x < 0)
        putchar(45), x = -x;
    while (x)
        stk[top++] = x % 10, x /= 10;
    while (top)
        putchar(stk[--top] + 48);
}

template <typename _Tp, typename... Args> inline void read(_Tp &x, Args &...args)
{
    read(x), read(args...);
}
}; // namespace IO

using namespace IO;
using namespace std;

int n, m, s, tmp;

vector<int> g[500010];
int anc[500010][31];
int dep[500010];
bool vis[500010];

inline void dfs(int now)
{
    vis[now] = true;
    for (reg int i = 1; (1 << i) <= dep[now]; ++i)
        anc[now][i] = anc[anc[now][i - 1]][i - 1];
    for (auto nxt : g[now])
    {
        if (!vis[nxt])
        {
            dep[nxt] = dep[now] + 1;
            anc[nxt][0] = now;
            dfs(nxt);
        }
    }
}

inline int LCA(int x, int y)
{
    if (x == y)
        return x;
    if (dep[x] > dep[y])
        swap(x, y);

    for (reg int i = log2(dep[y]); i >= 0; --i)
        // if (dep[x] < dep[y] && dep[anc[y][i]] >= dep[x])
        if (dep[x] <= dep[y] - (1 << i))
            y = anc[y][i];

    if (x == y)
        return x;
    for (reg int i = log2(dep[y]); i >= 0; --i)
    {
        if (anc[x][i] == anc[y][i])
            continue;
        if (anc[x][i] != anc[y][i])
        {
            x = anc[x][i];
            y = anc[y][i];
        }
    }
    return anc[x][0];
}

int main()
{
    read(n, m, s);
    for (reg int i = 1, u, v; i <= n - 1; ++i)
    {
        read(u, v);
        g[u].pb(v);
        g[v].pb(u);
    }
    dep[s] = 0;
    dfs(s);
    for (reg int i = 1, u, v; i <= m; ++i)
    {
        read(u, v);
        write(LCA(u, v));
        printf("\n");
    }
    return 0;
}