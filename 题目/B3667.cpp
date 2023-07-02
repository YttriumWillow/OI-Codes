// Problem:      B3667 求区间所有后缀最大值的位置
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/B3667
// Memory Limit: 512 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-04 08:20:53

#include <iostream>

#include <deque>

#define i64 long long
#define u64 unsigned i64
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, k, l, r;
u64 a[1000010];

deque<int> q;

int main()
{
    scanf("%d%d", &n, &k);
    for (reg int i = 1; i <= n; ++i)
    {
        scanf("%llu", &a[i]);

        if (!q.empty() && q.front() + k - 1 < i)
            q.pop_front();
        while (!q.empty() && a[q.back()] <= a[i])
            q.pop_back();
        q.push_back(i);
        if (i >= k)
        	printf("%llu\n", q.size());
    }
    return 0;
}