#include <iostream>

#include <algorithm>

#define i64 long long
#define reg register
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int inf = 0x7fffffff;

int n, m, res = inf;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	if (n == 1) { cout << 0 << endl; return 0; }
	for (reg int i = 1, u, v, w; i <= m; ++i)
	{
		cin >> u >> v >> w;
		res = min(res, w);
	}
	cout << res / __gcd(res, 2) << '/' << 2 / __gcd(res, 2) << endl;
	return 0;
}