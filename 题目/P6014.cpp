// Problem:      P6014 [CSGRound3]斗牛
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P6014
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-06-04 21:04:30 

#include <iostream>

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

int n, b[11], res;

int main()
{
	read(n);
	for (int i = 1, x; i <= n; ++i)
	{
		read(x); ++b[x % 10];
		res = (res + x) % 10;
	}	
	for (int i = 0; i <= 9; ++i)
	{
		for (int j = i + 1; j <= 9; ++j)
			if ((i + j) % 10 == res && b[i] && b[j])
			{ writeln(res != 0 ? res : 10); flushout(); return 0; }
	} 
	for (int i = 0; i <= 9; ++i)
		if ((i << 1) % 10 == res && b[i] > 1)
			{ writeln(res != 0 ? res : 10); flushout(); return 0; }
	writeln(0); flushout();
	return 0;
}