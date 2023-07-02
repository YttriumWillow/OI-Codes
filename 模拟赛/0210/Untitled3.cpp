#include <iostream>

#include <algorithm>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m;
longint ans;
longint b[500010];
longint f[500010];

struct Node
{
	longint val;
	int id;
	Node(){}
	Node(longint _v, int _i): val(_v), id(_i) {}
	friend bool operator < (Node _x, Node _y) { return _x.val > _y.val; }
} a[500010];

longint lowbit(longint x) { return x & -x; }

void add(int x, longint k)
{
	for (reg int i = x; i <= m; i += lowbit(i))
		f[i] += k;
}
longint query(int x)
{
	longint ret = 0;
	for (reg int i = x; i > 0; i -= lowbit(i))
		ret += f[i];
	return ret;
}

int main()
{
	cin >> n;
	for (reg int i = 1, val; i <= n; ++i)
	{
		cin >> val;
		a[i] = Node(val, i); 
	}
	sort(a + 1, a + n + 1);
	for (reg int i = 1; i <= n; ++i)
		if (a[i].val == a[i - 1].val)
			b[a[i].id] = m;
		else
			b[a[i].id] = (++m);
	for (reg int i = 1; i <= n; ++i)
	{
		add(b[i], 1);
		ans += query(b[i] - 1);
	}
	cout << ans << endl;
	return 0;
}
