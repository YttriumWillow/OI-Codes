#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int inf = 0x3fffffff;

int n, m, maxn;
struct Node { int l, r, max, pos; };
Node t[4000010];
int a[200010];
int b[1000010];
#define ls (p << 1)
#define rs (p << 1 | 1)
inline void pushup(int p)
{
	t[p].max = max(t[ls].max, t[rs].max);
	if (b[t[ls].pos] >= b[t[rs].pos])
		t[p].pos = t[ls].pos;
	else
		t[p].pos = t[rs].pos;
}
inline void build(int p, int l, int r)
{
	t[p].l = l; t[p].r = r;
	if (l == r) { t[p].max = b[l]; t[p].pos = l; return; }
	int mid = (l + r) >> 1;
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(p);
}
inline void modify(int p, int x, int y)
{
	if (t[p].l == t[p].r) { t[p].max += y; return; }
	int mid = (t[p].l + t[p].r) >> 1;
	if (x <= mid) modify(ls, x, y);
	if (mid <  x) modify(rs, x, y);
	pushup(p);
}
inline void replace(int x, int y)
{
	--b[a[x]]; ++b[y];
	modify(1, a[x], -1); modify(1, y, 1);
	a[x] = y; cout << t[1].pos << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (reg int i = 1; i <= n; ++i)
		cin >> a[i], ++b[a[i]], maxn = max(maxn, a[i]);
	build(1, 1, (maxn > 100010 ? maxn + 10 : 100010));
	for (reg int i = 1, x, y; i <= m; ++i)
	{
		cin >> x >> y;
		replace(x, y);
		
		// cerr << "[log]opt " << i << ": ";
		// for (reg int j = 1; j <= 10; ++j)
			// cerr << b[j] << ' ';
		// cerr << endl;
	}
	return 0;
}