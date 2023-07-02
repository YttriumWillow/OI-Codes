// Problem:      P3987 我永远喜欢珂朵莉~
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3987
// Memory Limit: 1 MB
// Time Limit:   4000 ms
// Created Time: 2023-04-20 20:51:38 

#include <iostream>

#include <cstring>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq !");

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
int a[500010];
i64 sum;

int main()
{
	read(n, m);
	for (reg int i = 1; i <= n; ++i)
		read(a[i]);
	while (m--)
	{
		read(opt, l, r);
		if (opt == 1)
		{
			read(x); if (x == 1) continue; reg int i;
			if (x == 2)
			{
				for (i = l; i <= r - 3; i += 4)
				{
					!(a[i] & 1) ? a[i] >>= 1 : 1;
					!(a[i + 1] & 1) ? a[i + 1] >>= 1 : 1;
					!(a[i + 2] & 1) ? a[i + 2] >>= 1 : 1;
					!(a[i + 3] & 1) ? a[i + 3] >>= 1 : 1;
				}
				while (r - i + 1)
					!(a[i] & 1) ? a[i] >>= 1 : 1, ++i;
				continue;
			}
			else
			{
				for (i = l; i <= r - 3; i += 4)
				{
					!(a[i] % x) ? a[i] /= x : 1;
					!(a[i + 1] % x) ? a[i + 1] /= x : 1;
					!(a[i + 2] % x) ? a[i + 2] /= x : 1;
					!(a[i + 3] % x) ? a[i + 3] /= x : 1;
				}
				while (r - i + 1)
					!(a[i] % x) ? a[i] /= x : 1, ++i;
			}
		}
		if (opt == 2)	
		{
			sum = 0; reg int i;
			for (i = l; i <= r - 3; i += 4)
				sum += a[i] + a[i + 1] + a[i + 2] + a[i + 3];
			while (r - i + 1)
				sum += a[i], ++i;
			writeln(sum);
		}
	}
	flushout();
	return 0;
}