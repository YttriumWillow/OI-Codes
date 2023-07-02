// Problem:      P3590 [POI2015] TRZ
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3590
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-06-28 19:41:47 

#include <iostream>
#include <cstring>

using namespace std;
const int N = 1e6 + 5;

string st;
int ans = 1, n;
int b[N], c[N], s[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> st;
	
	for (int i = 1; i <= n; ++ i)
	{
		b[i] = b[i - 1] + (st[i - 1] == 'B');
		c[i] = c[i - 1] + (st[i - 1] == 'C');
		s[i] = s[i - 1] + (st[i - 1] == 'S');
	}
	
	int sb0, sc0, ss0;
	int sb1, sc1, ss1;
	int sb2, sc2, ss2;
	int sb3, sc3, ss3;
	
	for (int i = 1; i <= 3; ++i)
		for (int j = n; j >= i + 1; --j)
		{
			sb0 = b[j] - b[i - 1], 
			sc0 = c[j] - c[i - 1], 
			ss0 = s[j] - s[i - 1];
			if (sb1 != sc1 && sc1 != ss1 && ss1 != sb1)
			{
				if (ans < j - i + 1)
					ans = j - i + 1;
				break;
			}
		}
		
	for (int j = n; j >= n - 2; --j)
		for (int i = 4; i <= j - 1; ++i)
		{
			sb = b[j] - b[i - 1], 
			sc = c[j] - c[i - 1], 
			ss = s[j] - s[i - 1];
			if (sb != sc && sc != ss && ss != sb)
			{
				if (ans < j - i + 1)
					ans = j - i + 1;
				break;
			}
		}
	cout << ans << endl;
	
	return 0;
}