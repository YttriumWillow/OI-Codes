// Problem:      P3946 ことりのおやつ（小鸟的点心）
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P3946
// Memory Limit: 125 MB
// Time Limit:   1000 ms
// Created Time: 2023-07-04 16:46:52

#include <bits/stdc++.h> //变量名跟题目中一模一样哦，不需要注释了吧
#define inf 1e9
using namespace std;
int n, m, s, t, g, q;
int l[1000001], head[1000001], h[1000001], cnt = 1;
int ans, dis[1000001], vis[1000001], tt[1000001];
string no_answer = "wtnap wa kotori no oyatsu desu!";
struct node
{
    int next, v, w;
} edge[1000001];
void add(int from, int to, int w)
{
    edge[cnt].w = w;
    edge[cnt].v = to;
    edge[cnt].next = head[from];
    head[from] = cnt;
    cnt++;
}
bool spfa()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = inf;
        vis[i] = 0;
    }
    q.push(s);
    vis[s] = 1;
    dis[s] = 0;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        vis[now] = 0;
        for (int i = head[now]; i; i = edge[i].next)
        {
            int next = edge[i].v;
            if ((dis[next] > dis[now] + edge[i].w && dis[now] + edge[i].w < tt[next] && next != t) ||
                (dis[next] > dis[now] + edge[i].w && next == t))
            {
                dis[next] = dis[now] + edge[i].w;
                if (!vis[next])
                {
                    vis[next] = 1;
                    q.push(next);
                }
            }
        }
    }
    ans = dis[t];
    if (ans == inf)
        return 0;
    else
        return 1;
}
int main()
{
    cin >> n >> m >> s >> t >> g >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i] >> l[i];
    }
    int u, v, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    for (int i = 1; i <= n; i++)
    {
        if (q == 0)
        {
            tt[i] = inf + 1;
            continue;
        }
        tt[i] = int((double)(l[i] - h[i]) / (double)(q));
    }
    if (spfa() && ans <= g)
        cout << ans;
    else
        cout << no_answer;
    return 0;
}
