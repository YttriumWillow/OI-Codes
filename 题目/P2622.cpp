// Problem:      P2622 关灯问题II
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2622
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-07-02 07:00:45 

#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 15;
const int M = 110;

int n, m;
int a[M][N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> a[i][j];
	
	
	return 0;
}