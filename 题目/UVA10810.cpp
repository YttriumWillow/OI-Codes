// Problem:      Ultra-QuickSort
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/UVA10810
// Memory Limit: 0 MB
// Time Limit:   3000 ms
// Created Time: 2023-03-28 19:23:24 

#include <iostream>

#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");
#define lowbit(x) (x & -x)

using namespace std;

int n, m;
i64 ans;
i64 b[500010];
i64 f[500010];

struct Node
{
	i64 val = 0; int id = 0;
	Node() {}
	Node(i64 _v, int _i): val(_v), id(_i) {}
	friend bool operator < (Node _x, Node _y) { return _x.val > _y.val; }
} a[500010];

inline void add(int x, i64 k)
{
	for (reg int i = x; i <= m; i += lowbit(i))
		f[i] += k;
}
inline i64 query(int x)
{
	i64 ret = 0;
	for (reg int i = x; i > 0; i -= lowbit(i))
		ret += f[i];
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	while (cin >> n)
	{
		if (n == 0) break;
		m = 0; ans = 0;
		
		for (reg int i = 1, val; i <= n; ++i)
			cin >> val, a[i] = Node(val, i); 
			
		sort(a + 1, a + n + 1);
		
		for (reg int i = 1; i <= n; ++i)
			if (a[i].val == a[i - 1].val)
				b[a[i].id] = m;
			else b[a[i].id] = ++m;
				
		for (reg int i = 1; i <= n; ++i)
			add(b[i], 1), ans += query(b[i] - 1);
			
		cout << ans << endl;
		
		for (reg int i = 1; i <= m; ++i) f[i] = 0;
	}
	return 0;
}