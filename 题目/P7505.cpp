// Problem:      P7505 「Wdsr-2.5」小小的埴轮兵团
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P7505
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-02-28 20:35:58

#include <iostream>

#include <algorithm>
#include <vector>
#include <queue>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");
// #define push_front() insert(q.begin())
// #define pop_front() erase(q.begin())

using namespace std;

i64 n, ans, m, k, x, op, delta;
i64 a[1000010];

deque<int> q;

int main()
{
    scanf("%lld%lld%lld", &n, &m, &k);
    for (reg int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for (reg int i = 1; i <= n; ++i)
        q.push_back(a[i]);
    while (m--)
    {
        scanf("%lld", &op);
        if (op == 1)
        {
            scanf("%lld", &x);
            delta += x;
            while (!q.empty())
            {
                if (q.back() + delta > k)
                    q.pop_back();
                else
                    break;
            }
            // ans = q.size();
        }
        if (op == 2)
        {
            scanf("%lld", &x);
            delta -= x;
            while (!q.empty())
            {
                if (q.front() + delta < -k)
                    q.pop_front();
                else
                    break;
            }
            // ans = q.size();
        }
        if (op == 3)
            cout << q.size() << endl;
    }
    return 0;
}