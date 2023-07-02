// Problem:      P1765 手机
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1765
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-10 15:19:43

#include <bits/stdc++.h>
using namespace std;
char s[20001];
long long ans = 0, x;
int main()
{
    cin.getline(s, 1000001);
    int n = strlen(s);
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == ' ' || s[i] == '#' || s[i] == '&')
        {
            ans++;
            continue;
        }
        x = s[i];
        x -= 96;
        if (x == 26)
        {
            ans += 4;
            continue;
        }
        if (x <= 18)
        {
            x %= 3;
            if (x == 0)
                ans += 3;
            else
                ans += x;
            continue;
        }
        else
        {
            if (x == 19)
            {
                ans += 4;
                continue;
            }
            x--;
            x %= 3;
            if (x == 0)
                ans += 3;
            else
                ans += x;
        }
    }
    cout << ans << endl;
    return 0;
}