// Problem:      1585：【例 1】Amount of Degrees
// Contest:      SSOIER
// URL:          http://ybt.ssoier.cn:8088/problem_show.php?pid=1585
// Memory Limit: 524 MB
// Time Limit:   1000 ms
// Created Time: 2023-03-10 19:57:19

#include <iostream>

#include <vector>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n'
#define pb push_back

using namespace std;

int x, y, k, b;
int f[1010][1010];

void init()
{
    for (reg int i = 0; i <= 31; ++i)
    {
        f[i][0] = 1;
        for (reg int j = 1; j <= i; ++j)
            f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
    }
}
int dp(int n)
{
    // if (n == 0) return 0;

    int ans = 0, lst = 0;
    vector<int> nums;
    while (n)
    {
        nums.pb(n % b);
        n /= b;
    }
    for (reg int i = nums.size() - 1; i >= 0; --i)
    {
        if (nums[i])
        {
            ans += f[i][k - lst];
            if (nums[i] > 1)
            {
                if (k - lst - 1 >= 0)
                	ans += f[i][k - lst - 1];
                break;
            }
            else ++lst;
            if (lst > k) break;
        }
        ans += (!i && lst == k);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> x >> y >> k >> b;
    init();
    cout << dp(y) - dp(x - 1) << endl;
    return 0;
}