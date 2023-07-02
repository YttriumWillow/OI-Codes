#include <iostream>

#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 50010;

struct Edge
{
	int u, v, w;
	Edge(int u = 0, int v = 0, int w = 0): u(u), v(v), w(w) { }
	friend bool operator < (Edge _x, Edge _y) { return _x.w < _y.w; }
};

int n, m, k;
int u, v, w, c;
int cnt[2], usd;
Edge e[2][N];
int fa[N];
i64 ans;

inline int find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k; // need k edges that in e[0].
	for (int i = 0; i <= n; ++i)
		fa[i] = i;
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> v >> w >> c;
		e[c][++cnt[c]] = Edge(u + 1, v + 1, w);
	}
	sort(e[0] + 1, e[0] + cnt[0] + 1);
	sort(e[1] + 1, e[1] + cnt[1] + 1);
	
	// for (int _ = 0; _ <= 1; ++_, cerr << endl)
		// for (int i = 1; i <= cnt[_]; ++i)
			// cerr << e[_][i].u << ' ' << e[_][i].v << ' ' << e[_][i].w << endl;
	
	for (int i = 1; i <= cnt[0] && usd < k; ++i)
	{
		int x = find(e[0][i].u);
		int y = find(e[0][i].v);
		if (x == y) continue;
		
		ans += e[0][i].w;
		++usd; fa[x] = y;
	}
	for (int i = 1; i <= cnt[1] && usd < n - 1; ++i)
	{
		int x = find(e[1][i].u);
		int y = find(e[1][i].v);
		if (x == y) continue;
		
		ans += e[1][i].w;
		++usd; fa[x] = y;
	}
	cout << ans << endl;
	return 0;
}