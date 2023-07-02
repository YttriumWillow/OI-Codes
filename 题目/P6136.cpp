// Problem:      P6136 【模板】普通平衡树（数据加强版）
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P6136
// Memory Limit: 89 MB
// Time Limit:   3000 ms
// Created Time: 2023-03-23 19:44:23 

#include <iostream>

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define i64 long long
#define qwq puts("fzy qwq ~");
#define Node pair<int, int>

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
    inline void writeln(_Tp a[], _Tpp faq) { for ( _Tpp i = 1; i <= faq; ++i) writespace(a[i]); putchar('\n'); }
    template<typename _Tp, typename _Tpp>
    inline void writeln(_Tp a[], _Tpp l, _Tpp r) { for (_Tpp i = l; i <= r; ++i) writespace(a[i]); putchar('\n'); }
};
using namespace IO;
using namespace std;
using namespace __gnu_pbds;

tree<
	Node, 
	null_type, 
	less<Node>, 
	rb_tree_tag, 
	tree_order_statistics_node_update
> Tree;

int T, n;
int opt, x, p;
int lst, ans;

int main()
{
	read(n, T);
	for (int i = 1; i <= n; ++i)
		read(p), Tree.insert({p, i});
	while (T--)
	{
		read(opt, x); x ^= lst;
		
		if      (opt == 1) Tree.insert( {x, ++n} );
		else if (opt == 2) Tree.erase( Tree.lower_bound( {x, 0} ) );
		else if (opt == 3) lst = Tree.order_of_key( {x, 0} ) + 1;
		else if (opt == 4) lst = Tree.find_by_order(x - 1) -> first;
		else if (opt == 5) lst = ( --Tree.lower_bound({x, 0}) ) -> first;
		else if (opt == 6) lst = Tree.upper_bound( {x, n} ) -> first;
		
		if (opt > 2) ans ^= lst;
	}
	writeln(ans);
	return 0;
}
