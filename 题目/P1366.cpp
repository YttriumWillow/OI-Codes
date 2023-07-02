// Problem:      P1366 有序表的合并
// Contest:      Luogu
// URL:          https://www.luogu.com.cn/problem/P1366
// Memory Limit: 128 MB
// Time Limit:   1400 ms
// Created Time: 2023-02-26 20:18:28

#include <iostream>
#include <chrono>
#include <random>

// #include <map>
#include <unordered_map>

#define i64 long long
#define u64 unsigned i64
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
    	// chrono::steady_clock::now().time_since_epoch().count()
    	// ((uint64_t)random_device{}() << 32) | random_device{}()
        static const uint64_t FIXED_RANDOM = ((uint64_t)random_device{}() << 32) | random_device{}();
        return splitmix64(x + FIXED_RANDOM);
    }
};

u64 n, m, T, x;
u64 a[10000010], ans;

unordered_map<u64, u64> mp;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	while (T--)
	{
		mp.clear();
		cin >> n >> m;
		for (reg int i = 1; i <= n; ++i)
			cin >> a[i];
		for (reg int i = 1; i <= m; ++i)
			cin >> x, ++mp[x];
		ans = 0;
		for (reg int i = 1; i <= n; ++i)
			ans ^= mp[a[i]];
		cout << ans << endl;
	}
	return 0;
}