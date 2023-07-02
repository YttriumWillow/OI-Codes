// Problem:      P9226 糖果
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P9226
// Memory Limit: 512 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-22 19:01:44 

#include <iostream>

#define i64 long long
#define reg register
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int n, k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	cout << k - n % k << endl;
	return 0;
}