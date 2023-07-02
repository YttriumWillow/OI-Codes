#include <iostream>

#define i64 long long
#define reg register
#define endl '\n'
#define pb push_back
#define qwq puts("fzy qwq ~");

using namespace std;

const int N = 5e5 + 5;

int T, n, a[N];
int l1, l2, r1;
int p1[N], p2[N];

inline bool faq(int x)
{
    int pre = p2[l2];
    for (int i = l2 - 1; i >= 1;)
    {
        if (pre - p2[i] == x)
            pre = p2[i], i--;
        else if (pre - p1[r1] == x)
            pre = p1[r1], r1--;
        else
            return 0;
    }
    return 1;
}

inline bool fk(int st, int x)
{
    l1 = l2 = 0;
    for (reg int i = 1; i <= st - 1; ++i)
        p2[++l2] = a[i];
    int now = a[st];

    for (reg int i = st; i <= n; ++i)
    {
        if (a[i] == now) p1[++l1] = a[i], now += x;
        else p2[++l2] = a[i];
    }

    if (l2 == 0)
        return cout << "Yes" << endl, 1;
    if (l2 == 1)
        return cout << "Yes" << endl, 1;

    r1 = l1;
    if (faq(p2[l2] - p2[l2 - 1]))
        return cout << "Yes" << endl, 1;

    r1 = l1;
    if (faq(p2[l2] - p1[l1]))
        return cout << "Yes" << endl, 1;

    return 0;
}

int main()
{

    cin >> T;
    while (T--)
    {
		cin >> n;
		for (reg int i = 1; i <= n; ++i)
			cin >> a[i];
		if (!fk(1, a[2] - a[1]) && !fk(1, a[3] - a[1]) && !fk(2, a[3] - a[2]))
			cout << "No" << endl;
    }

    return 0;
}
