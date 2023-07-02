#include <iostream>

#include <queue>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq!");

using namespace std;

const i64 inf = 0x7ffffffffff;

struct Edge
{
    i64 u, v, next;
    Edge() {}
    Edge(i64 _u, i64 _v, i64 _n) : u(_u), v(_v), next(_n) {}
} edge[80010];

struct Node
{
    i64 w, now;
    Node() {}
    Node(i64 _w, i64 _n): w(_w), now(_n) {}
    inline friend bool operator < (const Node &_x, const Node &_y) { return _x.w > _y.w; }
};

int n, m, tot;
int cnt, ans, hide;
i64 dis[40010], head[40010];
bool vis[40010];

inline void addEdge(i64 u, i64 v)
{
    edge[++tot] = Edge(u, v, head[u]);
    head[u] = tot;
}

void dijkstra()
{
    priority_queue<Node> q;
    
    for (reg int i = 1; i <= n; ++i)
        dis[i] = inf;
    dis[1] = 0;
    q.push(Node{0, 1});
    while (!q.empty())
    {
        Node x = q.top(); q.pop();
        int u = x.now;
        if (vis[u]) continue;
        vis[u] = 1;
        for (reg int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].v;
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
    for (i64 i = 1, u, v; i <= m; ++i)
    {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
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