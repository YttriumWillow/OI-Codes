#include <iostream>

#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int x, y, n;
int px, py;
int gx, gy;
int eu, ed, el, er;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> x >> y >> n; ed = x; er = y;
	for (reg int i = 1; i <= n; ++i)
	{
		cin >> px >> py;
		
		int u = px;
		int d = x - px;
		int l = py;
		int r = y - py;
		int v = min( { u, d, l, r } );
		
		if (v == u)
			eu = px;
		else if (v == d)
			ed = px;
		else if (v == l)
			el = py;
		else if (v == r)
			er = py;
	}
	cerr << eu << ' ' << ed << ' ' << el << ' ' << er;
	cout << ((er - el) + (ed - eu)) * 2 << endl;
	return 0;
}