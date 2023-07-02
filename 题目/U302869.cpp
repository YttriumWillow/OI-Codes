// Problem:      U302869 序列操作
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/U302869?contestId=108475
// Memory Limit: 512 MB
// Time Limit:   1000 ms
// Created Time: 2023-07-01 21:03:59 

#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int n, x, sum;
bool flg;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> x; if (x < 0) flg = 1;
		sum += x;
	}
	cout << sum - 1 << endl;
	return 0;
}