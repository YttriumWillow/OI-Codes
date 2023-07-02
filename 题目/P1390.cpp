// Problem:      P2398 GCD SUM
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2398
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-31 20:17:48 

#include <iostream>

#define i64 long long
#define u64 unsigned i64
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

i64 n, ans;
i64 f[2000010];
i64 phi[2000010];
i64 prime[2000010];
i64 phisum[2000010];

inline void init(u64 n)
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
	std::exit(0);
	cin >> n;
	init(n); 
	for (reg int i = 1; i <= n; ++i)
		ans += i * (phisum[n / i] - 1);
	cout << ans << endl;
    return 0;
}