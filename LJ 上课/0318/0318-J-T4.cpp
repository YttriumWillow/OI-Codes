#include <iostream>

#include <queue>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

struct Node
{
    int x, y, k;
};

int sx, sy, xx, yy, tx, ty;
char maze[210][210];
bool key[11];
int vis[210][210];
int dx = {-1, 0, 0, 1};
int dy = {0, -1, 1, 0};
char dc = {'L', 'U', 'D', 'R'};

queue<Node> q;

bool check(int x, int y)
{
	return (vis[x][y] < 4 && x)
}

void bfs()
{
    q.push(Node{sx, sy, 0, '?'});
    while (!q.empty())
    {
        Node now = q.front(); q.pop();
        for (reg int i = 0; i < 4; ++i)
        {
            xx = now.x + dx[i];
            yy = now.y + dy[i];
            kk = now.k;
            if ('a' <= maze[xx][yy] && maze[xx][yy] <= 'h')
            	
            if (xx == tx && yy == ty)
            	ans = min(ans, now.k);
            if (check(xx, yy))
            {
            	q.push(Node{xx, yy, , dc[i]})
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (reg int i = 1; i <= n; ++i)
        maze[i][0] = maze[i][m + 1] = 'X';
    for (reg int i = 1; i <= m; ++i)
        maze[0][i] = maze[n + 1][i] = 'X';
    for (reg int i = 1; i <= n; ++i)
        for (reg int j = 1; j <= n; ++j)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'S')
                sx = i, sy = j;
            if (maza[i][j] == 'T')
                tx = i, ty = j;
        }
    bfs();
    return 0;
}