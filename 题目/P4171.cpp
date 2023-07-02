// Problem:      P4171 [JSOI2010] 满汉全席
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P4171
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-15 18:52:19

#include <iostream>

#include <stack>
#include <vector>

#define i64 long long
#define reg register
#define endl '\n'
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 110 * 2;

int n, m, T;
int dfncnt, scccnt;
int scc[N], ins[N];
int dfn[N], low[N];
stack<int> st;
vector<int> g[N];

inline void tarjan(int u)
{
    low[u] = dfn[u] = ++dfncnt;
    ins[u] = 1; st.push(u);
    for (auto v : g[u])
    {
        if (!dfn[v])
            tarjan(v), 
            low[u] = min(low[u], low[v]);
        else if (ins[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        ++scccnt;
        do
        {
            scc[u] = scccnt;
            u = st.top(); st.pop();
            ins[u] = 0;
        } while (dfn[u] != low[u]);
    }
}

inline void build(string s1, string s2)
{
    reg int u = 0, v = 0;
    for (reg int i = 1; i < s1.size(); ++i)
        u = u * 10 + (s1[i] ^ '0');
    for (reg int i = 1; i < s2.size(); ++i)
        v = v * 10 + (s2[i] ^ '0');
    if (s1[0] == 'm')
    {
        if (s2[0] == 'h')
            g[u + n].pb(v + n), g[v].pb(u);
        else if (s2[0] == 'm')
            g[u + n].pb(v), g[v + n].pb(u);
    }
    else if (s1[0] == 'h')
    {
        if (s2[0] == 'h')
        	g[u].pb(v + n), g[v].pb(u + n);
        else if (s2[0] == 'm')
        	g[u].pb(v), g[v + n].pb(u + n);
    }
}

inline bool solve()
{
    cin >> n >> m;

    scccnt = dfncnt = 0;
    while (!st.empty()) ins[st.top()] = 0, st.pop();
    for (reg int i = 1; i <= 2 * n; ++i) g[i].clear();
    fill(low + 1, low + 2 * n + 1, 0);
    fill(dfn + 1, dfn + 2 * n + 1, 0);
    
    string u, v;

    for (reg int i = 1; i <= m; ++i)
    {
        cin >> u >> v;
        build(u, v);
    }
    for (reg int i = 1; i <= n * 2; ++i)
    	if (!dfn[i]) tarjan(i);
    for (reg int i = 1; i <= n; ++i)
    	if (scc[i] == scc[i + n])
    		return 0;
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while (T--)
        cout << (solve() ? "GOOD" : "BAD") << endl;
    return 0;
}