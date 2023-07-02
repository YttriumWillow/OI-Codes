// Problem:      Physical Education Lessons
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/CF915E
// Memory Limit: 250 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-28 20:07:46 

// Problem:      Willem, Chtholly and Seniorious
// Contest:      Luogu
// URL:          https://www -> luogu.com.cn/problem/CF896C
// Memory Limit: 250 MB
// Time Limit:   2000 ms
// Created Time: 2023-04-27 20:43:07 

#include <iostream>

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

int n, m, sum, q;

#include <set>
#include <vector>
#include <algorithm>
#define pb push_back

template<typename Tp>
struct ChthollyTree
{
	struct Node
	{
		Tp l, r;
		mutable Tp v;
		Node(Tp l, Tp r = 0, Tp v = 0): l(l), r(r), v(v) {}
		inline friend operator < (const Node& _x, const Node& _y)
		{ return _x.l < _y.l; }
	};
	set<Node> s;
	inline void insert(Tp pos, Tp x) { s.insert(Node(pos, pos, x)); }
	inline void init(Tp n, Tp i) { s.insert(Node(1, n, i)); }
	auto split(Tp pos)
	{
		auto it = s.lower_bound(Node(pos));
		if (it != s.end() && it->l == pos)
			return it;
		--it;
		if (it -> r < pos)
			return s.end();
		Tp l = it -> l, r = it -> r, v = it -> v;
		s.erase(it);
		s.insert(Node(l, pos - 1, v));
		return s.insert(Node(pos, r, v)).first;
	}
	inline void add(Tp l, Tp r, Tp x)
	{
		auto itr = split(r + 1), itl = split(l);
		for (auto it = itl; it != itr; ++it)
			it -> v += x;
	}
	inline void assign(Tp l, Tp r, Tp x)
	{
		auto itr = split(r + 1), itl = split(l), it = itl;
		for (; it != itr; ++it)
			sum -= it -> v * (it -> r - it -> l + 1);
		s.erase(itl, itr);
		s.insert(Node(l, r, x));
		sum += x * (r - l + 1);
	}
};
ChthollyTree<int> t;
int main()
{
	read(n, q); t.init(n, 1); sum = n;
	for (reg int i = 1, l, r, k; i <= q; ++i)
	{
		read(l, r, k);
		if (k == 1) t.assign(l, r, 0);
		if (k == 2) t.assign(l, r, 1);
		writeln(sum);
	}
	flushout();
	return 0;
}