#include <iostream>

#include <vector>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define pb push_back

using namespace std;

struct Node
{
	int len;
	vector<int> now;
} dp[510];

int n1, n2, a[510], b[510];

int main()
{
	// freopen("subseq.in", "r", stdin);
	// freopen("subseq.out", "w", stdout);
	
    scanf("%d", &n1);
    for (int i = 1; i <= n1; ++i)
        scanf("%d", &a[i]);
    scanf("%d", &n2);
    for (int i = 1; i <= n2; ++i)
        scanf("%d", &b[i]);
    
    for (reg int i = 1; i <= n1; ++i)
    {
    	Node p; p.len = 0;
    	for (reg int j = 1; j <= n2; ++j)
    	{
    		if (a[i] > b[j] && dp[j].len > p.len)
    			p = dp[j];
    		// what the f**king equaltion ahhhhhhhhhhhhhhhhhhhh
    		// it takes me two thousand years to remember this s**t one
    		// O(n^2) yyds! go to the hell O(nlogn).
    		if (a[i] == b[j]) // 我谔谔这就是说狗尾续貂是么
    		{
    			dp[j].len = p.len + 1;
    			dp[j].now = p.now;
    			dp[j].now.pb(a[i]);
    		}
    	}
    }
    Node ans = dp[1]; int x = max(n1, n2);
    for (reg int i = 2; i <= x; ++i)
    {
    	if (dp[i].len > ans.len)
    		ans = dp[i];
    }
    cout << ans.len << endl;
    for (auto x : ans.now)
    	printf("%d ", x);
    return 0;
}