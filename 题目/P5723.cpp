// Problem:      P5723 【深基4.例13】质数口袋
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P5723
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-03 21:18:48 

#include <iostream>

using namespace std;

int a, b, c, i;
int main()

{
    cin >> a;
    for (i = 2; c + i <= a; i++)
    {
        if (i % 2 == 1 || i == 2)
        {
            cout << i << endl;
            c = c + i;
            b++;
        }
    }
    cout << b;
    return 0;
}