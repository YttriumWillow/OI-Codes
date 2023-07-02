// Problem:	P3919 【模板】可持久化线段树 1（可持久化数组）
// Contest:	Luogu
// URL:	https://www.luogu.com.cn/problem/P3919
// Memory Limit:	1 GB
// Time Limit:	1500 ms
// Created Time:	2023-04-01 20:22:07 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

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

int n, m, cnt;
int a[32000010];
int rt[32000010];
int ver, opt, loc, val;

struct Node
{
	int val;
	int son[2];
} PsdTree[50000010];

inline int newnode(int now)
{
	++cnt;
	PsdTree[cnt] = PsdTree[now];
	return cnt;
}

inline int build(int now, int l, int r)
{
	now = ++cnt;
	if (l == r) { PsdTree[now].val = a[l]; return cnt; }
	int mid = (l + r) >> 1;
	PsdTree[now].son[0] = build(PsdTree[now].son[0], l, mid);
	PsdTree[now].son[1] = build(PsdTree[now].son[1], mid + 1, r);
	return now;
}

inline int modify(int now, int l, int r, int loc, int val)
{
	now = newnode(now);
	if (l == r) { PsdTree[now].val = val; }
	else
	{
		int mid = (l + r) >> 1;
		if (loc <= mid) PsdTree[now].son[0] = modify(PsdTree[now].son[0], l, mid, loc, val);
		else 			PsdTree[now].son[1] = modify(PsdTree[now].son[1], mid + 1, r, loc, val);
	}
	return now;
}

inline int query(int now, int l, int r, int loc)
{
	if (l == r) { return PsdTree[now].val; }
	else
	{
		int mid = (l + r) >> 1;
		if (loc <= mid) return query(PsdTree[now].son[0], l, mid, loc);
		else			return query(PsdTree[now].son[1], mid + 1, r, loc);
	}
}

int main()
{
	read(n, m);
	readln(a, n);
	rt[0] = build(0, 1, n);
	for (reg int i = 1; i <= m; ++i)
	{
		read(ver, opt, loc);
		switch (opt)
		{
			case 1: read(val); rt[i] = modify(rt[ver], 1, n, loc, val);     break;
			case 2: writeln(query(rt[ver], 1, n, loc)); rt[i] = rt[ver];    break;
			default: qwq
		}
	}
	return 0;
}