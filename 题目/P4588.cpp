// Problem:      P4588 [TJOI2018]数学计算
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P4588
// Memory Limit: 250 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-07 16:15:54 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");
#define ls (p << 1)
#define rs (p << 1 | 1)

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

i64 t[4000010];
i64 n, M, T;
i64 mod, p;
i64 a, b;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	read(T);
    while (T--)
    {
    	read(n, mod);
        
        M = 1; while (M <= n) M <<= 1;
        for (reg int i = 1; i <= M + n + 1; ++i)
        	t[i] = 1;
        
        for (reg int i = 1; i <= n; ++i)
        {
            read(a, b);
            if (a == 1)
            	p = i + M, t[p] = b % mod;
            else
            	p = b + M, t[p] = 1;
            while (p >>= 1)
            	t[p] = t[ls] * t[rs] % mod;
            writeln(t[1]);
        }
    }
    return 0;
}
