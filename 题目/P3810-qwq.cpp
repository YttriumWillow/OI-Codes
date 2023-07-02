// Problem:      P3810 【模板】三维偏序（陌上花开）
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3810
// Memory Limit: 500 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-27 21:09:30

// Problem:      P3810 【模板】三维偏序（陌上花开）
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3810
// Memory Limit: 500 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-24 16:55:28

#include <iostream>

#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");
#define lowbit(x) (x & -x)

namespace IO
{
    #define reg register
    template<typename _Tp>
    inline void read(_Tp& x)
    {
        x = 0; char c = getchar(); bool f = 0;
        while (!std::isdigit(c)) f |= c == 45, c = getchar();
        while ( std::isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
        return f ? x = -x : 1, void();
    }
    template<typename _Tp>
    inline void write(_Tp x)
    {
        static char stk[40]; int top = 0;
        if (!x)     return putchar(48), void();
        if (x < 0)  putchar(45), x = -x;
        while (x)   stk[top++] = x % 10, x /= 10;
        while (top) putchar(stk[--top] + 48);
    }

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
using namespace IO;
using namespace std;

int n, k;

struct Node
{
	int a, b, c, cnt, res;
    friend bool operator != (const Node &_x, const Node &_y)
    {
        if (_x.a != _y.a) return 1;
        if (_x.b != _y.b) return 1;
        if (_x.c != _y.c) return 1;
        return 0;
    }
};

int tree[200010];
inline void add(const int& pos, const int& v)
{
    for (reg int i = pos; i <= k; i += lowbit(i))
        tree[i] += v;
}
inline int query(const int& pos)
{
    reg int res = 0;
    for (reg int i = pos; i; i -= lowbit(i))
        res += tree[i];
    return res;
}

inline bool cmpX(const Node& _x, const Node& _y)
{
    if (_x.a != _y.a)
        return _x.a < _y.a;
    if (_x.b != _y.b)
        return _x.b < _y.b;
    return _x.c < _y.c;
}

inline bool cmpY(const Node& _x, const Node& _y)
{
    if (_x.b != _y.b)
        return _x.b < _y.b;
    return _x.c < _y.c;
}

Node e[200010];
Node ue[200010];
int m, t;
int ans[200010];

inline void CDQ(const int& l, const int& r)
{
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    CDQ(l, mid); CDQ(mid + 1, r);
    sort(ue + l, ue + mid + 1, cmpY);
    sort(ue + mid + 1, ue + r + 1, cmpY);
    reg int i = l, j = mid + 1;
    while (j <= r)
    {
        while (i <= mid && ue[i].b <= ue[j].b)
            add(ue[i].c, ue[i].cnt), ++i;
        ue[j].res += query(ue[j].c);
        ++j;
    }
    for (reg int k = l; k < i; ++k)
        add(ue[k].c, -ue[k].cnt);
}

int main()
{
    read(n, k);
    for (reg int i = 1; i <= n; ++i)
        read(e[i].a, e[i].b, e[i].c);
    sort(e + 1, e + n + 1, cmpX);
    for (reg int i = 1; i <= n; ++i)
    {
        ++t;
        if (e[i] != e[i + 1])
        {
            ++m;
            ue[m] = e[i];
            ue[m].cnt = t;
            t = 0;
        }
    }
    CDQ(1, m);
    for (reg int i = 1; i <= m; ++i)
        ans[ue[i].res + ue[i].cnt - 1] += ue[i].cnt;
    for (reg int i = 0; i < n; ++i)
        writeln(ans[i]);
    return 0;
}