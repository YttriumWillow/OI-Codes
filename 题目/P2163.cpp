// Problem:      P2163 [SHOI2007]园丁的烦恼
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2163
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-06-05 21:39:21 

// Problem:      P4390 [BalkanOI2007] Mokia 摩基亚
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P4390
// Memory Limit: 125 MB
// Time Limit:   2000 ms
// Created Time: 2023-06-04 19:20:55 

// Problem:      P3810 【模板】三维偏序（陌上花开）
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3810
// Memory Limit: 500 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-27 21:09:30

#include <iostream>

#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

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
using namespace std;

const int N = 1e7 + 10;

struct Node
{
	int t, x, y, val, id; Node() {}
	Node(int t, int x, int y, int v, int id):
		t(t), x(x), y(y), val(v), id(id) {}
};

template<typename Tp>
struct BIT
{
    #define lowbit(x) (x & -x)
    Tp t[N] = { 0 }; int len = 0;
    inline void init(int n) { len = n; }
    inline void add(const Tp& x, const Tp& v)
    {
        for (int i = x; i <= len; i += lowbit(i))
            t[i] += v;	
    }
    inline Tp query(const Tp& x)
    {
        Tp res = 0;
        for (int i = x; i; i -= lowbit(i))
            res += t[i];
        return res;
    }
};

inline bool cmpP(const Node& _x, const Node& _y)
{ return (_x.x != _y.x ? _x.x < _y.x : _x.y < _y.y); }

inline bool cmpT(const Node& _x, const Node& _y)
{ return _x.t < _y.t; }

Node e[N];
BIT<int> t;
int n, m, cnt, w;
int x, y, opt;
int x1, y1, x2, y2;

inline void CDQ(int l, int r)
{
    if (l == r) return;
    int mid = (l + r) >> 1;
    CDQ(l, mid); CDQ(mid + 1, r);
    sort(e + l, e + mid + 1, cmpP);
    sort(e + mid + 1, e + r + 1, cmpP);
    int i = l;
    for (int j = mid + 1; j <= r; ++j)
    {
        for (; i <= mid && e[i].x <= e[j].x; ++i)
            if (!e[i].id)
            	t.add(e[i].y, e[i].val);	
        if (e[j].id) e[j].val += t.query(e[j].y);
    }
    for (int j = l; j < i; ++j)
    	if (!e[j].id)
        	t.add(e[j].y, -e[j].val);
}

int main()
{
    read(n, m); cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
    	read(x, y); ++x, ++y;
    	e[++cnt] = Node(cnt, x, y, 1, 0);
    }
    for (int i = 1; i <= m; ++i)
    {
    	read(x1, y1, x2, y2); ++ x2, ++y2;
    	w = max({ w, x2, y2 });
    	e[++cnt] = Node(cnt, x1, y1, 0, 1);
    	e[++cnt] = Node(cnt, x2, y2, 0, 1);
    	e[++cnt] = Node(cnt, x1, y2, 0, 1);
    	e[++cnt] = Node(cnt, x2, y1, 0, 1);
    }
    t.init(w + 10); CDQ(1, cnt);
    sort(e + 1, e + cnt + 1, cmpT);
    for (int i = 1; i <= cnt; ++i)
    {
    	if (e[i].id)
    	{
    		writeln(e[i].val + e[i + 1].val - e[i + 2].val - e[i + 3].val);
    		i += 3;	
    	}
    }
    flushout();
    return 0;
}