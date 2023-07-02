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

#include <vector>
#include <cstring>

#define i64 long long
#define reg register
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

int n, q;
int b[11];
vector<int> ans;
int reject[1000010];

inline bool check(int x)
{
	int cnt = 0;
    while (x > 0) { b[++cnt] = x % 10; x /= 10; }
    for (reg int i = 1; i <= cnt; ++i)
    {
        for (reg int j = 1; j <= cnt; ++j)
            if (i != j)
            	if (b[i] == b[j])
            		return false;
    }
    return true;
}

inline void init(int n)
{
	ans.pb(0);
    for (reg int i = 1; i <= n; ++i)
        if (check(i))
        	ans.pb(i);
	for (reg int i = 1; i < ans.size(); ++i)
		reject[ans[i]] = i;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> q >> n; init(n);
	while (q--)
	{
		int x;
		cin >> x;
		if (reject[x] == 0)
			cout << "not exist!" << endl;
		else
			cout << reject[x] << endl;
	}
    return 0;
}