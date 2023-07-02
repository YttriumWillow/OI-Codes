// Problem:      U288300 立方
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/U288300
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-05-02 09:26:30 

#include <iostream>

#define i64 long long
#define reg register
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

i64 a, b, c, x, T;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while (T--)
	{
		cin >> a >> b >> c >> x;
		if (a + b + c == x)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}