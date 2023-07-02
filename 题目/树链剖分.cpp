#include <iostream>

#include <vector>

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

int n, q, s;
int x, y, w;
int fa[500010], dep[500010];
int siz[500010], hson[500010];
int top[500010], dfn[500010];
int rnk[500010], cnt;
vector<int> g[500010];

inline void init(int u)
{
    hson[u] = -1; siz[u] = 1;
    for (auto v : g[u])
        if (!dep[v])
        {
            dep[v] = dep[u] + 1; fa[v] = u;
            init(v);
            siz[u] += siz[v];
            if (hson[u] == -1 || siz[v] > siz[hson[u]])
                hson[u] = v;
        }
}

inline void cut(int u, int tp)
{
    top[u] = tp; ++cnt;
    dfn[u] = cnt; rnk[cnt] = u;
    if (hson[u] == -1) return;
    cut(hson[u], tp);
    for (auto v : g[u])
        if (v != hson[u] && v != fa[u])
            cut(v, v);
}

inline int LCA(int u, int v)
{
	while (top[u] != top[v])
	{
		if (dep[top[u]] > dep[top[v]]) u = fa[top[u]];
		else                           v = fa[top[v]];
	}
	return dep[u] < dep[v] ? u : v;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	read(n, q, s);
	for (reg int i = 1; i <= n - 1; ++i)
		read(x, y), g[y].pb(x);
	init(s); cut(s, s);
	while (q--)
	{
		read(x, y);
		writeln(LCA(x, y));
	}
	return 0;
}