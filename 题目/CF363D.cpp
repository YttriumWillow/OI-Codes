#include <iostream>

#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;

int n, m, a;
int l, r, ans, res;
int b[N], p[N];

inline bool check(int x)
{
	int j = x, rem = a;
	for (int i = 1; i <= x; ++i)
	{
		if (b[i] < p[j])
			rem += (b[i] - p[j]);
		--j;
		if (rem < 0) return 0;
	}
	return rem >= 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> a;
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
	for (int i = 1; i <= m; ++i)
		cin >> p[i];
	
	sort(b + 1, b + n + 1, greater<int>());
	sort(p + 1, p + m + 1);
	
	l = 0, r = min(n, m);
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid))
			l = mid + 1, ans = mid;
		else
			r = mid - 1;
	}
	for (int i = 1; i <= ans; ++i)
		res += p[i];
	cout << ans << ' ' << max(0, res - a) << endl;
	return 0;
}