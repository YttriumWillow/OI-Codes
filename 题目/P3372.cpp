// Problem:      P3372 【模板】线段树 1
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3372
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-24 14:28:02

#include <iostream>

#define i64 long long
#define qwq puts("fzy qwq ~");
#define ls(k) ((k) << 1)
#define rs(k) ((k) << 1 | 1)
#define nownode tree[now]
#define leftson tree[ls(now)]
#define rightson tree[rs(now)]

namespace IO
{
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
        static char stk[40]; i64 top = 0;
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
    inline void readln(_Tp a[], _Tpp faq) { for (_Tpp i = 1; i <= faq; ++i) read(a[i]); }
    template<typename _Tp, typename _Tpp>
    inline void readln(_Tp a[], _Tpp l, _Tpp r) { for (_Tpp i = l; i <= r; ++i) read(a[i]); }

    // writespace
    template<typename _Tp>
    inline void writespace(_Tp x) { write(x); putchar(' '); }
    template<typename _Tp, typename ...Args>
    inline void writespace(_Tp& x, Args& ...args) { writespace(x), writespace(args...); }

    // writeln
    template<typename _Tp>
    inline void writeln(_Tp x) { write(x); putchar('\n'); }
    template<typename ...Args>
    inline void writeln(Args& ...args) { writespace(args...), putchar('\n'); }
    template<typename _Tp, typename _Tpp>
    inline void writeln(_Tp a[], _Tpp faq) { for (_Tpp i = 1; i <= faq; ++i) writespace(a[i]); putchar('\n'); }
    template<typename _Tp, typename _Tpp>
    inline void writeln(_Tp a[], _Tpp l, _Tpp r) { for (_Tpp i = l; i <= r; ++i) writespace(a[i]); putchar('\n'); }
};
using namespace IO;
using namespace std;

i64 n, m, p;
i64 opt, x, y;
i64 a[200010], k;

struct Node
{
	i64 l, r;
	i64 val, tag;
	i64 siz() { return r - l + 1; }
} tree[400010];

void pushup(i64 now) { nownode.val = leftson.val + rightson.val; }

void pushdown(i64 now)
{
	if (nownode.tag)
	{
		leftson.val += nownode.tag * leftson.siz();
		rightson.val += nownode.tag * rightson.siz();
		leftson.tag += nownode.tag;
		rightson.tag += nownode.tag;
		nownode.tag = 0;
	}
}

void build(i64 l, i64 r, i64 now)
{
	nownode.l = l; nownode.r = r;
	if (l == r) { nownode.val = a[l]; return; cerr<<"faq\n";}
	i64 mid = (l + r) >> 1;
	build(l, mid, ls(now));
	build(mid + 1, r, rs(now));
	pushup(now);
}

void add(i64 l, i64 r, i64 now, i64 k)
{
	if (l <= nownode.l && nownode.r <= r)
	{
		nownode.val += k * nownode.siz();
		nownode.tag += k;
		return;
	}
	pushdown(now);
	i64 mid = (nownode.l + nownode.r) >> 1;
	if (x <= mid)     add(l, r, ls(now), k);
	if (y >= mid + 1) add(l, r, rs(now), k);
	pushup(now);
}

i64 query(i64 l, i64 r, i64 now)
{
	if (l <= nownode.l && nownode.r <= r)
		return nownode.val;
	pushdown(now);
	i64 mid = (nownode.l + nownode.r) >> 1;
	i64 ans = 0;
	if (l <= mid)
		ans += query(l, r, ls(now));
	if (mid + 1 <= r)
		ans += query(l, r, rs(now));
	return ans;
}

int main()
{
    read(n, m);
    readln(a, n);
	build(1, n, 1);
    while (m--)
    {
        read(opt, x, y);
        switch (opt)
        {
        case 1: read(k), add(x, y, 1, k); break;
        case 2: writeln(query(x, y, 1)); break;
        default: qwq
        }
    }
    return 0;
}