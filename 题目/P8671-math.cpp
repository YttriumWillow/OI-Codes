// Problem:      P8671 [蓝桥杯 2018 国 AC] 约瑟夫环
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P8671
// Memory Limit: 256 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-05 13:07:48 

#include <iostream>

#include <vector>
#include <algorithm>

#define i64 long long
#define reg register
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

int n, k;
vector <int> b;
inline int g(int n, int k)
{
	while (n)
	{
		b.pb(n % k);
		n /= k;
	}
	b.insert(b.begin(), b.back());
	b.pop_back(); reverse(b.begin(), b.end());
	int res = 0; 
	for (auto x : b)
		res = res * k + x;
	return res;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	cout << g(n, k) << endl;
	return 0;
}