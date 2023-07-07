// Problem:      P7281 [COCI2020-2021#4] Vepar
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P7281
// Memory Limit: 500 MB
// Time Limit:   1500 ms
// Created Time: 2023-07-05 10:52:18 

#include <iostream>
#include <bitset>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e7 + 10;

int t, a, b, c, d;
int t1, t2;
bool tag[N];
int prime[N];
bitset<10000010> p;

inline void saber(int n)
{
    p.set(); p[0] = p[1] = 0;
    for (int i = 2; i * i <= n; ++i)
        if (p[i])
            for (int j = i << 1; j <= n; j += i)
                if (p[j]) p[j] = 0;
    for (int i = 2; i <= n; ++i)
    	if (p[i])
    		prime[++prime[0]] = i;
}

inline int cnt(int a, int x)
{
	int res = 0;
	while (x) res += (x / a), x /= a;
	return res;
}

inline bool Solve(int l1, int r1, int l2, int r2)
{
	for (int i = 1; i <= prime[0] && prime[i] <= r1; ++i)
	{
		t1 = cnt(prime[i], r1) - cnt(prime[i], l1 - 1);
		t2 = cnt(prime[i], r2) - cnt(prime[i], l2 - 1);
		if (t1 > t2) return false;
	} 
	return true;
}

int main()
{
	scanf("%d", &t); saber(1e7 + 1);
	while (t--)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if (c <= a && b <= d)		puts("DA");
		else if (a < c && d < b)	puts("NE");
		else puts(Solve(a, b, c, d) ? "DA" : "NE");
	}
	return 0;
}