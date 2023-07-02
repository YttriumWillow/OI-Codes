#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int mod = 10000;

int n;
int dp[1000010][4];
int a[1000010];

int main()
{
    scanf("%d", &n);
    // a[0] = 1; a[1] = 1; a[2] = 2;
    // for (reg int i = 3; i <= n; ++i)
    //     a[i] = ((2 * a[i - 1]) % mod + a[i - 3]) % mod;
    
    // dp[1][0] = 0;
    dp[1][1] = 0;
    dp[1][2] = 0;
    dp[1][3] = 1;

    // dp[2][0] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[2][3] = 2;
    for (reg int i = 3; i <= n; ++i)
    {
        // dp[i][0] = dp[i - 1][3] % mod;

        dp[i][1] = (dp[i][1] + dp[i - 2][3]) % mod;
        dp[i][1] = (dp[i][1] + dp[i - 1][2]) % mod;

        dp[i][2] = (dp[i][2] + dp[i - 2][3]) % mod;
        dp[i][2] = (dp[i][2] + dp[i - 1][1]) % mod;

        dp[i][3] = (dp[i][3] + dp[i - 1][3]) % mod;
        dp[i][3] = (dp[i][3] + dp[i - 2][3]) % mod;
        dp[i][3] = (dp[i][3] + dp[i - 1][2]) % mod;
        dp[i][3] = (dp[i][3] + dp[i - 1][1]) % mod;
    }

    printf("%d\n", dp[n][3] % mod);
    return 0;
}