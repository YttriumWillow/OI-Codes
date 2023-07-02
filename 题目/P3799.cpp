// Problem:	P3799 妖梦拼木棒
// Contest:	Luogu
// URL:	https://www.luogu.com.cn/problem/P3799
// Memory Limit:	125 MB
// Time Limit:	1000 ms
// Created Time:	2023-02-18 13:53:41

#include <iostream>

// #define int long long
#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;
const int mod = 1e9 + 7;

int n, maxlen = -1, ans;
int a[100005], visited[100005];

int check(int k)
{
    return ((k * k - k) / 2) % mod;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        maxlen = max(maxlen, a[i]);
        ++visited[a[i]];
    }
    for (int i = 1; i <= maxlen; ++i)
    {
        for (int j = i; j <= maxlen; ++j)
        {
            if (i == j)
                ans = (ans + (check(visited[i]) * check(visited[i + j]))) % mod;
            else
                ans = (ans + ((visited[i] * visited[j]) % mod * check(visited[i + j])) % mod) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}
