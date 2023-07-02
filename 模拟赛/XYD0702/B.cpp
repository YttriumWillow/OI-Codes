#include <iostream>

#include <algorithm>

#define i64 long long
#define endl '\n'
#define Pii pair<int, int>
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 5e4 + 10;
const int W = 1e5 + 10;

int n, l, w, ans;
Pii a[N]; bool flg;
int dp[W];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
    	cin >> l >> w;
    	a[i] = { l, w };
    }
    
    sort(a + 1, a + n + 1, greater<Pii>());
    			
	for (int i = 1; i <= n; ++i, flg = 0)
	{
		for (int j = 1; j <= ans; ++j)
			if (dp[j] >= a[i].second)
			{
				dp[j] = a[i].second;
				flg = 1; break;
			}
		if (!flg) dp[++ans] = a[i].second;
	}
	
    cout << ans << endl;
    return 0;
}