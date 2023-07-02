// Problem:      人生的最高赞歌[DP]
// Contest:      bmhOJ
// URL:          https://bmh.coderlands.com/problem.php?cid=1873&pid=2
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-15 19:55:38

#include <bits/stdc++.h>
using namespace std;
int m, n, w[1010], c[1010], f[100010];
int main()
{
	cin >> m >> n;
	for(int i = 1; i <= n; i++)
		cin >> w[i] >> c[i];
	for(int i = 1; i <= n; i++)
		for(int j = m; j >= w[i]; j--)
			f[j] = max(f[j], f[j - w[i]] + c[i]);
	cout << f[m] << endl;
	return 0;
}