// Problem:      P3258 [JLOI2014]松鼠的新家
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3258
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-26 20:22:02 

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

template<typename Tp>
struct BIT
{
    #define N 500010
    #define lowbit(x) (x & -x)
    Tp t[N] = { 0 }; int len = 0;
    inline void init(int n) { len = n; }
    inline void add(Tp x, Tp v)
    {
        for (reg int i = x; i <= len; i += lowbit(i))
            t[i] += v;
    }
    inline void modify(Tp l, Tp r, Tp v) { add(l, v); add(r + 1, -v); }
    inline Tp query(Tp x)
    {
        reg Tp res = 0;
        for (reg int i = x; i; i -= lowbit(i))
            res += t[i];
        return res;
    }
};

int n;
BIT<int> t;
int path[300010];
int dfn[300010], rnk[300010];
int fa[300010], dep[300010];
int siz[300010], hson[300010];
int top[300010], cnt;
vector<int> g[300010];

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
    top[u] = tp; dfn[u] = ++cnt; rnk[cnt] = u;
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
			t.modify(dfn[top[x]], dfn[x], k);
			x = fa[top[x]];
		}
		else
		{
			t.modify(dfn[top[y]], dfn[y], k);
			y = fa[top[y]];
		}
	}
	if (dep[x] < dep[y]) t.modify(dfn[x], dfn[y], k);
	else				 t.modify(dfn[y], dfn[x], k);
}
int main()
{
	read(n); t.init(n);
	
	for (reg int i = 1; i <= n; ++i)
		read(path[i]);
	for (reg int i = 1, u, v; i <= n - 1; ++i)
		read(u, v), g[u].pb(v), g[v].pb(u);
	
	init(1); cut(1, 1);
	
	for (reg int i = 2; i <= n; ++i)
	{
		addpath(path[i - 1], path[i], 1);
		t.modify(dfn[path[i]], dfn[path[i]], -1);
	}
	for (reg int i = 1; i <= n; ++i)
		writeln(t.query(dfn[i]));
	flushout();
	return 0;
}