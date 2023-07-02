#pragma GCC optimize(3)
#pragma GCC target("avx,sse2,sse3,sse4,mmx,avx2,avx512f,popcnt,sse4.1,sse4.2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")

#include <iostream>

#include <cstring>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;
const int inf = 0x3fffffff;

int n, ans = inf;
int low = inf, high = -inf;
int a[N], b[N];
int th, tl;
int h[N], l[N];

int main()
{
	freopen("balance.in", "r", stdin);
	freopen("balance.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		low = min(low, a[i]);
		high = max(high, a[i]);
	} a[0] = a[n + 1] = -inf;
	for (int i = 1; i <= n; ++i)
	{
		if (a[i - 1] < a[i] && a[i] > a[i + 1])
			h[++th] = i;
		if (a[i - 1] > a[i] && a[i] < a[i + 1])
			l[++tl] = i;
	}
	for (int i = 1; i <= th; ++i)
	{
		int res = 0; int pst = a[h[i]];
		int to = (abs(pst - a[h[i] - 1]) < abs(pst - a[h[i] + 1])
					? a[h[i] - 1] : a[h[i] + 1]);
		memcpy(b, a, sizeof a);
		for (int i = 1; i <= n; ++i)
			if (b[i] == pst)
				b[i] = to;
		for (int i = 2; i <= n; ++i)
			res += abs(b[i] - b[i - 1]);
		ans = min(ans, res);
	}
	for (int i = 1; i <= tl; ++i)
	{
		int res = 0; int pst = a[l[i]];
		int to = (abs(pst - a[l[i] - 1]) < abs(pst - a[l[i] + 1])
					? a[l[i] - 1] : a[l[i] + 1]);
		memcpy(b, a, sizeof a);
		for (int i = 1; i <= n; ++i)
			if (b[i] == pst)
				b[i] = to;
		for (int i = 2; i <= n; ++i)
			res += abs(b[i] - b[i - 1]);
		ans = min(ans, res);
	}
	printf("%d\n", ans);
	return 0;
}