// Problem:      Binary Blocks
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/CF838A
// Memory Limit: 250 MB
// Time Limit:   2000 ms
// Created Time: 2023-07-04 20:50:09 

#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 5010;
const int inf = 0x3fffffff;

char ch;
int n, m;
int lmt;
int ans = inf;
int a[N][N];
int sum[N][N];
int prime[N];

inline void init(int n)
{ 
	for (int i = 2; i <= n; ++i)
	{
		if (!prime[i]) prime[++prime[0]] = i;
		for (int j = 1; j <= prime[0] && i * prime[j] <= n; ++j)
		{
			prime[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}

inline int zip(int v)
{
	int res = 0, t;
	for (int i = v; i - v < n; i += v)
		for (int j = v; j - v < m; j += v)
		{
			t = sum[i - v][j - v] + sum[i][j] - sum[i - v][j] - sum[i][j - v];
			res += min( t, v * v - t );
		}
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	
	int lmt = max(n, m);
	init(lmt);
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> ch, a[i][j] = ch - '0';
	
	for (int i = 1; i <= 2 * lmt; ++i)
		for (int j = 1; j <= 2 * lmt; ++j)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
	
	for (int i = 2; i <= lmt; ++i)
		ans = min(ans, zip(lmt));
	cout << ans << endl;
	return 0;
}