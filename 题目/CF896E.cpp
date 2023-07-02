// Problem:      Welcome home, Chtholly
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/CF896E
// Memory Limit: 500 MB
// Time Limit:   3000 ms
// Created Time: 2023-05-12 13:24:18 

#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC target("mmx","avx","avx2","avx512f","sse2","sse3","sse4","sse4.1","sse4.2")

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

int n, m;
int opt, l, r, x;
i64 a[200010];

int main()
{
	read(n, m);
	for (reg int i = 1; i <= n; ++i)
		read(a[i]);
	for (reg int i = 1; i <= m; ++i)
	{
		read(opt, l, r, x);
		if (opt == 1)
		{
			reg int i;
			for (i = l; i + 4 <= r; i += 4)
			{
				if (a[i] > x) a[i] -= x;
				if (a[i + 1] > x) a[i + 1] -= x;
				if (a[i + 2] > x) a[i + 2] -= x;
				if (a[i + 3] > x) a[i + 3] -= x;
			}
			while (i <= r)
			{
				if (a[i] > x) a[i] -= x;
				++i;
			}
		}
		else
		{
			i64 res0 = 0, res1 = 0, res2 = 0, res3 = 0;
			reg int i;
			for (i = l; i + 4 <= r; i += 4)
			{
				res0 += (a[i] == x);
				res1 += (a[i + 1] == x);
				res2 += (a[i + 2] == x);
				res3 += (a[i + 3] == x);
			}
			while (i <= r) res3 += (a[i] == x), ++i;
			writeln(res0 + res1 + res2 + res3);
		}
	}
	flushout();
	return 0;
}