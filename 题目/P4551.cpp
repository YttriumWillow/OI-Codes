// Problem:      P4551 最长异或路径
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P4551
// Memory Limit: 64 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-01 14:51:21 

#include <iostream>

#include <vector>

#define i64 long long
#define reg register
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

struct Branch { int v, w; };
struct TrieNode { int son[2]; };
vector<Branch> g[100010];

int n, cnt, ans;
int pre[100010];
TrieNode _01Trie[2000010];

inline void dfs(int u, int fa)
{
	for (auto now : g[u])
		if (now.v != fa)
		{
			pre[now.v] = pre[u] ^ now.w;
			dfs(now.v, u);
		}	
}

inline void build(int u, int val)
{
	for (reg int i = (1 << 30); i; i >>= 1)
	{
		bool lr = val & i;
		if (!_01Trie[u].son[lr])
			_01Trie[u].son[lr] = ++cnt;
		u = _01Trie[u].son[lr];
	}
}

inline int query(int u, int val)
{
	int res = 0;
	for (reg int i = (1 << 30); i; i >>= 1)
	{
		bool lr = val & i;
		if (_01Trie[u].son[!lr])
			u = _01Trie[u].son[!lr], res += i;
		else 
			u = _01Trie[u].son[lr];
	}
	return res;
}

int main()
{
	cin >> n;
	for (reg int i = 1, u, v, w; i <= n - 1; ++i)
	{
		cin >> u >> v >> w;
		g[u].pb({ v, w });
		g[v].pb({ u, w });
	}
	dfs(1, 0);
	for (reg int i = 1; i <= n; ++i)
		build(0, pre[i]);
	for (reg int i = 1; i <= n; ++i)
		ans = max(ans, query(0, pre[i]));
	cout << ans << endl;
	return 0;
}