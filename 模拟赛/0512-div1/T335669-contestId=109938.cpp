// Problem:      T335669 Darling's Game
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/T335669?contestId=109939
// Memory Limit: 512 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-12 13:49:48 

#include <iostream>
#include <cmath>
#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const i64 inf = 0xfffffffffffff;

i64 n0, n2;

i64 res1 = -inf;
i64 res2 = -inf;
i64 res3 = -inf;
i64 res4 = -inf;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	scanf("%lld%lld", &n0, &n2);
	if (n2 > n0)
	{
		i64 blk = n2 / (n0 + 1);
		i64 rem = n2 % (n0 + 1);
		i64 cnt = (n2 - rem) / blk - rem;
		
		res2 = -1ll * rem * (1 << (blk + 1));
		res2 += -1ll *  cnt * (1 << blk);
		res2 += n0;
		printf("%lld\n", max(-(n2 - n0) * (n2 - n0), res2));
	}
	else
	{
		i64 ano = n2 - n2 / 2;
		res1 = (n0 * n0) - (n2 / 2) * (n2 / 2) - ano * ano;
		printf("%lld\n", max((n0 * n0) - (n2 * n2), res1));
	}
	// printf("%lld\n", );
	return 0;
}