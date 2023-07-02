#include <iostream>

#include <algorithm>
#include <cmath>
#include <bitset>
#include <map>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~	");

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

int n, m, ans, pre, maxn;
int a[5010];
int b[5010];
int faq[5010];
int prime[10000010];
bool vis[1000010];
map<int, bool> bad;

inline void Euler(int n)
{
	for (reg int i = 2; i <= n; ++i)
	{
		if (!prime[i]) { prime[++prime[0]] = i; }
		for (reg int j = 1; j <= prime[0] && i * prime[j] <= n; ++j)
		{
			prime[i * prime[j]] = 1;
			if (!(i % prime[j])) break;
		}
	}
}

inline int f(int x)
{
	int res = 0;
	for (reg int i = 1; i <= prime[0]; ++i)
	{
		while ( !(x % prime[i]) )
		{
			if ( bad[prime[i]] ) --res;
			else ++res;
			x /= prime[i];
		}
		if (x == 1) break;
	}
	if (x == 1) return res;
	if (bad[x]) return res - 1;
	return res + 1;
}

inline void mk(int pos, int g)
{
	for (reg int i = 1; i <= pos; ++i)
		a[i] /= g;
}

int	main()
{
	read(n, m);
	for (reg int i = 1; i <= n; ++i)
		read(a[i]);
	for (reg int i = 1, x; i <= m; ++i)
		read(x), bad[x] = 1;
	Euler(50010);
	while (1)
	{
		int pre = a[1], pos = 1, u = a[1];
		for (reg int i = 2; i <= n; ++i)
		{
			pre = __gcd(pre, a[i]);
			if (f(pre) < 0)
				pos = i, u = pre;
		}
		if (f(u) >= 0)
			break;
		mk(pos, u);
	}
	for (reg int i = 1; i <= n; ++i)
		ans += f(a[i]);
	writeln(ans);
	flushout();
	return 0;
}