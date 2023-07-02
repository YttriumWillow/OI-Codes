// Problem:      C. LuoTianyi and the Show
// Contest:      Codeforces - Codeforces Round 872 (Div. 2)
// URL:          https://codeforces.com/contest/1825/problem/C
// Memory Limit: 256 MB
// Time Limit:   2000 ms
// Created Time: 2023-05-08 20:32:46 

#include <iostream>

#define i64 long long
#define reg register
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

#include <vector>
#include <algorithm>
// wait what is this really a balanced tree
template<typename Tp>
struct BalancedTree
{
    vector<Tp> t; typename::vector<Tp>::iterator pos = t.begin();
    inline void getpos(Tp x) { pos = lower_bound(t.begin(), t.end(), x); }
    inline void insert(Tp x) { getpos(x); t.insert(pos, x); }
    inline void del(Tp x)    { getpos(x); t.erase(pos); }
    inline void clear()		 { t.clear(); }
    inline bool empty()		 { return t.empty(); }
    inline bool exist(Tp x)  { getpos(x); return (*(pos) == x); }
    inline Tp size()		 { return t.size(); }
    inline Tp queryrnk(Tp x) { getpos(x); return pos - t.begin() + 1; }
    inline Tp queryval(Tp x) { getpos(x); return t.at(x - 1); }
    inline Tp prev(Tp x)     { getpos(x); return *(--pos); }
    inline Tp next(Tp x)     { getpos(x); return *upper_bound(t.begin(), t.end(), x); }
};

BalancedTree<int> t;

int T, n, m;
int cnt1, cnt2, cnt;
int x[100010];
vector<int> v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		v.clear(); cnt = cnt1 = cnt2 = 0;
		for (reg int i = 1; i <= n; ++i)
		{
			cin >> x[i];
			cnt1 += (x[i] == -1);
			cnt2 += (x[i] == -2);
			if (x[i] > 0) v.pb(x[i]);
		}
		sort(v.begin(), v.end());
		auto pos = unique(v.begin(), v.end()); v.erase(pos, v.end());
		cnt = v.size(); l = 
		cerr << cnt << ' ' << cnt1 << ' ' << cnt2 << endl;
		cnt = min(m, cnt + cnt1);
		cnt = min(m, cnt + cnt2);
		cout << cnt << endl;
	}
	return 0;
}