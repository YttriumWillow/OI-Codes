// Problem:      T343314 『XYGOI round1』一棵树
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/T343314?contestId=113611
// Memory Limit: 512 MB
// Time Limit:   1000 ms
// Created Time: 2023-07-01 14:52:56 

#include <iostream>

#include <cmath>
#include <algorithm>

#define i64 long long 
#define endl '\n'
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

const int N = 1e6 + 10;
const int M = 1e6 + 10;
const int mod = 998244353;
const int pat[21] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000 };

struct Edge
{
	int v, nxt; Edge() { }
	Edge(int v, int n): v(v), nxt(n) { }
} e[M << 1];
int tot, head[N];
inline void addedge(int u, int v)
{ e[++tot] = Edge(v, head[u]), head[u] = tot; }

int n, x, ans; 
int a[N], l[N];
i64 dis[N];
bool vis[N];

inline void dfs(int u)
{	vis[u] = 1;
	for (int i = head[u]; i; i = e[i].nxt)
	{
		if (!vis[e[i].v])
		{
			int v = e[i].v;
			dis[v] = (dis[u] * pat[l[v]] % mod + a[v]) % mod,
			ans = (ans + dis[v]) % mod, dfs(v);
		}
	} vis[u] = 0;
}

inline void subtask01()
{
	for (int i = 1; i <= n; ++i)
	{
		ans = (ans + a[i]) % mod,
		dis[i] = a[i], dfs(i);
	}
	writeln(ans), flushout();
	exit(0);
}

inline void subtask3()
{
	
}

int main()
{
	read(n);
	for (int i = 1; i <= n; ++i)
	{
		read(a[i]);
		l[i] = (!a[i]) ? 1 : (int)log10(a[i]) + 1;
	}
	for (int i = 1; i <= n - 1; ++i)
	{
		read(x);
		addedge(i + 1, x);
		addedge(x, i + 1);
	}
	if (n <= 8000)
		subtask01();
	return 0;
}