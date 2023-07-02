// Problem:      Guardian of Decency
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/UVA12083
// Memory Limit: 0 MB
// Time Limit:   3000 ms
// Created Time: 2023-05-13 08:13:29 

#include <iostream>

#include <vector>

#define i64 long long
#define reg register
#define pb push_back
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int n, T, ans;
int u, v;
int vis[510];
int match[510];
vector<int> g[510];

struct { int h; char s; string style, sport; } a[510];

inline bool dfs(int u)
{
	for (auto v : g[u])
		if (!vis[v])
		{
			vis[v] = 1;
			if (!match[v] || dfs(match[v]))
				return match[v] = u, 1;
		}
	return 0;
}

#define check(i, j) ((abs(a[i].h - a[j].h) > 40) || (a[i].s == a[j].s)\
				  || (a[i].style != a[j].style) || (a[i].sport == a[j].sport))


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while (T--)
	{
		cin >> n; ans = 0;
		
		fill(match + 1, match + n + 1, 0);
		for (reg int i = 1; i <= n; ++i)
			g[i].clear();
		
		for (reg int i = 1; i <= n; ++i)
			cin >> a[i].h >> a[i].s >> a[i].style >> a[i].sport;
		for (reg int i = 1; i <= n; ++i)
			for (reg int j = 1; j < i; ++j)
				if (check(i, j) || i == j) continue;
				else g[j].pb(i);
		for (reg int i = 1; i <= n; ++i)
		{
			fill(vis + 1, vis + n + 1, 0);
			ans += dfs(i);
		}			
		cout << ans << endl;
	}
	return 0;
}