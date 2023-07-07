// Problem:      P1681 最大正方形II
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1681
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-07-05 16:37:12

#include <iostream>

#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1510;

int n, m, ans;
int a[N][N];
int dp[N][N][2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            int v = a[i][j];
            
            dp[i][j][v] = min({ 
            	dp[i - 1][j - 1][v],
            	dp[i - 1][j][v ^ 1], 
            	dp[i][j - 1][v ^ 1], 
            }) + 1;
            
            ans = max(ans, dp[i][j][v]);
        }

    cout << ans << endl;
    return 0;
}
