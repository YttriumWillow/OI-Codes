// Problem:      T326569 「GMOI R2-T2」猫耳小
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/T326569?contestId=104457
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-05 14:12:04 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, k;
int a[500010];
int b[500010];
int ans, strt, top;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	for (reg int i = 1; i <= n; ++i)
		cin >> a[i], ++b[a[i]], top = max(top, a[i]);
	for (reg int i = 1; i <= top; ++i)
		if (i <= k && b[i] != 0)
			strt = i;
	for (reg int i = 1; i <= n; ++i)
		if (a[i] < strt)
			++ans;
	cout << ans << endl;
	return 0;
}