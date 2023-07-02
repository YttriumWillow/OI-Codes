// Problem:      P1486 [NOI2004] 郁闷的出纳员
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1486
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-23 07:28:02 

#include <iostream>

#include <vector>
#include <algorithm>

#define i64 long long
#define reg register
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

    // writeln
    template<typename _Tp>
    inline void writeln(_Tp x) { write(x); putchar('\n'); }
};
using namespace ExtIO;

struct BalancedTree
{
    vector<int> t; vector<int>::iterator pos = t.begin();
    inline void getpos(int x) { pos = lower_bound(t.begin(), t.end(), x); }
    inline void insert(int x) { getpos(x); t.insert(pos, x); }
    inline void del(int x)    { getpos(x); t.erase(pos); }
    inline int queryrnk(int x){ getpos(x); return pos - t.begin() + 1; }
    inline int queryval(int x){ getpos(x); return t.at(x - 1); }
    inline int prev(int x)    { getpos(x); return *(--pos); }
    inline int next(int x)    { getpos(x); return *upper_bound(t.begin(), t.end(), x); }
};

char opt;
int n, m, k, ans;
int d;
BalancedTree t;

int main()
{
	read(n, m);
	while (n--)
	{
		readchar(opt); read(k);
		if (opt == 'I')
		{
			for (auto &x : t.t)
				x += d;
			d = 0;
			t.insert(k);
			t.getpos(m);
			
			while (t.t[0] < m && !t.t.empty())
				t.t.erase(t.t.begin());
		}
		if (opt == 'A')
		{
			d += k;
			while (t.t[0] + d < m && !t.t.empty())
				t.t.erase(t.t.begin()), ++ans;
		}
		if (opt == 'S')
		{
			d -= k;
			while (t.t[0] + d < m && !t.t.empty())
				t.t.erase(t.t.begin()), ++ans;
		}
		if (opt == 'F')
		{
			if (k > t.t.size())
				puts("-1");
			else
				writeln(t.queryval(t.t.size() - k + 1) + d);
		}
		switch (opt)
		{
		case 114514:
			cout << faq << endl;
			break;
		case 1919810: 
			++faq;
			break;
		default:
			qwq
		}
	}
	writeln(ans);
	return 0;	
}