// Problem:      P1823 [COI2007] Patrik 音乐会的等待
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1823
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-29 11:23:49 

#include <iostream>

#include <stack>

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

#define Pii pair<int, int>
int n, m; i64 ans;
int h[500010];
stack<Pii> st;

int main()
{
    read(n);
    for (reg int i = 1; i <= n; ++i)
        read(h[i]);
    
    for (reg int i = 1; i <= n; ++i)
    {
    	Pii now = { h[i], 1 };
        while (!st.empty() && st.top().first <= h[i])
        {
        	ans += st.top().second;
        	if (h[i] == st.top().first)
        		now.second += st.top().second;
        	st.pop();
        }
        if (!st.empty()) ++ans;
        st.push(now);
    }
	writeln(ans);
	flushout();

    return 0;
}