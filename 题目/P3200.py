# // Problem:      P3200 [HNOI2009]有趣的数列
# // Contest:      Luogu
# // URL:          https://www.luogu.com.cn/problem/P3200
# // Memory Limit: 125 MB
# // Time Limit:   1000 ms
# // Created Time: 2023-05-11 18:51:26 

n, p = [int(i) for i in input().split()]

# cat = [1]
# i = 1
# while (i <= n):
	# cat.append( cat[i - 1] * (4 * i - 2) // (i + 1) )
	# i += 1
# 
# print(cat[-1] % p)

# (2n)! / (n!)^2

fac = [1]

i = 1
lmt = 2 * n
while (i <= lmt):
	fac.append(fac[i - 1] * i)
	i += 1

u = fac[2 * n] // fac[n] // fac[n]
ans = u // (n + 1)

print(ans % p)