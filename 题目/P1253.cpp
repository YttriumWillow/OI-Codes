// Problem:      P1253 [yLOI2018] 扶苏的问题
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1253
// Memory Limit: 512 MB
// Time Limit:   2000 ms
// Created Time: 2023-03-25 09:29:47 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");
#define ls(k) ((k) << 1ll)
#define rs(k) ((k) << 1ll | 1ll)
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
    inline void readln(_Tp a[], _Tpp faq) { for (reg _Tpp i = 1; i <= faq; ++i) read(a[i]); }
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
    template<typename ...Args>
    inline void writeln(Args& ...args) { writespace(args...), putchar('\n'); }
    template<typename _Tp, typename _Tpp>
    inline void writeln(_Tp a[], _Tpp faq) { for (reg _Tpp i = 1; i <= faq; ++i) writespace(a[i]); putchar('\n'); }
    template<typename _Tp, typename _Tpp>
    inline void writeln(_Tp a[], _Tpp l, _Tpp r) { for (reg _Tpp i = l; i <= r; ++i) writespace(a[i]); putchar('\n'); }
};
using namespace IO;
using namespace std;

const i64 faq = 1145141919810;
const i64 inf = 0xffffffffffff;

struct Node
{
    i64 l, r;
    i64 max, add, cvr;
    i64 siz() { return r - l + 1; }
} tree[16000010];

i64 a[4000010];
i64 n, q;
i64 l, r, x, opt;

// push faqing lazytags
// what should i do if there is much more tags :(
inline void pushup(i64 now) { nownode.max = max(leftson.max, rightson.max); }
inline void cvrdown(i64 now)
{
	if (nownode.cvr != faq)
	{
		leftson.add = rightson.add = 0;
		leftson.max = rightson.max = nownode.cvr;
		leftson.cvr = rightson.cvr = nownode.cvr;
		nownode.cvr = faq;
	}
}
inline void adddown(i64 now)
{
	if (nownode.add)
	{
		//cvrdown(now);
		leftson.max += nownode.add; rightson.max += nownode.add;
		leftson.add += nownode.add; rightson.add += nownode.add;
		nownode.add = 0;
	}
}
inline void pushdown(i64 now) { cvrdown(now); adddown(now); }

// operators
inline void build(i64 now, i64 l, i64 r)
{
    nownode.l = l; nownode.r = r; nownode.cvr = faq; nownode.add = 0;
    if (l == r) { nownode.max = a[l]; return; }
    i64 mid = (l + r) >> 1;
    build(ls(now), l, mid);
    build(rs(now), mid + 1, r);
    pushup(now);
}

inline void add(i64 now, i64 l, i64 r, i64 k)
{
	if (l <= nownode.l && nownode.r <= r)
	{
		// pushdown(now);
		nownode.max += k;
		nownode.add += k;
		return;
	}
	pushdown(now);
	i64 mid = (nownode.l + nownode.r) >> 1;
	if (l <= mid)     add(ls(now), l, r, k);
	if (r >= mid + 1) add(rs(now), l, r, k);
	pushdown(now);
	pushup(now);
}

inline void cvr(i64 now, i64 l, i64 r, i64 k)
{
	if (l <= nownode.l && nownode.r <= r)
	{
		pushdown(now);
		nownode.add = 0;
		nownode.max = k;
		nownode.cvr = k;
		return;
	}
	pushdown(now);
	i64 mid = (nownode.l + nownode.r) >> 1;
	if (l <= mid)     cvr(ls(now), l, r, k);
	if (r >= mid + 1) cvr(rs(now), l, r, k);
	pushdown(now);
	pushup(now);
}

inline i64 query(i64 now, i64 l, i64 r)
{
	if (l <= nownode.l && nownode.r <= r) { return nownode.max; }
	pushdown(now);
	i64 mid = (nownode.l + nownode.r) >> 1;
	i64 res = -inf;
	if (l <= mid)     res = max(res, query(ls(now), l, r));
	if (mid + 1 <= r) res = max(res, query(rs(now), l, r));
	return res;
}

int main()
{
	read(n, q);
	readln(a, n);
	build(1, 1, n);
	while (q--)
	{
		read(opt, l, r);
		switch (opt)
		{
		case 1: read(x); cvr(1, l, r, x); break;
		case 2: read(x); add(1, l, r, x); break;	
		case 3: writeln(query(1, l, r)); break;
		default: qwq
		}
	}
    return 0;
}