#include <iostream>

#include <numeric>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define l first
#define r second
#define Pii pair<int, int>
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e3 + 10;

int n, L, R;
Pii seg[N];
bool flg[N];
int ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> L >> R;
		seg[i] = { L, R };
	}
	// sort(seg + 1, seg + n + 1);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i != j && seg[i].l <= seg[j].l && seg[j].r <= seg[i].r)
				flg[j] = 1;
	for (int i = 1; i <= n; ++i)
		if (flg[i] == 0)
			++ans;
	cout << ans << endl;
	return 0;
}