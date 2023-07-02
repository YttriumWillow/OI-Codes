// Problem:      P3834 【模板】可持久化线段树 2
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3834
// Memory Limit: 256 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-06 19:18:24 

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

int n, m, q, cnt;
int a[32000010];
int rt[32000010];
int ver, opt, rnk, val;

struct Node
{
	int val;
	int son[2];
} PsdTree[50000010];



int main()
{
	read(n, q);
	readln(a, n);
	rt[0] = build(0, 1, n);
	for (reg int i = 1; i <= n; ++i)
		sep[i] = a[i];
	sort(sep + 1, sep + n + 1);
	m = unique(sep + 1, sep + n + 1) - sep - 1;
	for (reg int i = 1; i <= n; ++i)
	{
		rnk = lower_bound(sep + 1, sep + n + 1, a[i]) - m;
		modify(rt[ver - 1], 1, m, rnk);
	}
	while (q--)
	return 0;
}