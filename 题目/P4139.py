# Problem:      P4139 上帝与集合的正确用法
# Contest:      Luogu
# URL:          https://www.luogu.com.cn/problem/P4139
# Memory Limit: 125 MB
# Time Limit:   1000 ms
# Created Time: 2023-07-02 19:06:55 

n = 100010
a = [1]
res = [0] * 10000001

for i in range(1, n):
	a.append(2 ** a[i - 1])
	for mod in range(3, 10000000 + 1):
		if (a[i] % mod == a[i - 1] % mod):
			try:
				res[mod] = { a[i] % mod }
			except:
				pass

print(a)