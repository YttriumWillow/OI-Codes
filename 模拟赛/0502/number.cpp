#include <iostream>

#include <queue>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

struct Node
{
	int val, cnt;
	Node(int x, int y): val(x), cnt(y) {}
	friend bool operator < (const Node& _x, const Node& _y)
	{ return (_x.cnt != _y.cnt) ? (_x.cnt < _y.cnt)	: (_x.val > _y.val); }
};

priority_queue<Node> q;

int n, m, x, y;
int a[100010];
int b[10000010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (reg int i = 1; i <= n; ++i)
		cin >> a[i], ++b[a[i]];
	for (reg int i = 1; i <= n; ++i)
		q.push( Node(a[i], b[a[i]]) );
	for (reg int i = 1; i <= m; ++i)
	{
		cin >> x >> y;
		--b[a[x]]; q.push( Node(a[x], b[a[x]]) );
		++b[y]; q.push( Node(y, b[y]) ); a[x] = y;
		while (!q.empty() && q.top().cnt != b[q.top().val]) 
			q.pop();
		cout << q.top().val << endl;
	}
	return 0;
}