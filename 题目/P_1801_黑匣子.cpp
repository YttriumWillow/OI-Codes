#include <iostream>
#include <queue>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");
#define pqueue priority_queue

using namespace std;

int a[200005];
int n, m, now = 1, q;

pqueue< int, vector<int>, less<int> >    bigtop;
pqueue< int, vector<int>, greater<int> > smalltop;

inline void add(int x, int k)
{
    bigtop.push(x);
    while ((int)bigtop.size() >= k)
        smalltop.push(bigtop.top()), bigtop.pop();
}

inline int query(int k)
{
    int res = smalltop.top();
    bigtop.push(smalltop.top()); smalltop.pop();
    return res;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &q);
        for (reg int j = now; j <= q; ++j)
            add(a[j], i);
        now = q + 1;
        printf("%d\n", query(i));
    }
    return 0;
}
