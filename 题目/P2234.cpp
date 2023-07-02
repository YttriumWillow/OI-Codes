// Problem:      P2234 [HNOI2002]营业额统计
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2234
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-24 19:49:39 

#include <iostream>

#include <vector>
#include <algorithm>
#include <cmath>

#define i64 long long
#define reg register
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

const int inf = 0x7fffffff;

int n, ans, x;
vector<int> a;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n; a.pb(-inf);
	for (int i = 1; i <= n; ++i)
	{
		cin >> x;
		if (i == 1) { ans += x; a.pb(x); continue; }
		
		auto pre = --lower_bound(a.begin(), a.end(), x);
		auto suf =   lower_bound(a.begin(), a.end(), x);
		
		if ( (*pre) == -inf ) ans += abs( (*suf) - x );
		else ans += min( abs( (*pre) - x ), abs( (*suf) - x ) );
		
		a.insert( upper_bound(a.begin(), a.end(), x), x ); 
	}
	cout << ans << endl;
	return 0;
}