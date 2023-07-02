// Problem:      [ABC059D] Alice&Brown
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/AT_arc072_b
// Memory Limit: 256 MB
// Time Limit:   2000 ms
// Created Time: 2023-05-05 19:38:55 

#include <iostream>

#include <cmath>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

i64 n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cout << ( abs(n - m) <= 1 ? "Brown" : "Alice") << endl;
	return 0;
}