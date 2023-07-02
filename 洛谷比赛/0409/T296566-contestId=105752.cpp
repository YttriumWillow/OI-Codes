// Problem:      T296566 藤原「灭罪寺院伤」
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/T296566?contestId=105752
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-09 21:21:08 

#include <iostream>


#define i64 long long
#define reg regisiter
#define qwq puts("fzy qwq ~");

using namespace std;

int n, xe, ye;
int blkx[100010];
int blky[100010];

int main()
{
	cin >> n >> xe >> ye;
	for (reg int i = 1, x, y; i <= n; ++i)
	{
		cin >> x >> y;
		blkx[i] = x + i;
		blky[i] = y;
	}
	for (reg int i = n; i >= 1; --i)
	{
		if (blkx[i] >= xe && blky[i] >= ye)
	}
	return 0;
}