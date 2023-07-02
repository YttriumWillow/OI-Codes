// Problem:      Willem, Chtholly and Seniorious
// Contest:      Luogu
// URL:          https://www -> luogu.com.cn/problem/CF896C
// Memory Limit: 250 MB
// Time Limit:   2000 ms
// Created Time: 2023-04-27 20:43:07 

#pragma GCC target("avx,sse2,sse3,sse4,mmx,avx512f,sse4.1,sse4.2")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")

#include <iostream>

#include <set>
#include <cstring>

#define i64 long long
#define reg register
#define endl '\n'
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

struct ChthollyTree
{
	struct Node
	{
		i64 l, r; mutable int v;
		Node(i64 l, i64 r = 0, int v = 0): l(l), r(r), v(v) {}
		inline bool friend operator < (const Node& _x, const Node& _y) { return _x.l < _y.l; }
	};
	set<Node> s;
	inline void init() { s.insert(Node(1, 1e18, 0)); }
	inline set<Node>::iterator split(i64 pos)
	{
		set<Node>::iterator it = s.lower_bound(Node(pos));
		if (it != s.end() && it->l == pos)
			return it;
		--it;
		if (it -> r < pos)
			return s.end();
		i64 l = it -> l, r = it -> r, v = it -> v;
		s.erase(it);
		s.insert(Node(l, pos - 1, v));
		return s.insert(Node(pos, r, v)).first;
	}
	inline void assign(i64 l, i64 r, int x)
	{
		set<Node>::iterator itr = split(r + 1), itl = split(l);
		s.erase(itl, itr);
		s.insert(Node(l, r, x));
	}
	inline void xxor(i64 l, i64 r)
	{
		set<Node>::iterator itr = split(r + 1), itl = split(l);
		for (set<Node>::iterator it = itl; it != itr; ++it)
			it -> v ^= 1;
	}
	inline i64 find()
	{
		for (reg Node it : s)
			if (it.v == 0)
				return it.l;
		return -1;
	}
};

int n, m, opt;
i64 l, r;
ChthollyTree t;

int main()
{
	read(m); t.init();
	for (reg int i = 1; i <= m; ++i)
	{
		read(opt, l, r);
		if (opt == 1)
			t.assign(l, r, 1);
		else if (opt == 2)
			t.assign(l, r, 0);
		else
			t.xxor(l, r);
		writeln(t.find());
	}
	flushout();
	return 0;
}