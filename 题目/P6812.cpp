// Problem:      P6812 「MCOI-02」Ancestor 先辈
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P6812
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-12 16:08:25

#include <iostream>

#include <cstring>

#define i64 long long
#define reg register
#define endl '\n'
#define ls (p << 1)
#define rs (p << 1 | 1)
#define pushup(p) t[p].min = min(t[ls].min, t[rs].min);
#define qwq puts("fzy qwq ~");

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
    inline void write(_Tp x, char end = '\n')
    {
        if (outl > outr) { flushout(); }
        if (x < 0) { *outl++ = '-'; x = -x; }
        char sta[20]; char *top = sta;
        do { *top++ = (x % 10) + '0'; x /= 10; } while (x);
        do { *outl++ = *--top; } while (top != sta);
        (*outl++) = end;
    }
}
using namespace bufIO;

namespace ExtIO
{
	// read
    template<typename _Tp, typename ...Args>
    inline void read(_Tp& x, Args& ...args) { read(x), read(args...); }
    
    // readchar
    inline void readchar(char& x) { for (x = getchar(); !std::isalpha(x); x = getchar()); }

    // readln
    template<typename _Tp, typename _Tpp>
    inline void readln(_Tp a[], _Tpp w) { for (reg _Tpp i = 1; i <= w; ++i) read(a[i]); }
    template<typename _Tp, typename _Tpp>
    inline void readln(_Tp a[], _Tpp l, _Tpp r) { for (reg _Tpp i = l; i <= r; ++i) read(a[i]); }

    // writespace
    template<typename _Tp>
    inline void writespace(_Tp x) { write(x); putchar(' '); }
    template<typename _Tp, typename ...Args>
    inline void writespace(_Tp& x, Args& ...args) { writespace(x), writespace(args...); }

    // writeln
    template<typename _Tp>
    inline void writeln(_Tp x) { write(x); putchar('\n'); }
    template<typename _Tp, typename ...Args>
    inline void writeln(_Tp& x, Args& ...args) { writespace(x), writespace(args...), putchar('\n'); }
    template<typename _Tp, typename _Tpp>
    inline void writeln(_Tp a[], _Tpp w) { for (reg _Tpp i = 1; i <= w; ++i) writespace(a[i]); putchar('\n'); }
    template<typename _Tp, typename _Tpp>
    inline void writeln(_Tp a[], _Tpp l, _Tpp r) { for (reg _Tpp i = l; i <= r; ++i) writespace(a[i]); putchar('\n'); }
};
using namespace ExtIO;

using namespace std;

const int inf = 0x7fffffff;

int n, k;
int opt, l, r, x;
int a[1000010], dif[1000010];
struct Node { int l, r, min = inf; } t[4000010];

inline void build(int p, int l, int r)
{
    t[p].l = l; t[p].r = r;
    if (l == r) { t[p].min = dif[l]; return; }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(p);
}
inline void modify(int p, int x, int y)
{
	if (t[p].l == t[p].r) { t[p].min += y; return; }
	int mid = (t[p].l + t[p].r) >> 1;
	if (x <= mid)	modify(ls, x, y);
	else			modify(rs, x, y);
	pushup(p);
}
inline int query(int p, int l, int r) 
{
	if (l <= t[p].l && t[p].r <= r) { return t[p].min; }
	int mid = (t[p].l + t[p].r) >> 1;
	int ans = inf;
	if (l <= mid)	ans = min(ans, query(ls, l, r));
	if (mid  < r)	ans = min(ans, query(rs, l, r));
	return ans;
}

int main()
{
    read(n, k);
    for (reg int i = 1; i <= n; ++i)
        read(a[i]), dif[i] = a[i] - a[i - 1];
    build(1, 1, n);
    while (k--)
    {
        read(opt, l, r); if (r > n) { r = n; }
        if (opt == 1)
        {
        	read(x);
			modify(1, l, x);
			modify(1, r + 1, -x);
        }
        else
        {
        	cout << (query(1, l + 1, r) >= 0 ? "Yes" : "No") << endl;
        }
    }
    flushout();
    return 0;
}