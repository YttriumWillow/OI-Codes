// Problem:      P8819 [CSP-S 2022] 星战
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P8819
// Memory Limit: 512 MB
// Time Limit:   2000 ms
// Created Time: 2023-03-13 20:21:42 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m, u, v, q, t;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	while (m--)
		cin >> u >> v;
	cin >> q;
	while (q--)
	{
		if (t == 1 || t == 3)
			cin >> u >> v, puts("NO");
		else
			cin >> u, puts("NO");
	}
	return 0;
}