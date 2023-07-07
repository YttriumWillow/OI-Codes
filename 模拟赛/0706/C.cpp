#include <iostream>

#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;
const int M = 2e6 + 10;

// struct Edge
// {
	// int v, nxt; Edge() { }
	// Edge(int v, int nxt): v(v), nxt(nxt) {}
// } e[M << 1];
// int h[N], tot;
// inline void addedge(int u, int v)
// { e[++tot] = Edge(v, h[u]), h[u] = tot; }

int n, m;
int u, v;
i64 ans;
int cnt[N];
int b[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> v;
		++cnt[u]; ++cnt[v];
	}
	for (int i = 1; i <= n; ++i)
	{
		cnt[i] = n - 1 - cnt[i];
		if (cnt[i] == 1) ++ans;
		++b[cnt[i]];
	}
	// for (int i = 1; i <= n - 1; ++i)
		// cerr << b[i] << " \n"[i == n - 1];
	int res = 0;
	for (int i = 1; i <= n - 1; ++i)
		res += !!(b[i]);
	cout << res + ans << endl;
	sort(b + 1, b + n, greater<int>());
	for (int i = 1; i <= ans; ++i)
		cout << 1 << ' ';
	for (int i = 1; i <= res; ++i)
		cout << b[i] << ' ';
	return 0;
}