// Problem:      P8463 「REOI-1」深潜的第六兽
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P8463
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-03 20:24:47 

#include <iostream>

#define i64 long long
#define reg register
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

const int mod = 998244353;

template <typename Tp>
struct SegTree
{
    #define N 500010
    #define ls (p << 1)
    #define rs (p << 1 | 1)
    const Tp inf = 0xfffffff;
    struct Node { Tp l, r; Tp sum, cvr; Tp siz() { return r - l + 1; } } t[N << 2];
    inline void pushup(Tp p) { t[p].sum = (t[ls].sum + t[rs].sum) % mod; }
    inline void pushdown(Tp p)
    {
        if (t[p].cvr)
        {
            t[ls].sum = t[p].cvr * t[ls].siz() % mod; t[ls].cvr = t[p].cvr;
            t[rs].sum = t[p].cvr * t[ls].siz() % mod; t[rs].cvr = t[p].cvr;
            t[p].cvr = 0;
        }
    }
    inline void build(Tp p, Tp l, Tp r)
    {
        t[p].l = l, t[p].r = r;
        if (l == r) { t[p].sum = 1; return; }
        Tp mid = (l + r) >> 1;
        build(ls, l, mid);
        build(rs, mid + 1, r);
        pushup(p);
    }
    inline void modify(Tp p, Tp l, Tp r, Tp k)
    {
        if (l <= t[p].l && t[p].r <= r)
        { t[p].sum = k * t[p].siz() % mod; t[p].cvr = k; return; }
        pushdown(p);
        Tp mid = (t[p].l + t[p].r) >> 1;
        if (l <= mid) modify(ls, l, r, k);
        if (mid <  r) modify(rs, l, r, k);
        pushup(p);
    }
    inline Tp query(Tp p, Tp l, Tp r)
    {
        if (l <= t[p].l && t[p].r <= r) { return t[p].sum; }
        pushdown(p);
        Tp mid = (t[p].l + t[p].r) >> 1, res = -inf;
        if (l <= mid) res = (res + query(ls, l, r)) % mod;
        if (mid <  r) res = (res + query(rs, l, r)) % mod;
        return res;
    }
};

struct Seg
{
	int l, r, h;
}

int main()
{
	read(n, m);
	for (reg int i = 1; i <= m; ++i)
		read(l, r, h), seg[i] = { l, r, h };
	for (reg int i = 1; i <= n; ++i)
	{
		read(x);
		
	}
	flushout();
	return 0;
}