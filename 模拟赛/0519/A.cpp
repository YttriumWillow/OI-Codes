#include <iostream>

#include <cmath>
#include <algorithm>
#include <iomanip>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 5010;
const double inf = 1e15;

int n;
bool vis[N];
double d[N][N], ans;
double faq[N]; 

struct Point
{
	int x, y, w;
	friend bool operator < (Point _x, Point _y)
	{ return _x.w < _y.w; }
} p[N];

#define dis(i, j) ( hypot(p[i].x - p[j].x, p[i].y - p[j].y) )

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> p[i].w;
	for (int i = 1; i <= n; ++i)
		cin >> p[i].x >> p[i].y;
	sort(p + 1, p + n + 1);
	faq[1] = p[1].w; vis[1] = 1;
	for (int i = 2; i <= n; ++i)
		faq[i] = min(1.0 * p[i].w, dis(1, i));
	for (int i = 2; i <= n; ++i)
	{
		int now = 0; double nowd = inf;
		for (int j = 2; j <= n; ++j)
			if (!vis[j] && faq[j] < nowd)
				now = j, nowd = faq[j];
		vis[now] = 1;
		for (int j = 2; j <= n; ++j)
			if (!vis[j])
				faq[j] = min(faq[j], dis(now, j));
	}
	for (int i = 1; i <= n; ++i)
		ans += faq[i];
	cout << fixed << setprecision(2) << ans << endl;
	return 0;
}
