#include <iostream>
using namespace std;
const int N = 1e5 + 10;
struct Node {
    int l, r;
    bool rev;
    int val, sum, size;
    Node* ch[2];
    Node(int l, int r): l(l), r(r), rev(false), val(0), sum(0), size(0), ch({nullptr, nullptr}) {}
};
Node* root;
void pushup(Node* u) {
    u->size = 1 + (u->ch[0] ? u->ch[0]->size : 0) + (u->ch[1] ? u->ch[1]->size : 0);
    u->sum = u->val + (u->ch[0] ? u->ch[0]->sum : 0) + (u->ch[1] ? u->ch[1]->sum : 0);
}
void pushdown(Node* u) {
    if (u->rev) {
        swap(u->ch[0], u->ch[1]);
        if (u->ch[0]) u->ch[0]->rev ^= true;
        if (u->ch[1]) u->ch[1]->rev ^= true;
        u->rev = false;
    }
}
Node* merge(Node* u, Node* v) {
    if (!u || !v) return u ? u : v;
    pushdown(u), pushdown(v);
    if (u->val > v->val) {
        u->ch[1] = merge(u->ch[1], v);
        pushup(u);
        return u;
    } else {
        v->ch[0] = merge(u, v->ch[0]);
        pushup(v);
        return v;
    }
}
void split(Node* u, int k, Node* &x, Node* &y) {
    if (!u) x = y = nullptr;
    else {
        pushdown(u);
        if (u->ch[0] && u->ch[0]->size >= k) {
            y = u;
            split(u->ch[0], k, x, y->ch[0]);
            pushup(y);
        } else {
            x = u;
            split(u->ch[1], k - (u->ch[0] ? u->ch[0]->size + 1 : 0), x->ch[1], y);
            pushup(x);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) root = merge(root, new Node(i, i));
    while (m--) {
        int l, r;
        cin >> l >> r;
        Node *x, *y, *z;
        split(root, l - 1, x, y);
        split(y, r - l + 1, y, z);
        y->rev ^= true;
        root = merge(x, merge(y, z));
    }
    for (int i = 1; i <= n; i++) {
        Node* u;
        split(root, i, root, u);
        cout << root->val << ' ';
        root = merge(root, u);
    }
    cout << endl;
    return 0;
}