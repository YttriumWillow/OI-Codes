// Problem:      T271869 「GLR-R4」芒种
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/T271869?contestId=83892
// Memory Limit: 512 MB
// Time Limit:   2000 ms
// Created Time: 2023-03-18 15:51:35

#include <iostream>

#include <iomanip>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int T;
double n, m;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        if (n == 1)
        	cout << fixed << setprecision(6) << 1 << endl;
        else if (n == m || m == 0)
        	cout << fixed << setprecision(6) << n / 2 << endl;
        else
        	cout << fixed << setprecision(6) << n / 2 << endl;
    }
    return 0;
}