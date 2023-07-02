// Forked from Matrix_mlt[498779]
//  + Original (原生功能)
//     + Functions
//        + read()       // 2 Overloaded
//        + readchar()   // Non-overloaded
//        + write()      // Non-overloaded
// Pull Request from fengziyi[540226]
//  + Submitted (已追加功能)
//     + Functions
//        + readln()     // 2 Overloaded
//        + writespace() // 2 Overloaded
//        + writeln()    // 4 Overloaded
//  + Unsubmitted (待完善)
//     + Float Number Reading Functions
//     + Big Interger Functions
//     + ...

#include <iostream>
#include <cctype>

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

int n;
int a[114514];
int p, q, r;

int main()
{
    read(n);

    readln(a, n);
    writeln(a, n);

    readln(a, 3, 5);
    writeln(a, n);
    writeln(a, 0, 4);

    putchar('\n');

    read(p, q, r);
    writeln(p, q, r);

    return 0;
}