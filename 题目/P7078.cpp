#include <iostream>

#include <algorithm>
#include <set>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");
#define Pii pair<int, int>
#define id second
#define val first
#define mp make_pair

using namespace std;

const int N = 1e6 + 5;

int T, n, k, x, y, ans;
int a[N];
int eat[N], eaten[N];
bool safe[N];

inline void Solve()
{
    cin >> T;
    for (int faq = 1; faq <= T; ++faq)
    {
        set<Pii> s;
        if (faq == 1)
        {
            cin >> n;
            for (int i = 1; i <= n; ++i)
                cin >> a[i];
        }
        else
        {
            cin >> k;
            for (int i = 1; i <= k; ++i)
                cin >> x >> y, a[x] = y;
        }
        ans = n - 1;
        for (int i = 0; i <= n; ++i)
        {
            eat[i] = eaten[i] = 0;
            safe[i] = 0;
        }
        for (int i = 1; i <= n; ++i)
            s.insert({ a[i], i });
        for (int i = 0; i < n - 1; ++i)
        {
            auto min = s.begin(), 
            	max = prev(s.end());
            eaten[i] = min->id;
            eat[i] = max->id;
            s.erase(max), s.erase(min);
            s.insert({ max->val - min->val, max->id });
        }
        for (int i = n - 2; i >= 0; --i)
        {
            if (safe[eat[i]])
            {
                for (int j = i + 1; j < ans; j++)
                    safe[eaten[j]] = 0;
                ans = i;
            }
            else
                safe[eaten[i]] = 1;
        }
        cout << n - ans << endl;
    }
}

int main()
{
    Solve();
}