// Problem:      P5142 区间方差
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P5142
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-06-26 09:59:24 

#include <iostream>
#include <cmath>

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

const int N = 1e5 + 10;
const int RT = 1e3 + 10;
const i64 mod = 1e9 + 7;

int n, m, opt, x;
int blk, tot; 
int lft[RT], rgt[RT];
i64 a[N], y;
i64 sum[N], sqr[N];

#define bel(i) ((i - 1) / blk + 1)

inline i64 fpow(i64 a, i64 k)
{
	i64 res = 1; a %= mod;
	for (; k; k >>= 1)
	{
		if (k & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
	}
	return res;
}

#define inv(a) fpow(a, mod - 2)

inline void init(int n)
{
	// blk = (int)sqrt(n);
	// blk = (i64)pow(n, 0.44) + rand() % 3 - 1;
	// blk = log(n);
	blk = (int)pow(n, 0.432);
	// blk = (int)sqrt(n) + rand() % (int)sqrt(n) - (int)sqrt(n);
	tot = n / blk + !!(n % blk);
	for (int i = 1; i <= tot; ++i)
	{
		lft[i] = (i - 1) * blk + 1;
		rgt[i] = i * blk;
	} rgt[tot] = n;
	for (int i = 1; i <= tot; ++i)
	{
		for (int j = lft[i]; j <= rgt[i]; ++j)
		{
			sum[i] = (sum[i] + a[j]) % mod;
			sqr[i] = (sqr[i] + a[j] * a[j]) % mod;
		}
	}
}

inline void modify(int x, i64 y)
{
	int id = bel(x);
	sum[id] -= a[x];
	sqr[id] -= a[x] * a[x];
	a[x] = y;
	sum[id] += a[x];
	sqr[id] = (sqr[id] + a[x] * a[x]) % mod;
}

inline i64 query(int l, int r)
{
	int L = bel(l), R = bel(r);
	i64 t = (r - l + 1);
	i64 res = 0, ave = 0, invt = inv(t);
	if (L == R)
	{
		for (int i = l; i <= r; ++i)
		{
			ave += a[i];
			res = (res + a[i] * a[i]) % mod;
		}
		i64 tp = ave * invt % mod;
		return ((res * invt % mod - tp * tp % mod) % mod + mod) % mod;
	}
	for (int i = l; i <= rgt[L]; ++i)
	{
		ave += a[i];
		res = (res + a[i] * a[i]) % mod;
	}
	for (int i = L + 1; i <= R - 1; ++i)
	{
		ave += sum[i];
		res += sqr[i];
	}
	for (int i = lft[R]; i <= r; ++i)
	{
		ave += a[i];
		res = (res + a[i] * a[i]) % mod;
	}
	i64 tp = ave * invt % mod;
	return ((res * invt % mod - tp * tp % mod) % mod + mod) % mod;
}

int main()
{
	read(n, m);
	for (int i = 1; i <= n; ++i)
		read(a[i]);
	init(n);
	for (int i = 1; i <= m; ++i)
	{
		read(opt, x, y);
		if (opt == 1)
			modify(x, y);
		if (opt == 2)
			writeln(query(x, y));
	}
	flushout();
	return 0;
}