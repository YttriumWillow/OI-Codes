// Problem:      P1550 [USACO08OCT]Watering Hole G
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1550
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-19 19:03:50 

#include <iostream>

#include <cmath>
#include <algorithm>
#include <iomanip>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 5010;
const double inf = 0x7fffffff;

int n;
bool vis[N];
int dis[N][N], ans;
int faq[N]; 

struct Point
{
	int x, y, w;
	friend bool operator < (Point _x, Point _y)
	{ return _x.w < _y.w; }
} p[N];


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> p[i].w;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> dis[i][j];
	sort(p + 1, p + n + 1);
	faq[1] = p[1].w; vis[1] = 1;
	for (int i = 2; i <= n; ++i)
		faq[i] = min(p[i].w, dis[1][i]);
	for (int i = 2; i <= n; ++i)
	{
		int now = 0; int nowd = inf;
		for (int j = 2; j <= n; ++j)
			if (!vis[j] && faq[j] < nowd)
				now = j, nowd = faq[j];
		vis[now] = 1;
		for (int j = 2; j <= n; ++j)
			if (!vis[j])
				faq[j] = min(faq[j], dis[now][j]);
	}
	for (int i = 1; i <= n; ++i)
		ans += faq[i];
	cout << ans << endl;
	return 0;
}