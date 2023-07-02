// Problem:      P2257 YY的GCD
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2257
// Memory Limit: 500 MB
// Time Limit:   4000 ms
// Created Time: 2023-04-01 14:05:29 

// Problem:      P2568 GCD
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2568
// Memory Limit: 250 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-31 19:24:46 

#include <iostream>

#define i64 long long
#define u64 unsigned i64
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

i64 n;
i64 phi[20000010];
i64 prime[20000010];
i64 phisum[20000010];
i64 ans;

inline void Euler(i64 n)
{
	phi[1] = 1;
    for (reg int i = 2; i <= n; ++i)
    {
        if (!prime[i]) prime[++prime[0]] = i, phi[i] = i - 1;
        for (reg int j = 1; j <= prime[0] && i * prime[j] <= n; ++j)
        {
            prime[i * prime[j]] = 1;
            if (!(i % prime[j])) { 
            	 phi[i * prime[j]] = phi[i] * prime[j]; break; }
            else phi[i * prime[j]] = phi[i] * phi[prime[j]];
        }
    }
    for (reg int i = 1; i <= n; ++i)
    	phisum[i] = phisum[i - 1] + phi[i];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n; Euler(n);
	for (reg int i = 1; i <= prime[0]; ++i)
		ans += phisum[n / prime[i]] * 2 - 1;
	cout << ans << endl;
    return 0;
}