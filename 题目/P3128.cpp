// Problem:      P3128 [USACO15DEC]Max Flow P
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3128
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-26 19:35:45 

#include <iostream>

#include <vector>
#include <cstring>

#define i64 long long
#define reg register
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;
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
    template <typename _int>
    inline void read(_int &x)
    {
        if (inl + _d > inr) { flushin(); }
        int isne = 0;
        for (; !isdigit(*inl); ++inl) { isne = (*inl == '-'); }
        x = (*inl++ - '0');
        for (; isdigit(*inl); ++inl) { x = x * 10 + (*inl - '0'); }
        if (isne) { x = -x; }
    }
    template <typename _int>
    inline void writeln(_int x, char end = '\n')
    {
        if (outl > outr) { flushout(); }
        if (x < 0) { *outl++ = '-'; x = -x; }
        char sta[20]; char *top = sta;
        do { *top++ = (x % 10) + '0'; x /= 10; } while (x);
        do { *outl++ = *--top; } while (top != sta);
        (*outl++) = end;
    }
    template<typename _int, typename ...Args>
    inline void read(_int& x, Args& ...args) { read(x), read(args...); }
}
using namespace bufIO;

const int inf = 0x7ffffff;

#define N 500010
#define ls (p << 1)
#define rs (p << 1 | 1)
struct Node { int l, r; int max, add; } t[N << 2];
inline void pushup(int p) { t[p].max = max(t[ls].max, t[rs].max); }
inline void pushdown(int p)
{
	if (t[p].add)
	{
		t[ls].max += t[p].add; t[ls].add += t[p].add;
		t[rs].max += t[p].add; t[rs].add += t[p].add;
		t[p].add = 0;
	}
}
inline void build(int p, int l, int r)
{
	t[p].l = l, t[p].r = r;
	if (l == r) { t[p].max = 0; return; }
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(p);
}
inline void add(int p, int l, int r, int k)
{
	if (l <= t[p].l && t[p].r <= r)
	{ t[p].max += k; t[p].add += k; return; }
	pushdown(p);
	int mid = (t[p].l + t[p].r) >> 1;
	if (l <= mid) add(ls, l, r, k);
	if (mid <  r) add(rs, l, r, k);
	pushup(p);
}
inline int query(int p, int l, int r)
{
	if (l <= t[p].l && t[p].r <= r) { return t[p].max; }
	pushdown(p);
	int mid = (t[p].l + t[p].r) >> 1, res = -inf;
	if (l <= mid) res = max(res, query(ls, l, r));
	if (mid <  r) res = max(res, query(rs, l, r));
	return res;
}

int n, k;
int x, y;
int dfn[500010], rnk[500010];
int fa[500010], dep[500010];
int siz[500010], hson[500010];
int top[500010], cnt;
vector<int> g[500010];

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
    top[u] = tp; dfn[u] = ++cnt; rnk[cnt] = x;
    if (hson[u] == -1) return;
    cut(hson[u], tp);
    for (auto v : g[u])
        if (v != hson[u] && v != fa[u])
            cut(v, v);
}
inline void addpath(int x, int y, int k)
{
	while (top[x] != top[y])
	{
		if (dep[top[x]] > dep[top[y]])
		{
			add(1, dfn[top[x]], dfn[x], k);
			x = fa[top[x]];
		}
		else
		{
			add(1, dfn[top[y]], dfn[y], k);
			y = fa[top[y]];
		}
	}
	if (dep[x] < dep[y])
		add(1, dfn[x], dfn[y], k);
	else
		add(1, dfn[y], dfn[x], k);
}
int main()
{
	read(n, k); build(1, 1, n);
	for (reg int i = 1, u, v; i <= n - 1; ++i)
		read(u, v), g[u].pb(v), g[v].pb(u);
	init(1); cut(1, 1);
	for (reg int i = 1, x, y; i <= k; ++i)
	{
		read(x, y);
		addpath(x, y, 1);
	}
	writeln(query(1, 1, n));
	flushout();
	return 0;
}