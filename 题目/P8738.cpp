// Problem:	P8738 [蓝桥杯 2020 国 C] 天干地支
// Contest:	Luogu
// URL:	https://www.luogu.com.cn/problem/P8738
// Memory Limit:	128 MB
// Time Limit:	1000 ms
// Created Time:	2023-02-23 21:03:17

#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n;
string t[10] = {"geng", "xin", "ren", "gui", "jia", "yi", "bing", "ding", "wu", "ji"};
string d[12] = {"shen", "you", "xu", "hai", "zi", "chou", "yin", "mao", "chen", "si", "wu", "wei"};

int main()
{
    cin >> n;
    cout << t[n % 10] << d[n % 12] << endl;
    return 0;
}