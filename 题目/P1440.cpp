// Problem:      P1440 求m区间内的最小值
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1440
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-06 19:20:44

#include <iostream>

#include <deque>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m;

struct Node
{
    int val, id;
} now;

deque<Node> q;

int main()
{
    scanf("%d%d", &n, &m); printf("0\n");

    for (reg int i = 1; i <= n; ++i)
    {
        scanf("%d", &now.val); now.id = i;
        if (i == 1) { q.push_back(now); continue;}
        
        while (!q.empty() && now.id - q.front().id > m)
            q.pop_front();
        printf("%d\n", q.front().val);
        while (!q.empty() && q.back().val > now.val)
            q.pop_back();
        q.push_back(now);
    }
    return 0;
}