#include <iostream>

#include <vector>

#define i64 long long
#define endl '\n'
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 31;

int k, nd[N];
int n, ct[N][N];
bool vis[N];
int faq[N];
vector<int> ans;
int ansl = 114514;

inline bool chk()
{
	for (int i = 1; i <= k; ++i)
	{
		// cerr << faq[i] << " \n"[i == k];
		if (faq[i] < nd[i])
			return 0;
	}
	return 1;
}

inline void dfs(int now, int usd)
{
	if (usd > ansl) return;
	if (now > n) return;
	
	// cerr << now << ' ' << usd << endl;
	vis[now] = 1; ++usd;
	for (int i = 1; i <= k; ++i)
		faq[i] += ct[now][i];
		
	if (chk())
	{
		// cerr << "suc " << now << ' ' << usd << endl;
		if (usd < ansl)
		{
			ansl = usd;
			ans.clear();
			for (int i = 1; i <= n; ++i)
				if (vis[i])
					ans.pb(i);
		}
	}
	dfs(now + 1, usd);
	
	for (int i = 1; i <= k; ++i)
		faq[i] -= ct[now][i];
	
	vis[now] = 0; --usd;
	
	dfs(now + 1, usd);
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> k;
	for (int i = 1; i <= k; ++i)
		cin >> nd[i];
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= k; ++j)
			cin >> ct[i][j];
	
	dfs(1, 0);
	
	cout << ans.size();
	for (auto x : ans)
		cout << ' ' << x;
	
	return 0;
}