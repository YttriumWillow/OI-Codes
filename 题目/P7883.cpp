// Problem:      P7883 平面最近点对（加强加强版）
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P7883
// Memory Limit: 512 MB
// Time Limit:   350000 ms
// Created Time: 2023-03-28 20:44:07 

// Problem:      P1429 平面最近点对（加强版）
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1429
// Memory Limit: 256 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-28 20:15:01 

#include <iostream>

#include <cmath>
#include <ctime>
#include <random>
#include <iomanip>
#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

#pragma GCC target("ssse3","sse3","sse2","sse","avx2","avx","avx512f","sse4.1","sse4.2")

// for special purpose
#define randrad() ((rand() % 360) / 180.0 * Pi)
#define getdis(p, q) (hypot(a[p].x - a[q].x, a[p].y - a[q].y))

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

const double Pi = acos(-1.0);

struct Node
{
	double x, y;
	inline friend bool operator < (const Node& _x, const Node& _y) { return _x.x * _x.y < _y.x * _y.y; }
} a[400010];

int n;
double ans = 1145141919810000;

inline void rotate(const double& rad)
{
	for (reg int i = 1; i <= n; ++i)
	{
		double xx = a[i].x, yy = a[i].y;
		double nx = xx * cos(rad) - yy * sin(rad);
		double ny = xx * sin(rad) + yy * cos(rad);
		a[i].x = nx, a[i].y = ny;
	}
}

inline void faq()
{
	for (reg int i = 1; i <= n; ++i)
		for (reg int j = i + 1; j <= i + 60 && j <= n; ++j)
			ans = min(ans, getdis(i, j));
}

inline void cheat()
{
	// rotate(        0); sort(a + 1, a + n + 1); faq();
	rotate(randrad()); sort(a + 1, a + n + 1); faq();
	// rotate(randrad()); sort(a + 1, a + n + 1); faq();
}

int main()
{
	srand(1234978012);
	read(n);
	for (reg int i = 1, tx, ty; i <= n; ++i)
		read(tx, ty), 
		a[i].x = tx, 
		a[i].y = ty;
	cheat();
	printf("%.0lf\n", ans * ans);
	return 0;
}