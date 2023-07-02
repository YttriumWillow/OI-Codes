// Problem:      T266174 「GLR-R4」立夏
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/T266174?contestId=83892
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-18 14:03:32

#include <iostream>

#include <vector>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");
#define pb push_back

using namespace std;

vector<int> a;
i64 x, T, tmp, ans;
bool flag;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> x;
        if (x % 3 == 2) { cout << 0 << endl; continue; } 
        tmp = x; ans = 1;
        a.clear(); flag = false;
        while (tmp > 0)
        {
            a.pb(tmp % 3);
            tmp /= 3;
        }
        for (reg int i = 1; i < a.size(); ++i)
        	if (a[i] == 1)
        		ans *= 2;
        cout << ans << endl;
    }
    return 0;
}