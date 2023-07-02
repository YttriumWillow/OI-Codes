#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")


#include <iostream>

#include <algorithm>
#include <random>
#include <cstring>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n, mod;
int a[5010];
int b[5010];

namespace Solution
{
	mt19937 rnd(random_device{}());
	char ans[5010];
	inline void cheat()
	{
		for (reg int i = 1; i <= n - 1; ++i)
			ans[i] = 'D';
		for (reg int i = n; i <= 2 * n - 2; ++i)
			ans[i] = 'R';
		shuffle(ans + 1, ans + 2 * n - 1, rnd);
		for (reg int i = 1; i <= 2 * n - 2; ++i)
			cout << ans[i];
	}
	struct Node { int len = 0; string path = ""; } dp[110][110];
	inline void Subtask_1_2()
	{
		dp[1][1] = { a[1] * b[1] % mod, "" };
		for (reg int i = 2; i <= n; ++i)
			dp[i][1] = { dp[i - 1][1].len + a[i] * b[1] % mod, dp[i - 1][1].path + 'D' };
		for (reg int j = 2; j <= n; ++j)	
			dp[1][j] = { dp[1][j - 1].len + a[1] * b[j] % mod, dp[1][j - 1].path + 'R' };
		for (reg int i = 2; i <= n; ++i)
			for (reg int j = 2; j <= n; ++j)
			{
				if (i == 1 && j == 1) continue;
				int now = a[i] * b[j] % mod;
				int d = dp[i - 1][j].len + now;
				int r = dp[i][j - 1].len + now;
				if (r < d)
					dp[i][j] = { d, dp[i - 1][j].path + 'D' };
				else
					dp[i][j] = { r, dp[i][j - 1].path + 'R' };
			}
		cout << dp[n][n].path << endl;
		// check();
	}
}

using namespace Solution;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> mod;
	for (reg int i = 1; i <= n; ++i)
		cin >> a[i];
	for (reg int i = 1; i <= n; ++i)
		cin >> b[i];
	
	// cheat();
	
	if (n <= 100) Subtask_1_2();
	else cheat();
	return 0;
}