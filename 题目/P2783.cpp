// Problem:      P2783 有机化学之神偶尔会做作弊
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2783
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-06-26 15:24:47 

#include <iostream>

#include <set>
#include <vector>

#define i64 long long
#define endl '\n'
#define pb push_back
#define qwqw puts("fzy qwq ~");

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
    template <typename _Tp>
    inline void write(_Tp x)
    {
        if (outl > outr) { flushout(); }
        if (x < 0) { *outl++ = '-'; x = -x; }
        char sta[20]; char *top = sta;
        do { *top++ = (x % 10) + '0'; x /= 10; } while (x);
        do { *outl++ = *--top; } while (top != sta);
    }
    template<typename _Tp, typename ...Args>
    inline void read(_Tp& x, Args& ...args) { read(x), read(args...); }
}
using namespace bufIO;

const int N = 1e5 + 10;
const int M = 5e4 + 10;

int n, m, u, v, q;
int dfncnt, dcccnt;
int dfn[N], low[N], dcc[N];
int fa[N], dep[N], siz[N];
int hson[N], top[N], cnt;
bool ins[N];
set<pair<int, int>> faq;
vector<int> g[N];
struct FAQ { int u, v; } eg[M];
struct Edge
{
	int v, nxt; Edge() {}
	Edge(int v, int x): v(v), nxt(x) {}
};
Edge e[M << 1];
int head[N], tot = 1;
bool b[M << 1];

inline void addedge(int u, int v)
{ e[++tot] = Edge(v, head[u]); head[u] = tot; }

inline void tarjan(int u, int ine)
{
	dfn[u] = low[u] = ++dfncnt;
	for (int i = head[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (!dfn[v])
		{
			tarjan(v, i);
			low[u] = min(low[u], low[v]);
			
			if (dfn[u] < low[v])
				b[i] = b[i ^ 1] = 1;
		}
		else if (i != (ine ^ 1))
			low[u] = min(low[u], dfn[v]);
	}
}

inline void dfs(int u)
{
	dcc[u] = dcccnt;
	for (int i = head[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (!b[i] && !dcc[v]) dfs(v);
	}
}

inline void build()
{
	for (int i = 1; i <= n; ++i)
		for (int j = head[i]; j; j = e[j].nxt)
			if (dcc[i] != dcc[e[j].v])
				g[dcc[i]].pb(dcc[e[j].v]), g[dcc[e[j].v]].pb(dcc[i]);
}

inline void init(int u)
{
	hson[u] = -1; siz[u] = 1;
	dep[u] = dep[fa[u]] + 1;
	for (auto v : g[u])
	{
		if (!dep[v])
		{
			if (v == fa[u]) continue;
			fa[v] = u; init(v);
			siz[u] += siz[v];
			if (!~hson[u] || siz[v] > siz[hson[u]])
				hson[u] = v;
		}
	}
}

inline void cut(int u, int tp)
{
	top[u] = tp; ++cnt;
	if (!~hson[u]) return;
	cut(hson[u], tp);
	for (auto v : g[u])
		if (v != hson[u] && v != fa[u])
			cut(v, v);
}

inline int LCA(int u, int v)
{
	while (top[u] != top[v])
		(dep[top[u]] > dep[top[v]]) ? u = fa[top[u]] : v = fa[top[v]];
	return dep[u] < dep[v] ? u : v;
}

inline void print(int x)
{
	static int b[64], i; i = 0;
	for (; x; x >>= 1) b[++i] = x % 2;
	for (; i > 1; --i) write(b[i]);
	writeln(b[1]);
}

int main()
{
	read(n, m);
	for (int i = 1; i <= m; ++i)
	{
		read(u, v);
		if (u > v) swap(u, v);
		if (faq.count({ u, v })) continue;
		faq.insert({ u, v });
		addedge(u, v);
		addedge(v, u);
	}
	for (int i = 1; i <= n; ++i)
		if (!dfn[i]) tarjan(i, 0);
	for (int i = 1; i <= n; ++i)
		if (!dcc[i])
			++dcccnt, dfs(i);
	build(); init(1); cut(1, 1); 
	read(q);
	for (int i = 1; i <= q; ++i)
	{
		read(u, v);
		print(dep[dcc[u]] + dep[dcc[v]] - 2 * dep[LCA(dcc[u], dcc[v])] + 1);
	}
	flushout();
	return 0;
}