// Problem:      P1886 滑动窗口 /【模板】单调队列
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1886
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-06 20:03:31 

#include <iostream>

#include <deque>
#include <vector>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, m;

struct Node
{
    int val, id;
} now;

deque<Node> q1;
deque<Node> q2;
vector<int> ans;

int main()
{
    scanf("%d%d", &n, &m);

    for (reg int i = 1; i <= n; ++i)
    {
        scanf("%d", &now.val); now.id = i;
        
        
        if (i == 1) { q1.push_back(now); continue;}
        while (!q1.empty() && now.id - q1.front().id > m)
            q1.pop_front();
        printf("%d ", q1.front().val);
        while (!q1.empty() && q1.back().val > now.val)
            q1.pop_back();
        q1.push_back(now);
        
        
        
        
        // if (i == 1) { q2.push_back(now); continue;}
        // while (!q2.empty() && now.id - q2.front().id > m)
            // q2.pop_front();
        // ans.push_back(q2.front().val);
        // while (!q1.empty() && q2.back().val <= now.val)
            // q2.pop_back();
        // q2.push_back(now);
    }
    // for (auto x : ans)
    	// printf("%d ", x);
    return 0;
}