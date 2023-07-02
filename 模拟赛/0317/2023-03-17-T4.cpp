#include <iostream>

#include <queue>
#include <vector>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq!");
#define pb push_back

using namespace std;

const i64 inf = 0x7ffffffffff;

struct Node
{
    i64 w, now;
    friend bool operator < (const Node &_x, const Node &_y) { return _x.w > _y.w; }
};

vector<int> g[40010];

i64 n, m, tot;
i64 cnt, ans, hide;
i64 dis[40010], head[40010];
bool vis[40010];

inline void dijkstra()
{
    priority_queue<Node> q;

    for (reg int i = 1; i <= n; ++i)
        dis[i] = inf;
    dis[1] = 0; q.push(Node{0, 1});
    
    while (!q.empty())
    {
        Node x = q.top(); q.pop();
        
        int u = x.now;
        if (vis[u]) continue;
        vis[u] = 1;
        
        for (auto v : g[u])
        {
            if (dis[v] > dis[u] + 1)
            {
                dis[v] = dis[u] + 1;
                q.push(Node{dis[v], v});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (reg int i = 1, u, v; i <= m; ++i)
    {
        cin >> u >> v;
        g[u].pb(v), g[v].pb(u);
    }

    dijkstra();

    // for (int i = 1; i <= n; ++i)
    // printf("%lld ", dis[i]);

    for (reg int i = 1; i <= n; ++i)
        if (dis[i] > ans)
            ans = dis[i], hide = i;
    for (reg int i = 1; i <= n; ++i)
        cnt += (dis[i] == ans);

    cout << hide << ' ' << ans << ' ' << cnt;
    return 0;
}