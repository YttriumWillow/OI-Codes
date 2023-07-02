// Problem:      P3435 [POI2006] OKR-Periods of Words
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3435
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-28 21:22:07 

#include <iostream>

#include <cstring>
#include <algorithm>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

i64 k, ans;
string s;
i64 fail[1000010];

inline void KMP(string s, i64 fail[])
{
	i64 n = s.size(); fail[0] = fail[1] = 0;
	for (reg int i = 1, j = 0; i < n; ++i)
	{
		while (j && s[i] != s[j])
			j = fail[j];
		if (s[i] == s[j])
			++j;
		fail[i + 1] = j;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> k;
	cin >> s;
	KMP(s, fail);
	for (reg int i = 1; i <= k; ++i)
	{
        i64 j = i;
        while (fail[j])
        	j = fail[j];
        if (fail[i] != 0)
        	fail[i] = j;
        ans += (i - j);
    }
    cout << ans << endl;
	return 0;
}