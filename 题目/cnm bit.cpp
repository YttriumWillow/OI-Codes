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

i64 n, m, faq;
i64 t1[500010];
i64 t2[500010];

inline void add(const reg i64& k, const reg i64& v)
{
	reg i64 kv = k * v;
	for (reg int i = k; i <= n; i += lowbit(i))
		t1[i] += v, t2[i] += kv;
}

inline i64 getsum(reg i64 t[], const reg i64& k)
{
	reg i64 res = 0;
	for (reg int i = k; i; i -= lowbit(i))
		res += t[i];
	return res;
}

inline void addRange(const reg i64& l, const reg i64& r, const reg i64& v)
{
	add(l, v), add(r + 1, -v);
}

inline i64 queryRange(const reg i64& l, const reg i64& r)
{
	return (r + 1) * getsum(t1, r) - l * getsum(t1, l - 1) - (getsum(t2, r) - getsum(t2, l - 1));
}

int main()
{
    read(n, m);
    for (reg int i = 1, x; i <= n; ++i)
        read(x), addRange(i, i, x);
    for (reg int i = 1, opt, l, r, k; i <= m; ++i)
    {
        read(opt);
        switch(opt)
        {
        case 1: read(l, r, k); addRange(l, r, k); break;
        case 2: read(k); addRange(1, 1, k); break;
        case 3: read(k), addRange(1, 1, -k); break;
        case 4: read(l, r); writeln(queryRange(l, r)); break;
        case 5: writeln(queryRange(1, 1)); break;
        }
    }
    return 0;
}