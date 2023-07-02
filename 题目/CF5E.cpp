// Problem:      Bindian Signalizing
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/CF5E
// Memory Limit: 250 MB
// Time Limit:   4000 ms
// Created Time: 2023-04-29 10:57:41 

#include <iostream>

#include <stack>
#include <cstring>
#include <bitset>

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
        reg int rlen = fread(buf + (inr - inl), 1, inl - buf, stdin);
        if (inl - rlen > buf) { buf[inr - inl + rlen] = EOF; }
        inl = buf;
    }
    inline void flushout() { fwrite(obuf, outl - obuf, 1, stdout), outl = obuf; }
    template <typename _Tp>
    inline void read(reg _Tp &x)
    {
        if (inl + _d > inr) { flushin(); }
        reg int isne = 0;
        for (; !isdigit(*inl); ++inl) { isne = (*inl == '-'); }
        x = (*inl++ - '0');
        for (; isdigit(*inl); ++inl) { x = x * 10 + (*inl - '0'); }
        if (isne) { x = -x; }
    }
    template <typename _Tp>
    inline void writeln(reg _Tp x, char end = '\n')
    {
        if (outl > outr) { flushout(); }
        if (x < 0) { *outl++ = '-'; x = -x; }
        reg char sta[20]; char *top = sta;
        do { *top++ = (x % 10) + '0'; x /= 10; } while (x);
        do { *outl++ = *--top; } while (top != sta);
        (*outl++) = end;
    }
    template<typename _Tp, typename ...Args>
    inline void read(_Tp& x, Args& ...args) { read(x), read(args...); }
}
using namespace bufIO;

int n;
int pos, now, faq;
int a[1000010];
int h[1000010];
int r[1000010];
bitset<1000010> vis;
stack<int> st;
i64 ans;

int main()
{
	read(n);
	for (reg int i = 1, now = 0; i <= n; ++i)
	{
		read(a[i]);
		if (a[i] > now)
		{ now = a[i], pos = i; }
	}
	for (reg int i = 1; i <= n; ++i)
		h[i] = a[(i + pos - 2) % n + 1];	
	
	for (reg int i = 1; i <= n; ++i)
    {
    	r[i] = 1; faq = 0;
        for (; st.size() && h[faq = st.top()] <= h[i]; st.pop())
        {
        	ans += r[faq];
        	if (h[i] == h[faq])
        		r[i] += r[faq];
        }
        if (st.size())
        {
        	++ans;
        	if (st.top() == 1)
        		vis[i] = 1;
        }
        st.push(i);
    }
    
    for (reg int i = n; i > 1; --i)
    {
    	if (!vis[i] && h[i] != h[1] && h[i] >= now)
    		++ans;
    	now = max(now, h[i]);
    }
    
	writeln(ans);
	flushout();
	return 0;
}