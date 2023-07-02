// Problem:      P8671 [蓝桥杯 2018 国 AC] 约瑟夫环
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P8671
// Memory Limit: 256 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-29 15:40:46

#include <iostream>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, k;

inline int find(const int& n, const int& k)
{
    int pos = 0;
    for (reg int i = 2; i <= n; ++i)
        pos = (pos + k) % i;
    return pos + 1;
}

int main()
{
    cin >> n >> k;
    cout << find(n, k) << endl;
    return 0;
}