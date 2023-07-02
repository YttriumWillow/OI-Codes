// Problem:      P3391 【模板】文艺平衡树
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3391
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-24 19:18:18 

#include <bits/stdc++.h>
#include <ext/rope>

#define i64 long long
#define qwq puts("fzy qwq ~");
#define pb push_back

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
using namespace __gnu_cxx;

int n, m, l, r;
rope<int> a, b;

void reverse(int l, int r)
{
    if (l == r) return;
    rope<int> tmp = a.substr(--l + a.begin(), r + a.begin());
    a = a.substr(a.begin(), l + a.begin())
        + b.substr(n - r + b.begin(), n - l + b.begin())
        + a.substr(r + a.begin(), a.length() + a.begin());
    b = b.substr(b.begin(), n - r + b.begin())
        + tmp + b.substr(n - l + b.begin(), b.length() + b.begin());
}

int main()
{
	read(n, m);
	for (int i = 1; i <= n; ++i)
        a.append(i), b.append(n - i + 1);
    while (m--)
    {
        read(l, r);
        reverse(l, r);
    }
    for (auto x : a)
        writespace(x);
	return 0;	
}