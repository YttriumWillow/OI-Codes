// Problem:      P1429 平面最近点对（加强版）
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1429
// Memory Limit: 256 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-28 20:15:01 

#include <iostream>

#include <cmath>
#include <ctime>
#include <random>
#include <iomanip>
#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");
// for special purpose
#define randrad() ((rand() % 360) / 180.0 * Pi)
#define getdis(p, q) (hypot(a[p].x - a[q].x, a[p].y - a[q].y))

using namespace std;

const double Pi = acos(-1.0);

struct Node
{
	double x, y;
	inline friend bool operator < (Node _x, Node _y) { return _x.x < _y.x; }
} a[200010];

int n;
double tx, ty;
double ans = 1145141919810000;

inline void rotate(double rad)
{
	for (reg int i = 1; i <= n; ++i)
	{
		double xx = a[i].x, yy = a[i].y;
		double nx = xx * cos(rad) - yy * sin(rad);
		double ny = xx * sin(rad) + yy * cos(rad);
		a[i].x = nx, a[i].y = ny;
	}
}

inline void faq()
{
	for (reg int i = 1; i <= n; ++i)
		for (reg int j = i + 1; j <= i + 5 && j <= n; ++j)
			ans = min(ans, getdis(i, j));
}

inline void cheat()
{
	rotate(        0); sort(a + 1, a + n + 1); faq();
	rotate(randrad()); sort(a + 1, a + n + 1); faq();
	rotate(randrad()); sort(a + 1, a + n + 1); faq();
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	srand(time(0));
	cin >> n;
	for (reg int i = 1; i <= n; ++i)
		cin >> tx >> ty, a[i].x = tx, a[i].y = ty;
	cheat();
	cout << fixed << setprecision(4) << ans << endl;
	return 0;
}