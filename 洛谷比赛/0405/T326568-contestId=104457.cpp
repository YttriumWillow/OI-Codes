// Problem:      T326568 「GMOI R2-T1」轴对称
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/T326568?contestId=104457
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-04-05 14:16:46

#include <iostream>

#define i64 long long
#define reg register
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

struct RGB
{
    i64 v[4] = { 0 };
    friend bool operator == (const RGB &_x, const RGB &_y)
    { return (_x.v[1] == _y.v[1]) && (_x.v[2] == _y.v[2]) && (_x.v[3] == _y.v[3]); }
    friend bool operator != (const RGB &_x, const RGB &_y)
    { return !(_x == _y); }
} a[110][110];

int n, m, q, ans;
int i, j, t, c;

inline bool get()
{
	for (reg int i = 1; i <= n; ++i)
		for (reg int j = 1; j <= (m >> 1) + 1; ++j)
			if (a[i][j] != a[i][m - j + 1])
				return false;
	return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;
    for (reg int faq = 1; faq <= q; ++faq)
    {
        cin >> i >> j >> t >> c;
        
        a[i][j].v[t] = (a[i][j].v[t] + c % 256) % 256;
        
        if (a[i][j] != a[i][m - j + 1])
        	ans = 0;
        else ans = get();
        
        cout << (ans ? "Yes" : "No") << endl;
    }
    return 0;
}