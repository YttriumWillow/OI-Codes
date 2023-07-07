#include <iostream>

#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 3e5 + 10;

int k, n, p;
i64 ans;
i64 a[N], pos;

struct Melon
{
	int m, w;
	friend bool operator < (const Melon& a, const Melon& b)
	{ return (a.w != b.w ? a.w > b.w : a.m > b.m); }
	friend bool operator > (const Melon& a, const Melon& b)
	{ return (a.w != b.w ? a.w < b.w : a.m < b.m); }
} f[N];

int main()
{
	freopen("watermelon.in", "r", stdin);
	freopen("watermelon.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> k >> n >> p;
	for (int i = 1; i <= k; ++i)
		cin >> f[i].m >> f[i].w;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	sort(f + 1, f + k + 1);
	sort(a + 1, a + n + 1, greater<int>());
	
	// for (int i = 1; i <= n; ++i)
		// cerr << a[i] << " \n"[i == n];
	// for (int i = 1; i <= k; ++i)
		// cerr << f[i].m << ' ' << f[i].w << endl;
	
	for (int i = 1; i <= n; ++i)
		if (f[++pos].m <= a[i])
		{
			ans += f[pos].w;
			f[pos].m = f[pos].w = 0;
		}
	
	// cerr << "faq " << ans << endl;
	sort(f + 1, f + k + 1);
	// for (int i = 1; i <= k; ++i)
		// cerr << f[i].m << ' ' << f[i].w << endl;
	
	for (int i = 1; i <= p; ++i)
		ans += f[i].w;
	
	cout << ans << endl;
	return 0;
}