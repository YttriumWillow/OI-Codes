#pragma GCC optimize(2)
// #pragma GCC target("avx,sse2,sse3,sse4,mmx,avx2,avx512f,popcnt,sse4.1,sse4.2")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("inline")

#include <iostream>

#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

#define int long long
#define endl '\n'
#define pb push_back
#define ist insert
#define all(x) x.begin(),x.end()
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;
const int inf = 0x3fffffff;

int n, t;
int faq[N];
vector<int> nd[N];
priority_queue<int, vector<int>, greater<int>> val;

signed main()
{
    freopen("balance.in", "r", stdin);
    freopen("balance.out", "w", stdout);
    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> faq[i], val.push(faq[i]);
    int res = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (faq[i - 1] != faq[i])
        {
            res += abs(faq[i - 1] - faq[i]);
            nd[faq[i]].pb(faq[i - 1]);
            nd[faq[i - 1]].pb(faq[i]);
        }
    }
    int ans = res;
    while (!val.empty())
    {
        int wtf = val.top(); val.pop();
        if (nd[wtf].empty()) continue;
        sort(all(nd[wtf]));
        
        int sht = res, t = nd[wtf][nd[wtf].size() >> 1];
		for (auto i : nd[wtf])
			sht += abs(t - i) - abs(wtf - i);
		ans = min(ans, sht);
    }
    cout << ans << endl;
    return 0;
}