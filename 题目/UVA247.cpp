// Problem:      电话圈 Calling Circles
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/UVA247
// Memory Limit: 0 MB
// Time Limit:   3000 ms
// Created Time: 2023-05-20 08:53:00

#include <iostream>

#include <map>
#include <set>
#include <stack>
#include <vector>
#include <cstring>

#define i64 long long
#define endl '\n'
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

int T, n, m;

namespace Solution
{
string s1, s2;
map<string, int> idx;
string name[31];

int cnt;
int dfncnt, scccnt;
int dfn[31], low[31];
int scc[31]; bool ins[31];
set<int> g[31];
vector<int> res[31];
stack<int> st;

inline void tarjan(int u)
{
	dfn[u] = low[u] = ++dfncnt;
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
			scc[u] = scccnt; ins[u] = 0;
			res[scccnt].pb(u);
			u = st.top(); st.pop();
		} while (dfn[u] != low[u]);
	}
}

int main(int T)
{
	for (int i = 1; i <= m; ++i)
	{
		cin >> s1 >> s2;
		if (!idx.count(s1))
		{
			idx[s1] = ++cnt;
			name[cnt] = s1;
		}
		if (!idx.count(s2))
		{
			idx[s2] = ++cnt;
			name[cnt] = s2;
		}
		g[idx[s1]].insert(idx[s2]);
	}
	
	for (int i = 1; i <= n; ++i)
	{
		cerr << name[i] << ": ";
		for (auto v : g[i])
			cerr << name[v] << ' ';
		cerr << endl;
	}
	
	cout << "Calling circles for data set " << T << ":\n";
	for (int i = 1; i <= n; ++i)
		if (!dfn[i]) tarjan(i);
	
	for (int i = 1; i <= n; ++i)
		cerr << scc[i] << ' ';
	cerr << endl;
	
	for (int i = 1; i <= scccnt; ++i)
	{
		for (int j = 0; j < (int)res[i].size() - 1; ++j)
			cout << name[res[i][j]] << ", ";
		cout << name[*(--res[i].end())] << endl;
	}
	
	
	cerr << endl;
	cnt = dfncnt = scccnt = 0; idx.clear();
	for (int i = 1; i <= n; ++i) g[i].clear();
	for (int i = 1; i <= n; ++i) res[i].clear();
	for (int i = 1; i <= n; ++i) ins[i] = 0;
	for (int i = 1; i <= n; ++i) dfn[i] = low[i] = 0;
	while (!st.empty()) st.pop();
	return 0;
}
} // namespace Solution

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (cin >> n >> m && (n || m))
        Solution::main(++T);
    return 0;
}
