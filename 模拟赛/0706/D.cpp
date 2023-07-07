// Problem:      P2512 [HAOI2008]糖果传递
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2512
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-28 20:50:30 

// Problem:      P4016 负载平衡问题
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P4016
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-28 20:42:38 

#include <iostream>

#include <algorithm>

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

const int N = 1e6 + 10;

int n, mid;
int a[N], ave;
int sum[N];
i64 all, ans;

int main()
{
	read(n); mid = (n >> 1) + 1;
	
	for (int i = 1; i <= n; ++i)
		read(a[i]), all += a[i];
	
	all /= n;
	
	for (int i = 1; i <= n; ++i)
		a[i] = a[i - 1] + all - a[i];
	
	sort(a + 1, a + n + 1);
	nth_element(a + 1, a + mid, a + n + 1);
	
	for (int i = 1; i <= n; ++i)
		ans += abs(a[mid] - a[i]);
	
	writeln(ans); flushout();
	return 0;
}