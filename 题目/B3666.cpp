// Problem:      B3666 求数列所有后缀最大值的位置
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/B3666
// Memory Limit: 512 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-03 19:42:29

#include <iostream>

#include <stack>

#define i64 long long
#define u64 unsigned i64
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, ans;
u64 v;

template <typename Tp> struct monostack
{
    stack<Tp> st;
    void pushAndUpdateAns(Tp x) // 对于本题使用修改的 push 函数，顺手更新答案
    {
        while (!st.empty() && st.top().second <= x.second)
        {
            popAndUpdateAns();
        }
        st.push(x);
        ans ^= st.top().first;
    }
    void popAndUpdateAns() // pop 函数，在剔除栈顶元素同时消除已入栈元素的影响（因为有异或）
    {
        ans ^= st.top().first;
        st.pop();
    }
    void push(Tp x) // 通常使用的 push 函数
    {
        while (!st.empty() && st.top().second <= x.second)
            st.pop();
        st.push(x);
    }
    void pop(Tp x) // 通常使用的 pop 函数
    {
        st.pop();
    }
};

monostack<pair<int, u64>> st;

int main()
{
    scanf("%d", &n);
    for (reg int i = 1; i <= n; ++i)
    {
        scanf("%llu", &v);
        st.pushAndUpdateAns({i, v});
        printf("%d\n", ans);
    }
    return 0;
}