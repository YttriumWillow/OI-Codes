// Problem:      P2286 [HNOI2004]宠物收养场
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2286
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-27 18:59:18 

#include <iostream>

#include <vector>
#include <algorithm>

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

const i64 inf = 0x7fffffffffffff;
const i64 mod = 1000000;

// wait what is this really a balanced tree
template<typename Tp>
struct BalancedTree
{
    vector<Tp> t; typename::vector<Tp>::iterator pos = t.begin();
    inline void getpos(Tp x) { pos = lower_bound(t.begin(), t.end(), x); }
    inline void insert(Tp x) { getpos(x); t.insert(pos, x); }
    inline void del(Tp x)    { getpos(x); t.erase(pos); }
    inline Tp queryrnk(Tp x) { getpos(x); return pos - t.begin() + 1; }
    inline Tp queryval(Tp x) { getpos(x); return t.at(x - 1); }
    inline Tp prev(Tp x)     { getpos(x); return *(--pos); }
    inline Tp next(Tp x)     { getpos(x); return *upper_bound(t.begin(), t.end(), x); }
};

BalancedTree<i64> t;
i64 n, ans;
bool flag;

inline void update(i64 x)
{
	i64 p = t.prev(x), q = t.next(x);
	i64 pre = abs(x - p), nxt = abs(x - q);
	if (pre <= nxt)
		t.del(p), ans = (ans + pre % mod) % mod;
	else
		t.del(q), ans = (ans + nxt % mod) % mod;
}

int main()
{
	read(n);
	t.insert(-inf); t.insert(inf);
	for (reg int i = 1, opt, x; i <= n; ++i)
	{
		read(opt, x);
		if (t.t.size() == 2)
			flag = opt, t.insert(x);
		else
		{
			if (opt == flag) t.insert(x);
			else update(x);
		}
	}
	writeln(ans);
	flushout();
	return 0;
}