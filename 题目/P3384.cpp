// Problem:      P3384 【模板】重链剖分/树链剖分
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3384
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-29 14:55:55 

#include <iostream>

#include <vector>

#define i64 long long
#define reg register
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

#include <cstring>
namespace bufIO
{
    const int _Pu = 1 << 16;
    const int _d = 32;
    char buf[_Pu], obuf[_Pu];
    char *inl = buf + _Pu, *inr = buf + _Pu;
    char *outl = obuf, *outr = obuf + _Pu - _d;
    inline void flushin()
    {
        memmove(buf, inl, inr - inl);
        int rlen = fread(buf + (inr - inl), 1, inl - buf, stdin);
        if (inl - rlen > buf) { buf[inr - inl + rlen] = EOF; }
        inl = buf;
    }
    inline void flushout() { fwrite(obuf, outl - obuf, 1, stdout), outl = obuf; }
    template <typename _Tp>
    inline void read(_Tp &x)
    {
        if (inl + _d > inr) { flushin(); }
        int isne = 0;
        for (; !isdigit(*inl); ++inl) { isne = (*inl == '-'); }
        x = (*inl++ - '0');
        for (; isdigit(*inl); ++inl) { x = x * 10 + (*inl - '0'); }
        if (isne) { x = -x; }
    }
    template <typename _Tp>
    inline void writeln(_Tp x, char end = '\n')
    {
        if (outl > outr) { flushout(); }
        if (x < 0) { *outl++ = '-'; x = -x; }
        char sta[20]; char *top = sta;
        do { *top++ = (x % 10) + '0'; x /= 10; } while (x);
        do { *outl++ = *--top; } while (top != sta);
        (*outl++) = end;
    }
    template<typename _Tp, typename ...Args>
    inline void read(_Tp& x, Args& ...args) { read(x), read(args...); }
}
using namespace bufIO;

int n, m, s, mod;

template<typename Tp>
struct BIT
{
    #define N 100010
    #define lowbit(x) (x & -x)
    Tp t1[N] = { 0 };
    Tp t2[N] = { 0 };
    int len = 0;
    inline void init(int n) { len = n; }
    inline void add(Tp x, Tp v)
    {
        for (reg int i = x; i <= len; i += lowbit(i))
            t1[i] = (t1[i] + v % mod) % mod, t2[i] = (t2[i] + x * v % mod) % mod;
    }
    inline Tp query(Tp x)
    {
        reg Tp res = 0;
        for (reg int i = x; i; i -= lowbit(i))
            res = (res + ((x + 1) * t1[i] % mod - t2[i] % mod) % mod) % mod;
        return (res + mod) % mod;
    }
    inline Tp range(Tp l, Tp r) { return (query(r) - query(l - 1) + mod) % mod; }
    inline void modify(Tp l, Tp r, Tp x) { add(l, x); add(r + 1, -x); }
};

BIT<i64> t;
int a[100010];
int dfn[100010], rnk[100010];
int fa[100010], dep[100010];
int siz[100010], hson[100010];
int top[100010], cnt;
vector<int> g[100010];

inline void init(int u)
{
    hson[u] = -1; siz[u] = 1;
    dep[u] = dep[fa[u]] + 1;
    for (auto v : g[u])
        if (!dep[v])
        {
        	if (v == fa[u]) continue;
            fa[v] = u;
            init(v);
            siz[u] += siz[v];
            if (hson[u] == -1 || siz[v] > siz[hson[u]])
                hson[u] = v;
        }
}
inline void cut(int u, int tp)
{
    top[u] = tp; dfn[u] = ++cnt; rnk[cnt] = dfn[u];
    if (hson[u] == -1) return;
    cut(hson[u], tp);
    for (auto v : g[u])
        if (v != hson[u] && v != fa[u])
            cut(v, v);
}
inline void addpath(int x, int y, i64 k)
{
	while (top[x] != top[y])
	{
		if (dep[top[x]] > dep[top[y]])
			t.modify(dfn[top[x]], dfn[x], k), x = fa[top[x]];
		else
			t.modify(dfn[top[y]], dfn[y], k), y = fa[top[y]];
	}
	if (dep[x] < dep[y])
		t.modify(dfn[x], dfn[y], k);
	else
		t.modify(dfn[y], dfn[x], k);
}
inline i64 querypath(int x, int y)
{
	reg i64 res = 0;
	while (top[x] != top[y])
	{
		if (dep[top[x]] > dep[top[y]])
			res += t.range(dfn[top[x]], dfn[x]), res %= mod, x = fa[top[x]];
		else
			res += t.range(dfn[top[y]], dfn[y]), res %= mod, y = fa[top[y]];
	}
	if (dep[x] < dep[y])
		res += t.range(dfn[x], dfn[y]), res %= mod;
	else
		res += t.range(dfn[y], dfn[x]), res %= mod;
	return res;
}
inline void addsubtree(int x, i64 k)
{ t.modify(dfn[x], dfn[x] + siz[x] - 1, k); }
inline i64 querysubtree(int x)
{ return (t.range(dfn[x], dfn[x] + siz[x] - 1) + mod) % mod; }
int main()
{
	read(n, m, s, mod); t.init(n);
	for (reg int i = 1; i <= n; ++i)
		read(a[i]);
	for (reg int i = 1, u, v; i <= n - 1; ++i)
		read(u, v), g[u].pb(v), g[v].pb(u);
	init(s); cut(s, s);
	for (reg int i = 1; i <= n; ++i)
		t.modify(dfn[i], dfn[i], a[i]);
	for (reg int i = 1, opt, x, y, z; i <= m; ++i)
	{
		read(opt);
		if (opt == 1)
		{
			read(x, y, z);
			addpath(x, y, z);
		}
		if (opt == 2)
		{
			read(x, y);
			writeln(querypath(x, y));
		}
		if (opt == 3)
		{
			read(x, z);
			addsubtree(x, z);
		}
		if (opt == 4)
		{
			read(x);
			writeln(querysubtree(x));
		}
	}
	flushout();
	return 0;
}