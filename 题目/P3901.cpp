// Problem:      P3901 数列找不同
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3901
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-07-04 19:28:17 

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
    template<typename _Tp, typename ...Args>
    inline void read(_Tp& x, Args& ...args) { read(x), read(args...); }
}
using namespace bufIO;

const int N = 1e5 + 10;

int n, q;
int x, y, faq;
int l[N], maxl[N];

int main()
{
	read(n, q);
	for (int i = 1; i <= n; ++i)
	{
		read(faq);
		maxl[i] = max(maxl[i - 1], l[faq] + 1),
		l[faq] = i;
	}
	for	(int i = 1; i <= q; ++i)
	{
		read(x, y);
		puts(maxl[y] <= x ? "Yes" : "No");
	}
	return 0;
}