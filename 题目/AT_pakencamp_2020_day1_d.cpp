// Problem:      立方体を壊せ！
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/AT_pakencamp_2020_day1_d
// Memory Limit: 1 MB
// Time Limit:   2000 ms
// Created Time: 2023-05-08 19:08:23

#include <iostream>

#include <cmath>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

#define Cub(x) ((x) * (x) * (x))

i64 n, k;

int main()
{
    cin >> n >> k;

    if (k <= n)
    	cout << Cub(k) << endl;
    else if (k <= 2 * n)
    	cout << Cub(k) - 3ll * Cub(k - n) << endl;
    else if (k <= 3 * n)
    	cout << Cub(n) * 6ll - Cub(n - (k - 2 * n)) << endl;
    else
    	cout << Cub(n) * 6ll << endl;
    return 0;
}
