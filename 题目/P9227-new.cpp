// Problem:      P9227 异或积
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P9227
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-24 19:12:14 

#include <iostream>

#include <cstring>

#define uint unsigned int
#define i64 long long
#define u64 unsigned i64
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

int n, T; i64 k;
uint a[100010];
uint pre[100010];
uint suf[100010];

int main()
{
    cin >> T;

    while (T--)
    {
        read(n, k);
        for (reg int i = 1; i <= n; ++i)
            read(a[i]);

        if ((n & 1) || (k & 1))
        {
        	suf[n + 1] = 0;
            for (reg int i = 1; i <= n; ++i)
                pre[i] = pre[i - 1] ^ a[i];
            for (reg int i = n; i >= 1; --i)
                suf[i] = suf[i + 1] ^ a[i];
            for (reg int i = 1; i < n; ++i)
                writeln(pre[i - 1] ^ suf[i + 1], ' ');
            writeln(pre[n - 1] ^ suf[n + 1]);
        }
        else
        {
            for (reg int i = 1; i < n; ++i)
                writeln(a[i], ' ');
            writeln(a[n]);
        }
    }
    flushout();
    return 0;
}
