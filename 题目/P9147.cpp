// Problem:      P9147 签到题
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P9147
// Memory Limit: 256 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-12 19:07:44

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n';

using namespace std;

i64 n, ans;
i64 a[100010];
i64 f1[100010];
i64 f2[100010];

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
    cin >> n;
    for (reg int i = 1; i <= n; ++i)
        cin >> a[i];
    for (reg int i = 1; i <= n; ++i)
        f1[i] = (a[i] > a[i - 1]) ? f1[i - 1] + 1 : 1;
    for (reg int i = n; i >= 1; --i)
        f2[i] = (a[i] < a[i + 1]) ? f2[i + 1] + 1 : 1;
    for (reg int i = 1; i <= n; ++i)
    {
        if (a[i + 1] - a[i - 1] >= 2)
            ans = max(ans, f1[i - 1] + f2[i + 1] + 1);
        else
            ans = max(ans, max(f1[i - 1], f2[i + 1]) + 1);
    }
    cout << ans << endl;
    return 0;
}
