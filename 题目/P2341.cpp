// Problem:      P2341 [USACO03FALL / HAOI2006] 受欢迎的牛 G
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2341
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-22 18:54:05 

#include <iostream>

#include <vector>
#include <stack>
#include <queue>
#include <set>

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

struct Branch { int u, v; };

int n, m;
int dfncnt, scccnt;
int dfn[10010], low[10010];
int scc[10010], siz[10010];
bool instack[10010];

vector<int> g[10010];
vector<Branch> edge;
stack <int> st;
set<int> newg[10010];
vector<int> ans;


inline void tarjan(int u)
{
	low[u] = dfn[u] = ++dfncnt; 
	st.push(u); instack[u] = true;
	for (auto v : g[u])
	{
		if (!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (instack[v])
			low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u])
	{
		++scccnt;
		while (st.top() != u)
		{
			int now = st.top(); st.pop();
			scc[now] = scccnt;
			++siz[scccnt];
			instack[now] = false;
		}
		int now = st.top(); st.pop();
		scc[now] = scccnt;
		++siz[scccnt];
		instack[now] = false;
	}
}

inline void buildnew()
{
	for (auto p : edge)
	{
		int x = scc[p.u];
		int y = scc[p.v];
		if (x != y)
			newg[x].insert(y);
	}
	for (reg int i = 1; i <= scccnt; ++i)
		if (newg[i].size() == 0)
			ans.pb(i);
}

int main()
{
	read(n, m);
	for (reg int i = 1, u, v; i <= m; ++i)
		read(u, v), g[u].pb(v), edge.pb( (Branch){ u, v } );
	for (reg int i = 1; i <= n; ++i)
		if (!dfn[i])
			tarjan(i);
	buildnew();
	writeln(ans.size() > 1 ? 0 : siz[ans[0]]);
	return 0;
}