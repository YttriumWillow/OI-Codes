#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define i64 long long
#define endl '\n'
#define queryrnk order_of_key
#define Pii pair<int, int>
#define qwq puts("fzy qwq ~");

using namespace std;
using namespace __gnu_pbds;

const int N = 2e5 + 10;
const int inf = 0x7fffffff;

int n, q, x, y, a[N];
char opt;
tree<Pii, null_type, less<Pii>, rb_tree_tag, 
	tree_order_statistics_node_update> t;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        t.insert({ a[i], i });
    }
    for (int i = 1; i <= q; ++i)
    {
        cin >> opt;
        if (opt == '!')
        {
            cin >> x >> y;
            t.erase({ a[x], x });
            t.insert({ a[x] = y, x });
        }
        else
        {
            cin >> x >> y;
            cout << t.queryrnk({ y, inf })
            	- t.queryrnk({ x - 1, inf }) << ' ';
        }
    }
}