// Problem:      T335669 Darling's Game
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/T335669?contestId=109939
// Memory Limit: 512 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-12 13:49:48 

#include <iostream>
#include <cmath>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

i64 n0, n2;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n0 >> n2;
	if (n2 > n0 && n0 != 0) cout << -(n2 - n0) * (n2 - n0) << endl;
	else cout << n0 * n0 - n2 * n2 << endl;
	return 0;
}