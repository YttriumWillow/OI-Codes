// Problem:      P2894 [USACO08FEB] Hotel G
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P2894
// Memory Limit: 128 MB
// Time Limit:   1000 ms
// Created Time: 2023-06-28 20:28:02 

#include <iostream>

#include <set>
#include <vector>
#include <algorithm>

#define i64 long long
#define endl '\n'
#define qwq puts("fzy qwq ~");

using namespace std;

struct ChthollyTree
{
    struct Node
    {
        int l, r; mutable int v;
        Node(int l, int r = 0, int v = 0): l(l), r(r), v(v) {}
        inline friend operator < (const Node& _x, const Node& _y)
        	{ return _x.l < _y.l; }
    }; set<Node> s;
    inline void init(int n, int r) { s.insert(Node(1, n, r)); }
    
    auto split(int pos)
    {
        auto it = s.lower_bound(Node(pos));
        if (it != s.end() && it -> l == pos)
            return it;
        --it;
        if (it -> r < pos) return s.end();
        int l = it -> l, r = it -> r, v = it -> v;
        s.erase(it); s.insert(Node(l, pos - 1, v));
        return s.insert(Node(pos, r, v)).first;
    }
    
    inline void add(int l, int r, int x)
    {
        auto itr = split(r + 1), itl = split(l);
        for (auto it = itl; it != itr; ++it)
            it -> v += x;
    }
    inline void assign(int l, int r, int x)
    {
        auto itr = split(r + 1), itl = split(l);
        s.erase(itl, itr);
        s.insert(Node(l, r, x));
    }
    
    inline int checkin(int x)
    {
    	for (auto it = s.begin(); it != s.end(); ++it)
    		if (it -> v >= x)
    		{
    			int res = it -> l;
    			auto itr = split(it -> l + x), itl = split(it -> l);
    			s.erase(itl, itr); s.insert(Node(l, r, 1));
    			return res;
    		}
    	return 0;
    }
    
    inline void checkout(int x, int y)
    {
    	
    }
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> opt >> x;
		if (opt == 1)
			cout << checkin(x) << endl;
		if (opt == 2)
		{
			cin >> y;
		}
	}
	return 0;
}