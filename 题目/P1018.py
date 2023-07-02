# Problem:      P1018 [NOIP2000 提高组] 乘积最大
# Contest:      Luogu
# URL:          https://www.luogu.com.cn/problem/P1018
# Memory Limit: 128 MB
# Time Limit:   1000 ms
# Created Time: 2023-05-05 20:32:59 

n, m = [int(i) for i in input().split()]
a = [int(i) for i in input()]
a.insert(0, 0)


dp = []
for i in range(n + 1):
	dp.append([0] * (m + 1))

def num(x, y):
	res = 0
	for i in range(x, y + 1):
		res = res * 10 + a[i];
	return res

for i in range(1, n + 1):
	dp[i][0] = num(1, i)
for i in range(2, n + 1):
	for j in range(1, min(m + 1, i)):
		for l in range(j, i):
			dp[i][j] = max(dp[i][j], dp[l][j - 1] * num(l + 1, i));
print(dp[n][m])

# print(dp)	