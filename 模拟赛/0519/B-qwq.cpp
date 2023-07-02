#include <iostream>

#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 50010;
const int M	= 100010;

struct Edge
{
	int u, v, w, c;
	Edge(int u = 0, int v = 0, int w = 0, int c = 0): u(u), v(v), w(w), c(c) { }
	friend bool operator < (Edge _x, Edge _y) { return _x.w != _y.w ? _x.w < _y.w : _x.c < _y.c; }
};

int n, m, k, ans;
int u, v, w, c, res;
Edge e[M]; int fa[N];

inline int find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

inline bool checker(int mid)
{
	static int usd, fw;
	res = usd = fw = 0;
	for (int i = 1; i <= m; ++i)
		if (e[i].c == 0) e[i].w += mid;
	for (int i = 1; i <= n; ++i) fa[i] = i;
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= m; ++i)
	{
		int x = find(e[i].u);
		int y = find(e[i].v);
		if (x == y) continue;
		
		res += e[i].w; fa[x] = y;
		fw += (e[i].c == 0); // i am a fw
		if (++usd == n) break;
	}
	for (int i = 1; i <= m; ++i)
		if (e[i].c == 0) e[i].w -= mid;
	return fw >= k;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k; // need k edges that in e[0].
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> v >> w >> c;
		e[i] = Edge(u + 1, v + 1, w, c);
	}
	
	int l = -114, r = 114;
	while (l <= r)
	{	
		int mid = (l + r) >> 1;
		if (checker(mid)) l = mid + 1,
						  ans = res - mid * k;
		else 			  r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}