#include <iostream>

#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

struct Food
{
	int fat, cls;
	friend bool operator < (const Food &_x, const Food &_y)
	{
		if (_x.fat == _y.fat) return _x.cls < _y.cls;
		else return _x.fat > _y.fat;
	}
} a[1010];

int n, m, k, ans, cnt;
int clsn[110];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k;
	for (reg int i = 1; i <= k; ++i)
		cin >> clsn[i];
	for (reg int i = 1, x, y; i <= n; ++i)
	{
		cin >> x >> y;
		a[i] = { x, y };
	}
	sort(a + 1, a + n + 1);
	
	// for (reg int i = 1; i <= n; ++i)
		// cout << a[i].fat << ' ' << a[i].cls << endl;
	
	for (reg int i = 1; i <= n; ++i)
	{
		if (clsn[ a[i].cls ] > 0 && cnt < m)
		{
			// cout << "EAT: " << i << " fat: " << a[i].fat << " cls: " << a[i].cls << endl;
			ans += a[i].fat;
			--clsn[ a[i].cls ];
			++cnt;
		}
	}
	cout << ans << endl;
	return 0;
}