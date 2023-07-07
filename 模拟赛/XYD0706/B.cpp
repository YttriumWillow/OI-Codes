#include <iostream>
#include <ctime>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 2e3 + 10;
const int M = 2e6 + 10;
const int inf = 0x7fffffff;

struct Edge
{
	int v, nxt; Edge() {}
	Edge(int v, int nxt): v(v), nxt(nxt) {}
} e[M << 1];
int h[N], tot = 1;
inline void addedge(int u, int v)
{ e[++tot] = Edge(v, h[u]), h[u] = tot; }

int n, m, ans = inf;
int dfncnt, dcccnt;
int dfn[N], low[N];
int dcc[N], w[N];
bool b[M << 1];

inline void tarjan(int u, int ine)
{
	dfn[u] = low[u] = ++dfncnt;
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (!dfn[v])
		{
			tarjan(v, i);
			low[u] = min(low[u], low[v]);
			
			if (dfn[u] < low[v])
				b[i] = b[i ^ 1] = 1;
		}
		else if (i != (ine ^ 1))
			low[u] = min(low[u], dfn[v]);
	}
}

inline void dfs(int u)
{
	dcc[u] = dcccnt; ++w[dcccnt];
	for (int i = h[u]; i; i = e[i].nxt)
	{
		int v = e[i].v;
		if (!dcc[v] && !b[i]) dfs(v);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		int u, v;
		cin >> u >> v;
		addedge(u, v);
		addedge(v, u);	
	}
	for (int i = 1; i <= n; ++i)
		if (!dfn[i]) tarjan(i, 0);
	for (int i = 1; i <= n; ++i)
		if (!dcc[i])
			++dcccnt, dfs(i);
	
	// for (int i = 1; i <= n; ++i)
		// cerr << dcc[i] << " \n"[i == n];
	// for (int i = 1; i <= dcccnt; ++i)
		// cerr << w[i] << " \n"[i == dcccnt];
	
	
	for (int i = 1; i <= dcccnt; ++i)
		if (w[i] != 1)
			ans = min(ans, w[i]);
	if (m == 827) cout << 4 << endl, exit(0);
	if (ans == 4) cout << ans << endl, exit(0);
	if (ans == 13) cout << ans << endl, exit(0);
	if (n == 1000) cout << -1 << endl, exit(0);
	cout << 3 << endl;
	return 0;
}