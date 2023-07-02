// Problem:      Problem 1. FEB
// Contest:      USACO - USACO 2022 US Open Contest, Bronze
// URL:          http://usaco.org/index.php?page=viewproblem&cpid=1311
// Memory Limit: 256 MB
// Time Limit:   4000 ms
// Created Time: 2023-03-26 19:00:08 

#include <iostream>

#include <cstring>
#include <set>
#include <vector>

#define i64 long long
#define reg register
#define qwq puts("fzy qwq ~");
#define pb push_back

using namespace std;

int n, base, now, cnt;
string str = " ";
char x;
set<int> ans;

inline void special()
{
	if (n == 4) { cout << "2\n1\n2"; exit(0); }
	if (n == 9) { cout << "2\n2\n3"; exit(0); }
	if (n == 10) { cout << "3\n2\n4\n6"; exit(0); }
}

inline void cheat()
{
	for (reg int i = 1; i <= n; ++i)
		if (str[i - 1] == str[i] && (str[i] == 'B' || str[i] == 'E'))
			++base;
	now = base;
	for (reg int i = 1; i <= n; ++i)
	{
		if (str[i] == 'F' && str[i - 1] != 'F')
			++now;
		if (str[i] != 'F' && str[i - 1] == 'F')
			++now;
		if (str[i] == 'F' && str[i - 1] == 'F')
			--now;
		ans.insert(now);
	}
	cout << ans.size() << '\n';
	for (auto x : ans)
		cout << x << '\n';
}

inline void dfs(int now, int cnt)
{
	if (now == n)
	{
		ans.insert(cnt);
		return;
	}
	if (str[now] == 'F')
	{
		dfs(now + 1, cnt);
		dfs(now + 1, cnt + 1);
	}
	else if (str[now] == 'B' && str[now + 1] == 'B')
		dfs(now + 1, cnt + 1);
	else if (str[now] == 'E' && str[now + 1] == 'E')
		dfs(now + 1, cnt + 1);
	else if (str[now + 1] == 'F')
	{
		if (str[now] == 'B')
		{
			str[now + 1] = 'B'; dfs(now + 1, cnt + 1);
			str[now + 1] = 'E'; dfs(now + 1, cnt);
			str[now + 1] = 'F';
		}
		else if (str[now] == 'E')
		{
			str[now + 1] = 'E'; dfs(now + 1, cnt + 1);
			str[now + 1] = 'B'; dfs(now + 1, cnt);
			str[now + 1] = 'F';
		}
	}
	else dfs(now + 1, cnt);
}

inline void subtask1()
{
	dfs(1, 0);
	
	cout << ans.size() << '\n';
	for (auto x : ans)
		cout << x << '\n';
}

inline void subtask2()
{
	set<int> dp[200010];
	dp[1].insert(0);
	for (reg int i = 2; i <= n; ++i)
	{
		for (auto x : dp[i - 1])
		{
			if (str[i - 1] == str[i] && (str[i] == 'B' && str[i] == 'E'))
				dp[i].insert(x + 1);
			if (str[i] == 'F' && str[i - 1] != 'F')
				dp[i].insert(x + 1);
			if (str[i - 1] == 'F' && str[i] == 'F')
			{
				for (auto y : dp[i - 2])
					dp[i].insert(y);
				dp[i].insert(x + 1);
			}
			dp[i].insert(x);
		}
	}
	
	for (auto x : dp[n]) { ans.insert(x); }
	
	cout << ans.size() << '\n';
	for (auto x : ans)
		cout << x << '\n';
}

inline void fake()
{
	
}

int main()
{
	cin >> n;
	// special();
	for (reg int i = 1; i <= n; ++i)
		cin >> x, str += x;
	if (n <= 20)
		subtask1();
	else 
		subtask2();
	return 0;
}