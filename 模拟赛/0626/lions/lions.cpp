#pragma GCC optimize(3)
#pragma GCC target("avx,sse2,sse3,sse4,mmx,avx2,avx512f,popcnt,sse4.1,sse4.2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")

#include <iostream>

#include <queue>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define Pii pair<int, int>
#define abl first
#define age second
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 1e5 + 10;

int n, a[N];
Pii lst;
vector<Pii> q;
vector<int> ans;

inline void insert(int age, int abl)
{
	Pii x = { abl, age };
	q.insert(lower_bound(q.begin(), q.end(), x), x);
}

inline Pii getmax()
{ return q.back(); }
inline void delmax()
{ q.erase(--q.end()); }
inline Pii getmin()
{ return q.front(); }
inline void delmin()
{ lst = q.front(); q.erase(q.begin()); }

int main()
{
	freopen("lions.in", "r", stdin);
	freopen("lions.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		insert(i, a[i]);
	}
	// for (int i = 1; i <= 10; ++i)
	while (q.size() > 3)
	{
		Pii mx = getmax(), mn = getmin();
		delmax(); delmin(); ans.pb(mn.age);
		insert(mx.age, mx.abl - mn.abl);
	}
	cout << n - 3 << endl;
	sort(ans.begin(), ans.end());
	for (auto x : ans)
		cout << x << ' ';
	return 0;
}