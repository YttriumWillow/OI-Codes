// Problem:      P3801 红色的幻想乡
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3801
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-11 19:41:07 

#include <iostream>

#include <cstring>

#define i64 long long 
#define reg register
#define lowbit(x) (x & -x)
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
}
using namespace IO;

namespace ExtIO
{
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
using namespace ExtIO;

using namespace std;

int n, m, q;
int x, y, opt;
int ex, ey, sx, sy;
i64 xx[100010], yy[100010];
bool dx[100010], dy[100010];

inline void add(i64 t[], int p, i64 v)
{
	int tmp = (t == xx ? n : m);
	for (reg int i = p; i <= tmp; i += lowbit(i))
		t[i] += v;
}

inline i64 sum(i64 t[], int p)
{
	reg i64 res = 0;
	for (reg int i = p; i; i -= lowbit(i))
		res += t[i];
	return res;
}

inline i64 query(i64 t[], int l, int r) { return sum(t, r) - sum(t, l - 1); }

inline void Change(int x, int y)
{
	add(xx, x, (dx[x] ? -1 : 1)); dx[x] ^= 1; 
	add(yy, y, (dy[y] ? -1 : 1)); dy[y] ^= 1;
}

inline i64 Query(int sx, int sy, int ex, int ey)
{
	i64 tx = query(xx, sx, ex); int lx = (ex - sx + 1);
	i64 ty = query(yy, sy, ey); int ly = (ey - sy + 1);
	return tx * ly + ty * lx - 2 * tx * ty;
}

int main()
{
	read(n, m, q);
	while (q--)
	{
		read(opt);
		switch (opt)
		{
		case 1: read(x, y); Change(x, y); break;
		case 2: read(sx, sy, ex, ey); writeln(Query(sx, sy, ex, ey)); break;
		default: qwq
		}
	}
	return 0;
}