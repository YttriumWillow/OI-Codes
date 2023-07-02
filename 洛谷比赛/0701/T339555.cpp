// Problem:      T339555 『XYGOI round1』好多数
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/T339555?contestId=113611
// Memory Limit: 512 MB
// Time Limit:   2000 ms
// Created Time: 2023-07-01 16:00:50 

#include <iostream>

#include <map>
#include <unordered_map>
#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int n, a, b, q, x;
unordered_map<int, int> faq;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	while (cin >> a >> b)
	{
		cerr << a << ' ' << b << endl;
		if (a == 0 && b == 0) break; 
		faq[a] += b;
	}
		
	cin >> q;
	for (int i = 1; i <= q; ++i)
	{
		cin >> x;
		if (faq[x]) cout << faq[x] << ' ';
		else cout << 0 << ' ';
	}
	return 0;
}