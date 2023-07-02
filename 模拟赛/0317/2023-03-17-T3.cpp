#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

i64 n, m, ans;
bool ext[2050];

int solve(int l, int r)
{
	// cout << l << ' ' << r << endl;
	if (l >= r) return r;
	int mid = (l + r) >> 1;
	int x = solve(l, mid);
	int y = solve(mid + 1, r);
	if ( (!ext[x] && ext[y]) || (ext[x] && !ext[y]) )
	{
		++ans;
		// cout << x << " vs " << y << endl;
	}
	if (ext[x]) return x;
	if (ext[y]) return y;
	else return y;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (reg int i = 1; i <= (1 << n); ++i)
		ext[i] = 1;
	for (reg int i = 1, x; i <= m; ++i)
		cin >> x, ext[x] = 0;
	int tmp = solve(1, (1 << n));
	cout << ans << endl;
	return 0;
}