#pragma GCC optimize(3)

#include <iostream>

#include <queue>
#include <cstring>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e3 + 10;
const int M = 1e4 + 10;

struct Edge
{
	int v, nxt; Edge() {}
	Edge(int v, int n): v(v), nxt(n) {}
} e[M << 1];
int h[N], tot = 1;
inline void addedge(int u, int v)
{ e[++tot] = Edge(v, h[u]); h[u] = tot; }

int k, n, m, res;
int u, v, x;
int a[N], cnt[N];
bool vis[N];

inline void bfs(int s)
{
	queue<int> q; q.push(s);
	vis[s] = 1;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		cnt[u] += a[s];
		for (int i = h[u]; i; i = e[i].nxt)
		{
			int v = e[i].v;
			if (!vis[v])
			{
				vis[v] = 1;
				q.push(v);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> k >> n >> m;
	for (int i = 1; i <= k; ++i)
		cin >> x, ++a[x];
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> v;
		addedge(u, v);
	}
	for (int i = 1; i <= n; ++i)
	{
		memset(vis, 0, sizeof vis);
		bfs(i);
	}
	for (int i = 1; i <= n; ++i)
		if (cnt[i] >= k)
			++res;
	cout << res << endl;
	return 0;
}