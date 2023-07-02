#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 1e5 + 5, maxq = 1e5 + 5;

struct Query
{
    int l, r, id;
    Query()
    {
    }
    Query(int l, int r, int id) : l(l), r(r), id(id)
    {
    }
} query[maxq];

vector<int> vec[maxn];

int n, q, ans[maxq];
int tr[maxn];
int a[maxn], pre[maxn], id[maxn], len;

int lowbit(int x)
{
    return x & -x;
}

void update(int x, int v)
{
    for (int i = x; i <= len; i += lowbit(i))
    {
        tr[i] += v;
    }
}

int query(int x)
{
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        res += tr[i];
    }
    return res;
}

void cdq(int l, int r)
{
    if (l == r)
        return;
    int mid = l + r >> 1;
    cdq(l, mid), cdq(mid + 1, r);
    int i = l, j = mid + 1;
    memset(tr, 0, sizeof tr);
    while (j <= r)
    {
        while (i <= mid && query(a[i]) <= mid - i)
            update(a[i], 1), i++;
        ans[query[j].id] += query(a[j]) - query(a[query[j].l] - 1);
        j++;
    }
    while (i < j)
    {
        update(a[i], -1), i++;
    }
    // 下面进行归并排序，这里就不再赘述了。
    i = l, j = mid + 1;
    vector<int> tmp;
    while (i <= mid && j <= r)
    {
        if (a[i] < a[j])
        {
            tmp.push_back(a[i++]);
        }
        else
        {
            tmp.push_back(a[j++]);
        }
    }
    while (i <= mid)
        tmp.push_back(a[i++]);
    while (j <= r)
        tmp.push_back(a[j++]);
    for (int i = l, j = 0; i <= r; i++, j++)
    {
        a[i] = tmp[j];
    }
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        vec[a[i]].push_back(i);
    }
    memcpy(pre, a, sizeof pre);
    sort(pre + 1, pre + 1 + n);
    len = unique(pre + 1, pre + 1 + n) - pre - 1;
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(pre + 1, pre + 1 + len, a[i]) - pre;
    }
    for (int i = 0; i < q; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        query[i] = Query(l, r, i);
    }
    sort(query, query + q, [](const Query &q1, const Query &q2) { return q1.r < q2.r; });
    int ptr = 1;
    for (int i = 0; i < q; i++)
    {
        while (ptr <= query[i].r)
        {
            for (int p : vec[ptr])
            {
                int pos = upper_bound(vec[a[p] - 1].begin(), vec[a[p] - 1].end(), p) - vec[a[p] - 1].begin() - 1;
                update(pos + 1, 1);
            }
            ptr++;
        }
        ans[query[i].id] = query(query[i].r) - query(query[i].l - 1);
    }
    memset(tr, 0, sizeof tr);
    for (int i = 1; i <= len; i++)
    {
        a[i] = pre[i];
        for (int p : vec[a[i]])
        {
            id[p] = i;
        }
    }
    cdq(1, len);
    for (int i = 0; i < q; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}