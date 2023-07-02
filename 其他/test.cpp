#include <iostream>

#include <cstring> 

#define reg register
#define longint long long
#define qwq puts("fzy qwq ~");
#define left <<1
#define right <<1|1

using namespace std;

int n, m;
int s[300010];
longint add[1200010], sum[1200010];

inline void pushup(int root)
{
	sum[root] = sum[root left] + sum[root right];
}
// 你干嘛
inline void build(int l, int r, int root)
{
	if (l == r)
	{
		sum[root] = s[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, root left);
	build(mid + 1, r, root right);
	pushup(root);
}

inline void pushdown(int root, int len)
{
	if (add[root])
	{
		add[root left] ^= 1;
		add[root right] ^= 1;
		sum[root left] = (len - (len >> 1)) - sum[root left];
		sum[root right] = (len >> 1) - sum[root right];
		add[root] = 0;
	}
}

inline longint query(int L, int R, int l, int r, int root)
{
	if (l >= L && r <= R)
		return sum[root];
	pushdown(root, r - l + 1);
	int mid = (l + r) >> 1;
	longint ans = 0;
	if (L <= mid)
		ans += query(L, R, l, mid, root left);
	if (mid + 1 <= R)
		ans += query(L, R, mid + 1, r, root right);
	return ans; 
}

inline void update(int L, int R, int l, int r, int root)
{
    pushdown(root, r - l + 1);
	if (l >= L && r <= R)
	{
		add[root] ^= 1;
		sum[root] = r - l + 1 - sum[root];
		return;
	}
	int mid = (l + r) >> 1;
	if (L <= mid)
		update(L, R, l, mid, root left);
	if (mid + 1 <= R)
		update(L, R, mid + 1, r, root right);
	pushup(root);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (reg int i = 1; i <= n; ++i)
		scanf("%1d", &s[i]);
		
	build(1, n, 1);
	for (reg int i = 1, p, l, r; i <= m; ++i)
	{
		scanf("%d%d%d", &p, &l, &r);
		if (p == 0)
			update(l, r, 1, n, 1);
		else
			printf("%lld\n", query(l, r, 1, n, 1));
	}
	return 0;
}