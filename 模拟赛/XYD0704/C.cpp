#pragma GCC optimize(2)

#include <iostream>

#include <queue>
#include <vector>

#define i64 long long
#define endl '\n'
#define pb push_back
#define Pii pair<int, int>
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 2e6 + 10;
const int inf = 0x3fffffff;

char ch;
int n, m, s0, s1;
int s[N], a[N];
int l[N], r[N];
bool vis[N];
vector<Pii> res;

struct Node
{
	int d, l, r;
	friend bool operator < (const Node& a, const Node& b)
	{ return (a.d != b.d ? a.d > b.d : (a.l != b.l ? a.l > b.l : a.r > b.r)); } 
};

priority_queue<Node> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> ch, s[i] = ch - '0';
		
	for (int i = 2; i <= n; ++i)
		l[i] = i - 1;
	for (int i = 1; i < n; ++i)
		r[i] = i + 1;
		
	for (int i = 1; i <= n; ++i)
		s0 += (s[i] == 0),
		s1 += (s[i] == 1);
	
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	
	for (int i = 2; i <= n; ++i)
		if (s[i] != s[i - 1])
			q.push({ abs(a[i] - a[i - 1]), i - 1, i });
	
	while (s0 && s1)
	{
		Node u = q.top(); q.pop();
		
		if (vis[u.l] || vis[u.r]) continue;
		
		
		if (l[u.l]) r[ l[u.l] ] = r[u.r];
		if (r[u.r]) l[ r[u.r] ] = l[u.l];
		
		if (l[u.l] && r[u.r] && s[l[u.l]] != s[r[u.r]])
			q.push({ abs( a[l[u.l]] - a[r[u.r]] ), l[u.l], r[u.r] });
		
		res.pb({ u.l, u.r });
		vis[u.l] = vis[u.r] = 1;
		--s0, --s1;
	}
	cout << res.size() << endl;
	for (auto p : res)
		cout << p.first << ' ' << p.second << endl;
	return 0;
}