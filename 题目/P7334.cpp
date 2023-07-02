// Problem:      P7334 [JRKSJ R1] 吊打
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P7334
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-06 10:11:34 

#include <iostream>

#include <cmath>

#define i64 long long
#define reg register
#define bel(p) ((p - 1) / blk + 1)
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

const i64 mod = 998244353;

int n, m, l, r, opt;
int blk, tot;
int lft[500], rgt[500];
int tag[500];
i64 sum[500];
i64 a[200010];
i64 ans;

inline void build(int n)
{
	blk = (int)sqrt(n);
	tot = n / blk; if (n % blk) ++tot;
    for (reg int i = 1; i <= tot; ++i)
    {
        lft[i] = (i - 1) * blk + 1;
        rgt[i] = i * blk;
    } rgt[tot] = n;
    for (reg int i = 1; i <= n; ++i)
    	sum[bel(i)] += a[i];
}

inline void update(int p) { tag[p] = (rgt[p] - lft[p] + 1) == sum[p]; }

inline void rt(int l, int r)
{
	int L = bel(l);
	int R = bel(r);
	if (L == R)
	{
		if (tag[L]) return;
		for (reg int i = l; i <= r; ++i)
		{
			sum[L] -= a[i];
			a[i] = (i64)sqrt(a[i]);
			sum[L] += a[i];
		}
		update(L);
		return;
	}
	if (!tag[L])
	{
		for (reg int i = l; i <= rgt[L]; ++i)
		{
			sum[L] -= a[i];
			a[i] = (i64)sqrt(a[i]);
			sum[L] += a[i];
		}
	}
	if (!tag[R])
	{
		for (reg int i = lft[R]; i <= r; ++i)
		{
			sum[R] -= a[i];
			a[i] = (i64)sqrt(a[i]);
			sum[R] += a[i];
		}
	}
	update(L); update(R);
	for (reg int now = L + 1; now < R; ++now)
	{
		if (tag[now]) continue;
		for (reg int i = lft[now]; i <= rgt[now]; ++i)
		{
			sum[now] -= a[i];
			a[i] = (i64)sqrt(a[i]);
			sum[now] += a[i];
		}
		update(now);
	}
}

inline void sq(int l, int r)
{
	for (reg int i = l; i <= r; ++i)
	{
		sum[bel(i)] -= a[i];
		a[i] = a[i] * a[i] % mod;
		sum[bel(i)] += a[i];
	}
}

int main()
{
	read(n, m);
	for (reg int i = 1; i <= n; ++i)
		read(a[i]);
	build(n);
	for (reg int i = 1; i <= m; ++i)
	{
		read(opt, l, r);
		(opt == 1) ? rt(l, r) : sq(l, r);
	}
	for (reg int i = 1; i <= tot; ++i)
		ans = (ans + sum[i]) % mod;
	writeln(ans); flushout();
	return 0;	
}