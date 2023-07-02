// farewell

#include <iostream>

#include <algorithm>
#include <queue>

#define i64 long long
#define reg register
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

i64 l, n, m;
i64 ans;
i64 a[100010];
i64 b[100010];

struct Node
{
    i64 idx, time;
    inline friend bool operator < (Node _x, Node _y)
    { return _x.time > _y.time; }
};
priority_queue<Node> qa;
priority_queue<Node> qb;
vector<i64> timer = { 0 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> l >> n >> m;
    for (reg int i = 1; i <= n; ++i)
        cin >> a[i], qa.push({ i, a[i] });
    for (reg int i = 1; i <= m; ++i)
        cin >> b[i], qb.push({ i, b[i] });
	
	for (reg int i = 1; i <= l; ++i)
	{
		Node now = qa.top(); qa.pop();
		qa.push({ now.idx, now.time + a[now.idx] });
		timer.pb(now.time);
	}
	for (reg int i = l; i >= 1; --i)
	{
		Node now = qb.top(); qb.pop();
		qb.push({ now.idx, now.time + b[now.idx] });
		ans = max(ans, timer[i] + now.time);
	}
	cout << ans << endl;
    return 0;
}