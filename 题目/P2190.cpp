// Problem:      P2190 小Z的车厢
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2190
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-07-07 14:41:47

#include <iostream>

#define i64 long long

using namespace std;

const int N = 1e6 + 5;

int n, m;
int x, y, z;
int jca[N], nojj[N];
int ans, now;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 
	
    cin >> n >> m;
    
    for (int i = 1; i <= m; ++i)
    {
        cin >> x >> y >> z;
        jca[x] += z, nojj[y] += z;
        
        if (x > y) jca[1] += z;
    }
    for (int i = 1; i <= n; ++i)
    {
        now += jca[i] - nojj[i];
        ans = max(ans, now);
    }
    
    cout << ans / 36 + !!(ans % 36) << endl;
    return 0;
}