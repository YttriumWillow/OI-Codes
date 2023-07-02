// Problem:      P3373 【模板】线段树 2
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3373
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-24 15:09:14 

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
	i64 sum, mul, tag;
	i64 siz() { return r - l + 1; }
} tree[400010];

void pushup(i64 now) { nownode.sum = (leftson.sum + rightson.sum) % p; }

void pushdown(i64 now)
{
	leftson.sum = (leftson.sum * nownode.mul + (nownode.tag * leftson.siz()) % p) % p;
	rightson.sum = (rightson.sum * nownode.mul + (nownode.tag * rightson.siz()) % p) % p;
		
	leftson.mul = (leftson.mul * nownode.mul % p) % p;
	rightson.mul = (rightson.mul * nownode.mul % p) % p;
		
	leftson.tag = ((leftson.tag * nownode.mul) % p + nownode.tag) % p;
	rightson.tag = ((rightson.tag * nownode.mul) % p + nownode.tag) % p;
		
	nownode.mul = 1;
	nownode.tag = 0;
}

void build(i64 l, i64 r, i64 now)
{
	nownode.l = l; nownode.r = r; nownode.mul = 1;
	if (l == r) { nownode.sum = a[l] % p; return;  }
	i64 mid = (l + r) >> 1;
	build(l, mid, ls(now));
	build(mid + 1, r, rs(now));
	pushup(now);
}

void add(i64 l, i64 r, i64 now, i64 k)
{
	if (l <= nownode.l && nownode.r <= r)
	{
		nownode.sum = (nownode.sum + k * nownode.siz() % p) % p;
		nownode.tag = (nownode.tag + k) % p;
		return;
	}
	pushdown(now);
	pushup(now);
	i64 mid = (nownode.l + nownode.r) >> 1;
	if (l <= mid)     add(l, r, ls(now), k);
	if (mid + 1 <= r) add(l, r, rs(now), k);
	pushup(now);
}

void mul(i64 l, i64 r, i64 now, i64 k)
{
	if (l <= nownode.l && nownode.r <= r)
	{
		nownode.sum = (nownode.sum * k) % p;
		nownode.mul = (nownode.mul * k) % p;
		nownode.tag = (nownode.tag * k) % p;
		return;
	}
	pushdown(now);
	pushup(now);
	i64 mid = (nownode.l + nownode.r) >> 1;
	if (l <= mid)     mul(l, r, ls(now), k);
	if (mid + 1 <= r) mul(l, r, rs(now), k);
	pushup(now);
}

i64 query(i64 l, i64 r, i64 now)
{
	if (l <= nownode.l && nownode.r <= r)
		return nownode.sum;
	pushdown(now);
	i64 mid = (nownode.l + nownode.r) >> 1;
	i64 ans = 0;
	if (l <= mid)
		ans = (ans + query(l, r, ls(now)) % p) % p;
	if (mid + 1 <= r)
		ans = (ans + query(l, r, rs(now)) % p) % p;
	return ans % p;
}

int main()
{
    read(n, m, p);
    readln(a, n);
	build(1, n, 1);
    while (m--)
    {
        read(opt, x, y);
        switch (opt)
        {
        case 1: read(k), mul(x, y, 1, k); break;
        case 2: read(k), add(x, y, 1, k); break;
        case 3: writeln(query(x, y, 1)); break;
        default: qwq
        }
    }
    return 0;
}