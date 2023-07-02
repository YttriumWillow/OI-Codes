// Problem:      P1503 鬼子进村
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1503
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-20 20:04:59 

#include <iostream>

#include <vector>
#include <algorithm>

#define i64 long long
#define reg register
#define pb push_back
#define db pop_back
#define qwq puts("fzy qwq ~");

using namespace std;
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

char opt;
int n, m, x;
bool dead[50010];
vector<int> d;

// wait what is this really a balanced tree
struct BalancedTree
{
	vector<int> t; vector<int>::iterator pos = t.begin();
	inline void getpos(int x) { pos = lower_bound(t.begin(), t.end(), x); }
	inline void insert(int x) { getpos(x); t.insert(pos, x); }
	inline void del(int x)	  { getpos(x); t.erase(pos); }
	inline int queryrnk(int x){ getpos(x); return pos - t.begin() + 1; }
	inline int queryval(int x){ getpos(x); return t.at(x - 1); }
	inline int prev(int x)	  { getpos(x); return *(--pos); }
	inline int next(int x)	  { getpos(x); return *upper_bound(t.begin(), t.end(), x); }
};
BalancedTree t;

int main()
{
	read(n, m);
	t.insert(0); t.insert(n + 1);
	while (m--)
	{
		readchar(opt);
		switch (opt)
		{
		case 'D': read(x); dead[x] = 1; t.insert(x); d.pb(x); break;
		case 'R': dead[d.back()] = 0; t.del(d.back()); d.db(); break;
		case 'Q': read(x); if (dead[x]) { writeln(0); } else { writeln(t.next(x) - t.prev(x) - 1); } break;
		default: qwq
		}
	}
	return 0;
}