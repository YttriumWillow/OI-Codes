// Problem:      P2357 守墓人
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2357
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-25 08:10:57 

#include <iostream>

#define i64 long long
#define qwq puts("fzy qwq ~");
#define lowbit(x) (x & -x)

namespace IO
{
	#define reg register
    template<typename _Tp>
    inline void read(reg _Tp& x)
    {
        x = 0; reg char c = getchar(); reg bool f = 0;
        while (!std::isdigit(c)) f |= c == 45, c = getchar();
        while ( std::isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
        return f ? x = -x : 1, void();
    }
    template<typename _Tp>
    inline void write(reg _Tp x)
    {
        static char stk[40]; reg int top = 0;
        if (!x)     return putchar(48), void();
        if (x < 0)  putchar(45), x = -x;
        while (x)   stk[top++] = x % 10, x /= 10;
        while (top) putchar(stk[--top] + 48);
    }

    // read
    template<typename _Tp, typename ...Args>
    inline void read(reg _Tp& x, Args& ...args) { read(x), read(args...); }

    // readchar
    inline void readchar(reg char& x) { for (x = getchar(); !std::isalpha(x); x = getchar()); }

    // readln
    template<typename _Tp, typename _Tpp>
    inline void readln(reg _Tp a[], reg _Tpp& faq) { for (reg _Tpp i = 1; i <= faq; ++i) read(a[i]); }
    template<typename _Tp, typename _Tpp>
    inline void readln(reg _Tp a[], reg _Tpp& l, reg _Tpp& r) { for (reg _Tpp i = l; i <= r; ++i) read(a[i]); }

    // writespace
    template<typename _Tp>
    inline void writespace(const reg _Tp& x) { write(x); putchar(' '); }
    template<typename _Tp, typename ...Args>
    inline void writespace(const reg _Tp& x, Args& ...args) { writespace(x), writespace(args...); }

    // writeln
    template<typename _Tp>
    inline void writeln(const reg _Tp& x) { write(x); putchar('\n'); }
    template<typename ...Args>
    inline void writeln(Args& ...args) { writespace(args...), putchar('\n'); }
    template<typename _Tp, typename _Tpp>
    inline void writeln(const reg _Tp a[], const reg _Tpp& faq) { for (reg _Tpp i = 1; i <= faq; ++i) writespace(a[i]); putchar('\n'); }
    template<typename _Tp, typename _Tpp>
    inline void writeln(const reg _Tp a[], const reg _Tpp& l, const reg _Tpp& r) { for (reg _Tpp i = l; i <= r; ++i) writespace(a[i]); putchar('\n'); }
};
using namespace IO;
using namespace std;

i64 n, m, lst, faq;
i64 sum1[500010];
i64 sum2[500010];

inline void add(const reg i64& pos, const reg i64& x)
{
    for (reg int i = pos; i <= n; i += lowbit(i))
        sum1[i] += x, sum2[i] += pos * x;
}
inline i64 query(const reg i64& pos)
{
    reg i64 res = 0;
    for (reg int i = pos; i; i -= lowbit(i))
        res += (pos + 1) * sum1[i] - sum2[i];
    return res;
}
inline i64 range(const reg i64& l, const reg i64& r) { return query(r) - query(l - 1); }
inline void modify(const reg i64& l, const reg i64& r, const reg i64& x) { add(l, x); add(r + 1, -x); }

int main()
{
	reg i64 x, y, z, opt;
    read(n, m);
    for (reg int i = 1; i <= n; ++i)
        read(x), add(i, x - lst), lst = x;
    for (reg int i = 1; i <= m; ++i)
    {
        read(opt);
        switch (opt)
        {
        case 1: read(x, y, z); modify(x, y, z); break;
        case 2: read(z); faq += z; break;
        case 3: read(z); faq -= z; break;
        case 4: read(x, y); writeln(range(x, y) + (x == 1) * faq); break;
        case 5: writeln(query(1) + faq);
        }
    }
}