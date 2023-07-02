// Problem:      P9118 [春季测试 2023] 幂次【民间数据】
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P9118?contestId=102679
// Memory Limit: 1 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-06 20:37:18

#include <iostream>

#include <map>
#include <unordered_map>
// #include <bitset>

#define i64 long long
#define i128 __int128
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

i128 n, k, now, K;
i64 ans;

template <typename Tp>
inline void read(Tp &x)
{
    x = 0; char ch = getchar(); Tp sgn = 1;
    while (!isdigit(ch)) { if (ch == '-') sgn = -1; ch = getchar(); }
    while (isdigit(ch)) { x = (x << 3) + (x << 1) + (ch & 15); ch = getchar(); }
    x *= sgn;
}

inline i128 fpow(i128 a, i128 b)
{
	i128 ans = 1;
	i128 base = a;
	while (b)
	{
		if (b & 1)
			ans *= base;
		base *= base;
		b >>= 1;
	}
	return ans;
}

map<i128, bool> mp;

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);

    read(n); read(K);
    // cout << fpow(2, 3) << endl;
    if (K == 1)
    {
    	ans = n;
    	cout << ans << endl;
    	return 0;
    }

    for (reg int k = K; k < 100 ; ++k)
    {
    	for (reg int i = 2; fpow(i, k) <= n && fpow(i, k) >= 1; ++i)
    	{
    		now = fpow(i, k);
    		// cout << i << ' ' << k << ' ' << now << endl;
    		if (!mp[now] && now <= n && now >= 1)
    			++ans, mp[now] = 1;
    	}
    }
    cout << ans + 1 << endl;
    return 0;
}


/*
#include <iostream>

#include <cmath>
#include <set>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

i64 n, k, ans;
set<i64> s;

inline i64 fpow(i64 a, i64 p)
{
    i64 base = a, ans = 1;
    while (p)
    {
        if (n / ans < base)
            return 0;
        if (p & 1)
            ans *= base;
        p >>= 1;
        if (n / base < base) { if (p) return 0; continue; }
        base *= base;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    if (k == 1)
    {
        printf("%lld\n", n);
        return 0;
    }
    for (int i = k; i <= 65; ++i)
    {
        for (reg i64 now = 1; now <= 1e6; ++now)
        {
            i64 res = fpow(now, i);
            if (res <= 0)
                break;
            if (k != 2 || res <= 1e12 || res > n || (sqrt(res) != (i64)(sqrt(res))))
                s.insert(res);
        }
    }
    ans = s.size();
    if (n > 1e12 && k == 2)
    {
        i64 l = 1, r = n, num = 0;
        while (l < r)
        {
            i64 mid = (l + r) >> 1;
            if (fpow(mid, 2))
                l = mid + 1, num = mid;
            else
                r = mid;
        }
        ans += num - 1e6;
    }

    cout << ((!ans) ? 1 : ans) << endl;
    return 0;
}
*/