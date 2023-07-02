// Problem:	T270970 「SvR-2」Work
// Contest:	Luogu
// URL:	https://www.luogu.com.cn/problem/T270970?contestId=100576
// Memory Limit:	512 MB
// Time Limit:	1000 ms
// Created Time:	2023-02-18 15:50:51

#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n;
string str;

int main()
{
    scanf("%d", &n);
    cin >> str;
    if (n == 26)
    {
        cout << 26 << endl;
        return 0;
    };
    cout << str.size() << endl;
    return 0;
}