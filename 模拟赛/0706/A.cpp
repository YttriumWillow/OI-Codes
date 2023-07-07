#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e6 + 10;
const i64 inf = 0x7ffffffffffffff;

i64 n;
i64 a[N];
i64 sum, now = inf;

int main()
{
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], sum += a[i];
	cerr << sum << endl;
	if (sum & 1)
	{
		for (int i = 1; i <= n; ++i)
			if (a[i] & 1)
				now = min(now, a[i]);
		if (sum - now == 0)
			cout << "NIESTETY" << endl;
		else
			cout << sum - now << endl;
	}
	else cout << sum << endl;
	return 0;
}