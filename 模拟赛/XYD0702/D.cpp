#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 110;
const int inf = 0x3fffffff;

i64 n, m;
i64 a[N][N];
i64 dp[1 << 12];
i64 stt;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	
	for (int i = 0; i < (1 << n); ++i)
		dp[i] = inf;
	dp[0] = 0;
	
	for (int i = 1; i <= m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];
	for (int faq = 0; faq < (1 << n); ++faq)
		for (int i = 1; i <= m; ++i)
		{
			int stt = faq;
			for (int j = 0; j < n; ++j)
			{
				if (a[i][j] == 1)
					stt |= (1 << j);
				if (a[i][j] == -1)
					if (stt >> j & 1)
						stt ^= (1 << j);
			}
			dp[stt] = min(dp[stt], dp[faq] + 1);
		}
	cout << dp[(1 << n) - 1] << endl;
}