// Problem:      P8670 [蓝桥杯 2018 国 B] 矩阵求和
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P8670
// Memory Limit: 256 MB
// Time Limit:   2000 ms
// Created Time: 2023-04-02 19:10:29 

#include <iostream>

#define i64 long long
#define u64 unsigned i64
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int mod = 1e9 + 7;

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
	for (reg i64 i = 1; i <= n; ++i)
		ans = (ans + ((i * i) % mod) * ((phisum[n / i] * 2 - 1) % mod) % mod) % mod;
	cout << ans << endl;
    return 0;
}