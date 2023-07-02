// Problem:      Petya and Array
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/CF1042D
// Memory Limit: 250 MB
// Time Limit:   2000 ms
// Created Time: 2023-05-02 09:35:53 

#include <iostream>

#include <algorithm>

#define i64 long long
#define reg register
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

int n, t; i64 ans;
int a[200010];
i64 sum[200010];

inline void CDQ(reg int l, reg int r)
{
	if (l == r) return;
	reg int mid = (l + r) >> 1;
	CDQ(l, mid); CDQ(mid + 1, r);
	reg int j = l;
	for (reg int i = mid + 1; i <= r; ++i)
	{
		while (j <= mid && sum[i] >= sum[j] + t + 1) ++j;
		ans += mid - j + 1;
	}
	sort(sum + l, sum + r + 1);
}

int main()
{
	read(n, t);
	for (reg int i = 1; i <= n; ++i)
		read(a[i]), sum[i] = sum[i - 1] + a[i];
	CDQ(0, n);
	writeln(ans); flushout();
	return 0;
}