// Problem:      P9202 「GMOI R2-T2」猫耳小（加强版）
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P9202
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-07 14:40:42

#include <bits/stdc++.h>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, k, ans;
int a[1000010];
set<int> s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    for (reg int i = 1; i <= n; ++i)
        cin >> a[i];
    if (k == 0)
    {
        for (reg int i = 1; i <= n; ++i)
            if (a[i] != 0)
                ++ans, a[i] = 0;
        cout << ans << endl;
        for (reg int i = 1; i <= n; ++i)
        	cout << a[i] << ' ';
        return 0;
    }
    if (k > n + 1)
    {
        cout << 0 << endl;
        for (reg int i = 1; i <= n; ++i)
        	cout << a[i] << ' ';
        return 0;
    }
    for (reg int i = 1; i <= n; ++i)
    {
        if (a[i] > k)
            continue;
        if (a[i] == k)
        {
            s.clear();
            continue;
        }
        s.insert(a[i]);
        if (s.size() == k)
        {
            ++ans, a[i] = k;
            s.clear();
        }
    }
    cout << ans << "\n";
    for (reg int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    return 0;
}