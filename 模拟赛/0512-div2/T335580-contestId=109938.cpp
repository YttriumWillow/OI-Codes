// Problem:      T335580 魔女的归途
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/T335580?contestId=109938
// Memory Limit: 512 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-12 13:42:21 

#include <iostream>
#include <cmath>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int mod = 520;

int n, x;
int a[10010];
int b[10010];
i64 ans;

int main()
{
	scanf("%d", &n);
	for (reg int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (reg int i = 1; i <= n; ++i)
		b[a[i]] = abs(a[i] - i),
		ans += abs(a[i] - i);
	for (reg int i = 1; i <= n; ++i)
		printf("%d ", b[i]);
	printf("\n%lld\n", ans % mod);
	return 0;
}