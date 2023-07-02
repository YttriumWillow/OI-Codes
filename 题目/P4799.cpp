// Problem:      P4799 [CEOI2015 Day2] 世界冰球锦标赛
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P4799
// Memory Limit: 500 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-30 18:45:19 

#include <iostream>

#include <algorithm>

#define i64 long long 
#define reg register
#define qwq puts("fzy qwq ~"`);

using namespace std;

i64 n, m, cntA, cntB;
i64 price[3000010];
i64  ansA[3000010];
i64  ansB[3000010];

inline void dfs(const int& l, const int& r, i64 sum, i64& cnt, i64 ans[])
{
	if (sum > m) return;
	if (l > r) { ans[++cnt] = sum; return; }
	dfs(l + 1, r, sum, cnt, ans);
	dfs(l + 1, r, sum + price[l], cnt, ans);
}

inline i64 answer()
{
	i64 ans = 0;
	sort(ansA + 1, ansA + cntA + 1);
	for (reg int i = 1; i <= cntB; ++i)
		ans += upper_bound(ansA + 1, ansA + cntA + 1, m - ansB[i]) - ansA - 1;
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (reg int i = 1; i <= n; ++i)
		cin >> price[i];
	i64 mid = n / 2;
	dfs(    1, mid, 0, cntA, ansA);
	dfs(mid + 1, n, 0, cntB, ansB);
	cout << answer() << endl;
	return 0;
}