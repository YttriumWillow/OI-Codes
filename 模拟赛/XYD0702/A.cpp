#pragma GCC optimize(2)

#include <iostream>

#include <queue>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 55;
const int inf = 0x7ffffff;

#define check(i, j) (!vis[i][j] && i >= 1 && j >= 1 && i <= n && j <= n && !a[i][j])

char ch;
int n, m, colcnt, ans = inf;
int sx, sy, ex, ey;
int a[N][N];
int col[N][N];
bool vis[N][N];

struct Node { int x, y; };
int dx[] = { -1,  0, 1, 0 };
int dy[] = {  0, -1, 0, 1 };

inline void bfs(int x, int y, int blk)
{
	queue<Node> q; q.push({ x, y });\
	while (!q.empty())
	{
		Node u = q.front(); q.pop();
		vis[u.x][u.y] = 1;
		col[u.x][u.y] = blk;
		for (int i = 0; i < 4; ++i)
			if (check(u.x + dx[i], u.y + dy[i]))
				q.push({ u.x + dx[i], u.y + dy[i] });
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	cin >> sx >> sy;
	cin >> ex >> ey;
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> ch, a[i][j] = ch - '0';
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (!vis[i][j] && !a[i][j])
				bfs(i, j, ++colcnt);
				
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int x = 1; x <= n; ++x)
				for (int y = 1; y <= n; ++y)
					if (col[i][j] == col[sx][sy] && col[x][y] == col[ex][ey])
						ans = min(ans, (i - x) * (i - x) + (j - y) * (j - y));
	
	cout << ans << endl;
	return 0;
}