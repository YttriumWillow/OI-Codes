// Problem:	T270967 「SvR-2」音符
// Contest:	Luogu
// URL:	https://www.luogu.com.cn/problem/T270967?contestId=100576
// Memory Limit:	128 MB
// Time Limit:	1000 ms
// Created Time:	2023-02-18 14:38:35 

#include <iostream>

#include <cstring>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

longint n, T, k, a, b;
string str;

void init(string& x, int n)
{
	string base = "Nahida";
	x = ""; int i = 0;
	for (; i + base.size() < n; i += base.size())
		x += base;
	for (; i < n; ++i)
		x += base[i % base.size()];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
    cin >> T;
    while (T--)
    {
        cin >> n >> k >> a >> b;
        init(str, n);
        cout << 0 << endl;
        cout << str << endl;
    }
    return 0;
}