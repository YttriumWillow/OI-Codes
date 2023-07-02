// Problem:      T333131 分块
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/T333131
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-02 09:03:34 

#include <iostream>

#include <cmath>

#define i64 long long
#define reg register
#define endl '\n'
#define bel(p) ((p - 1) / blk + 1)
#define qwq puts("fzy qwq ~");

using namespace std;

int T;
i64 n, blk;
i64 l, r;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> T;
	blk = (i64)(sqrt(n));
	for (reg int i = 1; i <= T; ++i)
	{
		cin >> l >> r;
		cout << bel(r) - bel(l) + 1 << endl;
	}
	return 0;
}