// Problem:      P1982 [NOIP2013 普及组] 小朋友的数字
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1982
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-19 20:03:59 

#include <iostream>

#define i64 long long
#define i128 __int128
#define reg register
#define qwq puts("fzy qwq ~");

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
	inline void readchar(char& x) { for (x = getchar(); !std::isalpha(x); x = getchar()); }
	
	template<typename _Tp, typename ...Args>
	inline void read(_Tp& x, Args& ...args) { read(x), read(args...); }
	template<typename _Tp>
	inline void readln(_Tp a[], _Tp faq) { for (reg int i = 1; i <= faq; ++i) read(a[i]); }
	template<typename _Tp>
	inline void readln(_Tp a[], _Tp l, _Tp r) { for (reg int i = l; i <= r; ++i) read(a[i]); }
	
	template<typename _Tp>
	inline void writeln(_Tp x) { write(x); putchar('\n'); }
	template<typename _Tp>
	inline void writespace(_Tp x) { write(x); putchar(' '); }
	template<typename _Tp, typename ...Args>
	inline void writeln(_Tp& x, Args& ...args) { writespace(x), writespace(args...); putchar('\n'); }
	template<typename _Tp>
	inline void writeln(_Tp a[], _Tp faq) { for (reg int i = 1; i <= faq; ++i) writespace(a[i]); putchar('\n'); }
	template<typename _Tp>
	inline void writeln(_Tp a[], _Tp l, _Tp r) { for (reg int i = l; i <= r; ++i) writespace(a[i]); putchar('\n'); }
};
using namespace IO;

using namespace std;

i128 n, p, ans;
i128 vmax = 0, vmin = 0xfffffff;
i128 q[1000010];
i128 s[1000010];
i128 w[1000010];
i128 a[1000010];

int main()
{
	read(n, p);
	readln(a, n);
	ans = s[1] = q[1] = w[1] = a[1];
	for (reg int i = 2; i <= n; ++i)
	{
		w[i] = max(w[i - 1] + a[i], a[i]);
		q[i] = max(q[i - 1], w[i]);
		s[i] = (i == 2) ? s[1] + s[1] : max(s[i - 1], s[i - 1] + q[i - 1]);
		ans = max(ans, s[i]);
	}
	writeln(ans % p);
	return 0;
}