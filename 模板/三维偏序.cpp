#include <iostream>

#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n'

using namespace std;

int n, m;

struct Node
{
	int a, b, c, s, res;
	friend bool operator < (const Node& _x, const Node& _y)
	{
		if (_x.a != _y.a)	return _x.a < _y.a;
		if (_x.b != _y.b)	return _x.b < _y.b;
							return _x.c < _y.c;
	}
	friend bool operator == (const Node& _x, const Node& _y)
	{
		return _x.a == _y.a && _x.b == _y.b && _x.c == _y.c;
	}
} q[200010], w[200010];

int tree[200010], ans[100010];

int lowbit(int x) { return x & -x; }
void add(int x, int v)
{
	for (reg int i = x; i <= 200010; i += lowbit(i))
		tree[x] += v;
} 
int query(int x)
{
	int res = 0;
	for (reg int i = x; i; i -= lowbit(i))
		res += tree[i];
	return res;
}

void mergesort(int l, int r)
{
	if (l >= r) return;
	int mid = (l + r) >> 1;
	mergesort(l, mid); mergesort(mid + 1, r);
	int i = l, j = mid + 1, k = 0;
	while (i <= mid && j <= r)
	{
		if (q[i].b <= q[j].b)
			add(q[i].c, q[i].s), w[k++] = q[i++];
		else
			q[j].res += query(q[j].c), w[k++] = q[j++];
	}
	while (i <= mid)
		add(q[i].c, q[i].s), w[k++] = q[i++];
	while (j <= r)
		q[j].res += query(q[j].c), w[k++] = q[j++];
	for (i = l; i <= mid; ++i)
		add(q[i].c, -q[i].s);
	for (i = l, j = 0; j < k; ++i, ++j)
		q[i] = w[j];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (reg int i = 1, a, b, c; i <= n; ++i)
	{
		cin >> a >> b >> c;
		q[i] = (Node){a, b, c, 1, 0};
	}
	sort(q + 1, q + n + 1);
	n = unique(q + 1, q + n + 1) - q + 1;
	
	mergesort(1, n);
	for (reg int i = 1; i <= n; ++i)
	{
		ans[q[i].res + q[i].s - 1] += q[i].s;
	}
	for (reg int i = 1; i <= n; ++i)
		cout << ans[i] << endl;
	return 0;
}