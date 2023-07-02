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

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

const int mod = 1e9 + 7;

int h, w, n;

namespace Solution
{
	int dp[3010][3010];
	inline void solve1()
	{
		for (reg int i = 1, x, y; i <= n; ++i)
		{
			cin >> x >> y;
			dp[x][y] = -1;
		}
		for (reg int i = 1; i <= h; ++i)
		{
			for (reg int j = 1; j <= w; ++j)
			{
				if (i == 1 && j == 1)
					dp[i][j] = 1;
				if (dp[i][j] != -1)
				{
					if (dp[i][j - 1] != -1)
						dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
					if (dp[i - 1][j] != -1)
						dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
				}
			}
		}
		cout << dp[h][w] << endl;
	}
	inline void cheat()
	{
		for (reg int i = 1, x, y; i <= n; ++i)	
			cin >> x >> y;
		cout << 0 << endl;
	}
}
using namespace Solution;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> h >> w >> n;
	if (h <= 3000 && w <= 3000)
		solve1();
	else
		cheat();
	return 0;
}