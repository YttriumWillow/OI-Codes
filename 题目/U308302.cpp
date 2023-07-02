// Problem:      U308302 小清新构造题
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/U308302?contestId=115417
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-06-29 19:10:24 

#include <iostream>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

int n, k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	if (k & 1)
	{
		cout << "Yes" << endl;
		for (int i = 1; i < k - 1; +i += )
			cout << i << ' ' << i + 1 << endl;
		for (int i = k + 1; i <= )
	}
	return 0;
}