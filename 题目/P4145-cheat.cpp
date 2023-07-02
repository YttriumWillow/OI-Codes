// Problem:      P4145 上帝造题的七分钟 2 / 花神游历各国
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P4145
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-04 20:07:43 

#pragma GCC target("avx","sse2","sse3","sse4","mmx","avx512f","sse4.1","sse4.2")

#include <iostream>

#include <cmath>

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

int n, m, k, l, r;
i64 a[100010];

int main()
{
	read(n);
	for (reg int i = 1; i <= n; ++i)
		read(a[i]);
	read(m);
	while (m--)
	{
		read(k, l, r); if (l > r) swap(l, r);
		if (k == 0)
		{
			for (reg int i = l; i <= r; ++i)
				if (a[i] != 1)
					a[i] = (i64)sqrt(a[i]);
		}
		else
		{
			reg i64 res = 0;
			for (reg int i = l; i <= r; ++i)
				res += a[i];
			writeln(res);
		}
	}
	flushout();
	return 0;
}