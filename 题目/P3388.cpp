// Problem:      P3388 【模板】割点（割顶）
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3388
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-21 19:53:54 

#include <iostream>

#include <vector>
#include <algorithm>
#include <set>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");
#define pb push_back

namespace IO
{
    template<typename _Tp>
    inline void read(_Tp& x)
    {
        x = 0; char c = getchar(); bool f = 0;
        while (!std::isdigit(c)) f |= c == 45, c = getchar();
        while ( std::isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
        return f ? x = -x : 1, void();
    }
    template<typename _Tp>
    inline void write(_Tp x)
    {
        static char stk[40]; int top = 0;
        if (!x)     return putchar(48), void();
        if (x < 0)  putchar(45), x = -x;
        while (x)   stk[top++] = x % 10, x /= 10;
        while (top) putchar(stk[--top] + 48);
    }

    // read
    template<typename _Tp, typename ...Args>
    inline void read(_Tp& x, Args& ...args) { read(x), read(args...); }

    // readchar
    inline void readchar(char& x) { for (x = getchar(); !std::isalpha(x); x = getchar()); }

    // readln
    template<typename _Tp, typename _Tpp>
    inline void readln(_Tp a[], _Tpp w) { for (reg _Tpp i = 1; i <= w; ++i) read(a[i]); }
    template<typename _Tp, typename _Tpp>
    inline void readln(_Tp a[], _Tpp l, _Tpp r) { for (reg _Tpp i = l; i <= r; ++i) read(a[i]); }

    // writespace
    template<typename _Tp>
    inline void writespace(_Tp x) { write(x); putchar(' '); }
    template<typename _Tp, typename ...Args>
    inline void writespace(_Tp& x, Args& ...args) { writespace(x), writespace(args...); }

    // writeln
    template<typename _Tp>
    inline void writeln(_Tp x) { write(x); putchar('\n'); }
    template<typename _Tp, typename ...Args>
    inline void writeln(_Tp& x, Args& ...args) { writespace(x), writespace(args...), putchar('\n'); }
    template<typename _Tp, typename _Tpp>
    inline void writeln(_Tp a[], _Tpp w) { for (reg _Tpp i = 1; i <= w; ++i) writespace(a[i]); putchar('\n'); }
    template<typename _Tp, typename _Tpp>
    inline void writeln(_Tp a[], _Tpp l, _Tpp r) { for (reg _Tpp i = l; i <= r; ++i) writespace(a[i]); putchar('\n'); }
};
using namespace IO;
using namespace std;

int n, m, ans, dfncnt;
int dfn[20010], low[20010];
bool cut[20010];

vector<int> g[20010];
set<int> ctp;


inline void tarjan(int u, int fa)
{
	low[u] = dfn[u] = ++dfncnt; int son = 0;
	for (auto v : g[u])
	{
		if (!dfn[v])
		{
			tarjan(v, fa);
			low[u] = min(low[u], low[v]);
			if (low[v] >= dfn[u] && u != fa)
				ctp.insert(u);
            son += (u == fa);
		}
		low[u] = min(low[u], dfn[v]);
	}
	if (son >= 2 && u == fa)
		ctp.insert(u);
}

int main()
{
	read(n, m);
	for (reg int i = 1, u, v; i <= m; ++i)
		read(u, v), 
		g[u].pb(v), 
		g[v].pb(u);
	for (reg int i = 1; i <= n; ++i)
		if (!dfn[i])
			tarjan(i, i);

	writeln(ctp.size());
	for (auto x : ctp)
		writespace(x);
	return 0;
}