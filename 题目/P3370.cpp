// Problem:      P3370 【模板】字符串哈希
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3370
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-05 19:59:55 

#include <iostream>

#include <cstring>

#define i64 long long
#define u64 unsigned i64
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const u64 base = 131;

int n;
u64 ans;
string str;
bool h[120000001];

u64 Hash(string str)
{
	int res = 0;
	for (auto x : str)
		res = (res * base + (u64)x) % 114514191;
	return res % 114514191;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (reg int i = 1; i <= n; ++i)
		cin >> str, h[Hash(str)] = true;
	for (reg int i = 0; i <= 120000000; ++i)
		if (h[i])
			++ans;
	cout << ans << endl;
	return 0;
}