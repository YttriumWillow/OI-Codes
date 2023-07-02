#include <iostream>

#include <cmath>
#include <vector>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");
#define endl '\n'
#define pb push_back

using namespace std;

struct Node
{
    i64 l, r, v;
} s[1000010];

vector<i64> tim[1000010];
i64 n, T, cnt = 0;
i64 dp[1000010];
i64 a, b, c, q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
    cin >> n >> T;
    for (reg int i = 1; i <= n; ++i)
    {
        cin >> q;
        while (q--)
        {
            cin >> a >> b >> c;
            ++cnt;
            s[cnt] = {a, b, c};
            tim[b].pb(cnt);
        }
    }
    for (reg int i = 1; i <= T; ++i)
    {
        dp[i] = dp[i - 1];
        if (!tim[i].size())
            continue;
        for (reg int j = 0, faq; j <= tim[i].size() - 1; ++j)
        {
            faq = tim[i][j];
            dp[i] = max(dp[i], dp[i - (s[faq].r - s[faq].l + 1)] + s[faq].v);
        }
    }
    cout << dp[T] << endl;
    return 0;
}