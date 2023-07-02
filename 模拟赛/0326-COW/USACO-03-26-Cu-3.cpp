// Problem:      Problem 3. Rotate and Shift
// Contest:      USACO - USACO 2022 US Open Contest, Bronze
// URL:          http://usaco.org/index.php?page=viewproblem&cpid=1313
// Memory Limit: 256 MB
// Time Limit:   4000 ms
// Created Time: 2023-03-26 19:33:27 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, k, T;
int a[200010];
int chg[200010];
int tmp[200010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k >> T;
	for (reg int i = 0; i < n; ++i)
		a[i] = i;
	for (reg int i = 1; i <= k; ++i)
		cin >> chg[i];
	chg[0] = chg[k];
	for (reg int t = 0; t < T; ++t)
	{
		for (reg int i = 1; i <= k; ++i)
			tmp[i] = a[ (chg[i - 1] + t) % n ];
		for (reg int i = 1; i <= k; ++i)
			a[ (chg[i] + t) % n ] = tmp[i];
	}
	for (reg int i = 0; i < n; ++i)
		cout << a[i] << ' ';
	return 0;
}