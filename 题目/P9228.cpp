// Problem:      P9228 原神
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P9228
// Memory Limit: 512 MB
// Time Limit:   2000 ms
// Created Time: 2023-04-22 19:32:04 

#include <iostream>

#include <algorithm>
#include <cstring>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

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

int n, m, k;
int a[1000010];
int b[1000010];
i64 ans;

int main()
{
	read(n, m, k);
	
	for (reg int i = 1; i <= n; ++i)
		read(a[i]), ans += a[i];
	for (reg int i = 1; i <= m; ++i)
		read(b[i]), ans += b[i];
	sort(a + 1, a + n + 1, greater<int>());
	for (reg int i = 1; i <= min(n, m); ++i)
		ans += max(a[i], k);
	writeln(ans);
	flushout();
	return 0;
}