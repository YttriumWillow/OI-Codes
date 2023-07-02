// Problem:      P9236 [蓝桥杯 2023 省 A] 异或和之和
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P9236
// Memory Limit: 256 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-12 20:45:49 

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

i64 n, ans;
i64 a[100010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (reg int i = 1; i <= n; ++i)
		cin >> a[i], a[i] ^= a[i - 1];
    for (reg int d = 0; d < 31; ++d)
    {
        i64 c[2] = { 0, 0 };
        for (reg int j = 0; j <= n; ++j)
        	++c[a[j] >> d & 1];
        ans += (1 << d) * c[0] * c[1];
    }
    cout << ans << endl;
	return 0;
}