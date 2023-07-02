#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
struct Node {
    int l, r;
    int val;  // 节点值
    int size; // 子树大小
    int cnt;  // 节点出现次数
    int rnd;  // 随机值
    bool rev; // 翻转标记
} tr[MAXN];
int root, idx, n, m;
inline int new_node(int val) {
    tr[++idx].val = val;
    tr[idx].size = tr[idx].cnt = 1;
    tr[idx].rnd = rand();
    return idx;
}
inline void pushup(int p) {
    tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + tr[p].cnt;
}
inline void pushrev(int p) {
    swap(tr[p].l, tr[p].r);
    tr[p].rev ^= 1;
}
inline void pushdown(int p) {
    if (tr[p].rev) {
        pushrev(tr[p].l);
        pushrev(tr[p].r);
        tr[p].rev = false;
    }
}
void split(int p, int v, int& x, int& y) {
    if (!p) x = y = 0;
    else {
        pushdown(p);
        if (tr[p].val <= v) {
            x = p;
            split(tr[p].r, v, tr[p].r, y);
        } else {
            y = p;
            split(tr[p].l, v, x, tr[p].l);
        }
        pushup(p);
    }
}
int merge(int x, int y) {
    if (!x || !y) return x + y;
    if (tr[x].rnd < tr[y].rnd) {
        pushdown(x);
        tr[x].r = merge(tr[x].r, y);
        pushup(x);
        return x;
    } else {
        pushdown(y);
        tr[y].l = merge(x, tr[y].l);
        pushup(y);
        return y;
    }
}
void insert(int val) {
    int x, y;
    split(root, val, x, y);
    if (x && tr[x].val == val) tr[x].cnt++, tr[x].size++;
    else x = new_node(val);
    root = merge(merge(x, y), tr[root].l);
}
void remove(int val) {
    int x, y, z;
    split(root, val, x, z);
    split(x, val - 1, x, y);
    if (y && y->cnt > 1) y->cnt--, y->size--;
    else y = 0;
    root = merge(merge(x, y), z);
}
int kth(int p, int k) {
    pushdown(p);
    if (tr[tr[p].l].size >= k) return kth(tr[p].l, k);
    if (tr[tr[p].l].size + tr[p].cnt >= k) return tr[p].val;
    return kth(tr[p].r, k - tr[tr[p].l].size - tr[p].cnt);
}
int get_rank(int val) {
    int x, y;
    split(root, val - 1, x, y);
    int res = tr[x].size;
    root = merge(x, y);
    return res;
}
int get_pre(int val) {
    int x, y;
    split(root, val - 1, x, y);
    int p = x;
    while (tr[p].r) p = tr[p].r;
    int res = tr[p].val;
    root = merge(x, y);
    return res;
}
int get_suc(int val) {
    int x, y;
    split(root, val, x, y);
    int p = y;
    while (tr[p].l) p = tr[p].l;
    int res = tr[p].val;
    root = merge(x, y);
    return res;
}
void reverse(int l, int r) {
    int x, y, z;
    split(root, r, x, z);
    split(x, l - 1, x, y);
    tr[y].rev ^= 1;
    root = merge(merge(x, y), z);
}
void inorder(int p) {
    pushdown(p);
    if (tr[p].l) inorder(tr[p].l);
    cout << tr[p].val << " ";
    if (tr[p].r) inorder(tr[p].r);
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) insert(i);
    while (m--) {
        int l, r;
        cin >> l >> r;
        reverse(l, r);
    }
    for (int i = 1; i <= n; i++) cout << kth(root, i) << " ";
    return 0;
}